'use strict';
const { GObject, Clutter, Animation } = imports.gi;
const ExtensionUtils = imports.misc.extensionUtils;
const Extension = ExtensionUtils.getCurrentExtension();
const Settings = Extension.imports.settings;
const Me = ExtensionUtils.getCurrentExtension();
const Utils = Me.imports.commonUtils;
const MonitorUtils = Me.imports.monitorUtils;

const CLUTTER_TIMELINE_DURATION = 1000 * 1000;

var WobblyEffect = GObject.registerClass({},
    class WobblyEffect extends Clutter.DeformEffect {

        _init(params = {}) {
            super._init();
            this.operationType = params.op;

            this.allocationChangedEvent = null;
            this.paintEvent = null;
            this.newFrameEvent = null;
            this.resizeEvent = null;
            
            this.timerId = null;
            this.initOldValues = true;
            this.width = 0;
            this.height = 0;
            this.xMouse = 0;
            this.yMouse = 0;
            this.margin = 3;
            this.msecOld = 0;

            this.wobblyModel = null;
            this.anchor = null;
            
            this.monitorConfiguration = new MonitorUtils.MonitorConfiguration();
            this.scale = 1;
            this.monitorsWithSameScale = false;
            
            this.position = new Animation.Vector();
            this.size = new Animation.Vector();
            this.anchorPosition = new Animation.Vector();
            this.delta = new Animation.Vector();
            this.reverseDelta = new Animation.Vector();

            let prefs = (new Settings.Prefs());
            this.FRICTION = prefs.FRICTION.get();
            this.SPRING_K = prefs.SPRING_K.get();            
            
            this.SPEEDUP_FACTOR = prefs.SPEEDUP_FACTOR.get();
            this.OBJECT_MOVEMENT_RANGE = prefs.OBJECT_MOVEMENT_RANGE.get();
            this.X_TILES = prefs.X_TILES.get();
            this.Y_TILES = prefs.Y_TILES.get();

            this.set_n_tiles(this.X_TILES, this.Y_TILES);
            
            this.initialized = false;
        }

        vfunc_set_actor(actor) {
            super.vfunc_set_actor(actor);

            if (actor && !this.initialized) {
                this.initialized = true;

                this.monitorsWithSameScale = this.monitorConfiguration.monitorsWithSameScale();
                this.scale = this.monitorConfiguration.getScale(actor);

                [this.width, this.height] = actor.get_size();
                [this.size.x, this.size.y] = [this.width + this.margin, this.height + this.margin];
                [this.xNew, this.yNew] = [actor.get_x(), actor.get_y()];
                [this.xOld, this.yOld] = [this.xNew, this.yNew];
                [this.xMouse, this.yMouse] = global.get_pointer();

                [this.position.x, this.position.y] = [0.0, 0.0];
                this.wobblyModel = new Animation.WobblyModel({
                    friction: this.FRICTION, 
                    spring_k: this.SPRING_K,
                    movement_range: this.OBJECT_MOVEMENT_RANGE,
                    position: this.position, 
                    size: this.size
                });

                [this.anchorPosition.x, this.anchorPosition.y] = [this.xMouse - this.xNew, this.yMouse - this.yNew];
                this.anchor = this.wobblyModel.grab_anchor(this.anchorPosition);

                this.allocationChangedEvent = actor.connect(Utils.is_old_shell_versions() ? 'allocation-changed' : 'notify::allocation', this.on_actor_event.bind(this));
                this.paintEvent = actor.connect('paint', () => {});
                this.resizeEvent = actor.connect('notify::size', this.resized.bind(this));
                this.start_timer(this.on_tick_elapsed.bind(this), actor);
            }
        }

        start_timer(timerFunction, actor) {
            this.stop_timer();
            if (Utils.is_old_shell_versions()) {
                this.timerId = new Clutter.Timeline();
            } else {
                this.timerId = new Clutter.Timeline({ actor: actor });
            }

            this.timerId.set_duration(CLUTTER_TIMELINE_DURATION);

            this.newFrameEvent = this.timerId.connect('new-frame', timerFunction);
            this.timerId.start();      
        }

        stop_timer() {
            if (this.timerId) {
                if (this.newFrameEvent) {
                    this.timerId.disconnect(this.newFrameEvent);
                    this.newFrameEvent = null;
                }
                this.timerId.run_dispose();
                this.timerId = null;
            }
        }

        resized(actor, params) {
            if (!this.monitorsWithSameScale) {
                this.scale = this.monitorConfiguration.getScale(actor);
            }

            [this.width, this.height] = actor.get_size();
            [this.size.x, this.size.y] = [this.width + this.margin, this.height + this.margin];
            this.wobblyModel.resize(this.size);
        }

        destroy() {
            this.stop_timer();

            if (this.anchor) {
                this.anchor.release();
                this.anchor = null;
            }

            if (this.wobblyModel) {
                this.wobblyModel = null;
            }
            
            let actor = this.get_actor();
            if (actor) {
                if (this.paintEvent) {
                    actor.disconnect(this.paintEvent);
                    this.paintEvent = null;
                }
            
                if (this.allocationChangedEvent) {
                    actor.disconnect(this.allocationChangedEvent);
                    this.allocationChangedEvent = null;
                }

                if (this.resizeEvent) {
                    actor.disconnect(this.resizeEvent);
                    this.resizeEvent = null;
                }

                actor.remove_effect(this);
            }
        }

        on_actor_event(actor, allocation, flags) {
            if (!this.monitorsWithSameScale) {
                this.scale = this.monitorConfiguration.getScale(actor);
            }
            
            [this.xOld, this.yOld, this.xNew, this.yNew] = [this.xNew, this.yNew, actor.get_x(), actor.get_y()];
            
            [this.delta.x, this.delta.y] = [this.xNew - this.xOld, this.yNew - this.yOld];
            this.anchor.move_by(this.delta);

            [this.reverseDelta.x, this.reverseDelta.y] = [this.delta.x * -1, this.delta.y * -1];
            this.wobblyModel.move_by(this.reverseDelta);
        }

        on_tick_elapsed(timer, msec) {
            this.wobblyModel.step(1 + (msec - this.msecOld) / this.SPEEDUP_FACTOR);
            this.msecOld = msec;
            this.invalidate();
        }
        
        vfunc_deform_vertex(w, h, v) {
            [v.x, v.y] = this.wobblyModel.deform_texcoords_plain(v.ty, v.tx).map(el => el * this.scale);
        }
    }
);