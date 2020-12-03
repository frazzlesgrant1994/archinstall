/*
 * This file is generated by gdbus-codegen, do not modify it.
 *
 * The license of this code is the same as for the D-Bus interface description
 * it was derived from. Note that it links to GLib, so must comply with the
 * LGPL linking clauses.
 */

#ifndef __TERMINAL_GDBUS_GENERATED_H__
#define __TERMINAL_GDBUS_GENERATED_H__

#include <gio/gio.h>

G_BEGIN_DECLS


/* ------------------------------------------------------------------------ */
/* Declarations for org.gnome.Terminal.Factory0 */

#define TERMINAL_TYPE_FACTORY (terminal_factory_get_type ())
#define TERMINAL_FACTORY(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), TERMINAL_TYPE_FACTORY, TerminalFactory))
#define TERMINAL_IS_FACTORY(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), TERMINAL_TYPE_FACTORY))
#define TERMINAL_FACTORY_GET_IFACE(o) (G_TYPE_INSTANCE_GET_INTERFACE ((o), TERMINAL_TYPE_FACTORY, TerminalFactoryIface))

struct _TerminalFactory;
typedef struct _TerminalFactory TerminalFactory;
typedef struct _TerminalFactoryIface TerminalFactoryIface;

struct _TerminalFactoryIface
{
  GTypeInterface parent_iface;

  gboolean (*handle_create_instance) (
    TerminalFactory *object,
    GDBusMethodInvocation *invocation,
    GVariant *arg_options);

};

GType terminal_factory_get_type (void) G_GNUC_CONST;

GDBusInterfaceInfo *terminal_factory_interface_info (void);
guint terminal_factory_override_properties (GObjectClass *klass, guint property_id_begin);


/* D-Bus method call completion functions: */
void terminal_factory_complete_create_instance (
    TerminalFactory *object,
    GDBusMethodInvocation *invocation,
    const gchar *receiver);



/* D-Bus method calls: */
void terminal_factory_call_create_instance (
    TerminalFactory *proxy,
    GVariant *arg_options,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean terminal_factory_call_create_instance_finish (
    TerminalFactory *proxy,
    gchar **out_receiver,
    GAsyncResult *res,
    GError **error);

gboolean terminal_factory_call_create_instance_sync (
    TerminalFactory *proxy,
    GVariant *arg_options,
    gchar **out_receiver,
    GCancellable *cancellable,
    GError **error);



/* ---- */

#define TERMINAL_TYPE_FACTORY_PROXY (terminal_factory_proxy_get_type ())
#define TERMINAL_FACTORY_PROXY(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), TERMINAL_TYPE_FACTORY_PROXY, TerminalFactoryProxy))
#define TERMINAL_FACTORY_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), TERMINAL_TYPE_FACTORY_PROXY, TerminalFactoryProxyClass))
#define TERMINAL_FACTORY_PROXY_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), TERMINAL_TYPE_FACTORY_PROXY, TerminalFactoryProxyClass))
#define TERMINAL_IS_FACTORY_PROXY(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), TERMINAL_TYPE_FACTORY_PROXY))
#define TERMINAL_IS_FACTORY_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), TERMINAL_TYPE_FACTORY_PROXY))

typedef struct _TerminalFactoryProxy TerminalFactoryProxy;
typedef struct _TerminalFactoryProxyClass TerminalFactoryProxyClass;
typedef struct _TerminalFactoryProxyPrivate TerminalFactoryProxyPrivate;

struct _TerminalFactoryProxy
{
  /*< private >*/
  GDBusProxy parent_instance;
  TerminalFactoryProxyPrivate *priv;
};

struct _TerminalFactoryProxyClass
{
  GDBusProxyClass parent_class;
};

GType terminal_factory_proxy_get_type (void) G_GNUC_CONST;

#if GLIB_CHECK_VERSION(2, 44, 0)
G_DEFINE_AUTOPTR_CLEANUP_FUNC (TerminalFactoryProxy, g_object_unref)
#endif

void terminal_factory_proxy_new (
    GDBusConnection     *connection,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GAsyncReadyCallback  callback,
    gpointer             user_data);
TerminalFactory *terminal_factory_proxy_new_finish (
    GAsyncResult        *res,
    GError             **error);
TerminalFactory *terminal_factory_proxy_new_sync (
    GDBusConnection     *connection,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GError             **error);

void terminal_factory_proxy_new_for_bus (
    GBusType             bus_type,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GAsyncReadyCallback  callback,
    gpointer             user_data);
TerminalFactory *terminal_factory_proxy_new_for_bus_finish (
    GAsyncResult        *res,
    GError             **error);
TerminalFactory *terminal_factory_proxy_new_for_bus_sync (
    GBusType             bus_type,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GError             **error);


/* ---- */

#define TERMINAL_TYPE_FACTORY_SKELETON (terminal_factory_skeleton_get_type ())
#define TERMINAL_FACTORY_SKELETON(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), TERMINAL_TYPE_FACTORY_SKELETON, TerminalFactorySkeleton))
#define TERMINAL_FACTORY_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), TERMINAL_TYPE_FACTORY_SKELETON, TerminalFactorySkeletonClass))
#define TERMINAL_FACTORY_SKELETON_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), TERMINAL_TYPE_FACTORY_SKELETON, TerminalFactorySkeletonClass))
#define TERMINAL_IS_FACTORY_SKELETON(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), TERMINAL_TYPE_FACTORY_SKELETON))
#define TERMINAL_IS_FACTORY_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), TERMINAL_TYPE_FACTORY_SKELETON))

typedef struct _TerminalFactorySkeleton TerminalFactorySkeleton;
typedef struct _TerminalFactorySkeletonClass TerminalFactorySkeletonClass;
typedef struct _TerminalFactorySkeletonPrivate TerminalFactorySkeletonPrivate;

struct _TerminalFactorySkeleton
{
  /*< private >*/
  GDBusInterfaceSkeleton parent_instance;
  TerminalFactorySkeletonPrivate *priv;
};

struct _TerminalFactorySkeletonClass
{
  GDBusInterfaceSkeletonClass parent_class;
};

GType terminal_factory_skeleton_get_type (void) G_GNUC_CONST;

#if GLIB_CHECK_VERSION(2, 44, 0)
G_DEFINE_AUTOPTR_CLEANUP_FUNC (TerminalFactorySkeleton, g_object_unref)
#endif

TerminalFactory *terminal_factory_skeleton_new (void);


/* ------------------------------------------------------------------------ */
/* Declarations for org.gnome.Terminal.Terminal0 */

#define TERMINAL_TYPE_RECEIVER (terminal_receiver_get_type ())
#define TERMINAL_RECEIVER(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), TERMINAL_TYPE_RECEIVER, TerminalReceiver))
#define TERMINAL_IS_RECEIVER(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), TERMINAL_TYPE_RECEIVER))
#define TERMINAL_RECEIVER_GET_IFACE(o) (G_TYPE_INSTANCE_GET_INTERFACE ((o), TERMINAL_TYPE_RECEIVER, TerminalReceiverIface))

struct _TerminalReceiver;
typedef struct _TerminalReceiver TerminalReceiver;
typedef struct _TerminalReceiverIface TerminalReceiverIface;

struct _TerminalReceiverIface
{
  GTypeInterface parent_iface;


  gboolean (*handle_exec) (
    TerminalReceiver *object,
    GDBusMethodInvocation *invocation,
    GUnixFDList *fd_list,
    GVariant *arg_options,
    GVariant *arg_arguments);

  void (*child_exited) (
    TerminalReceiver *object,
    gint arg_exit_code);

};

GType terminal_receiver_get_type (void) G_GNUC_CONST;

GDBusInterfaceInfo *terminal_receiver_interface_info (void);
guint terminal_receiver_override_properties (GObjectClass *klass, guint property_id_begin);


/* D-Bus method call completion functions: */
void terminal_receiver_complete_exec (
    TerminalReceiver *object,
    GDBusMethodInvocation *invocation,
    GUnixFDList *fd_list);



/* D-Bus signal emissions functions: */
void terminal_receiver_emit_child_exited (
    TerminalReceiver *object,
    gint arg_exit_code);



/* D-Bus method calls: */
void terminal_receiver_call_exec (
    TerminalReceiver *proxy,
    GVariant *arg_options,
    GVariant *arg_arguments,
    GUnixFDList *fd_list,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean terminal_receiver_call_exec_finish (
    TerminalReceiver *proxy,
    GUnixFDList **out_fd_list,
    GAsyncResult *res,
    GError **error);

gboolean terminal_receiver_call_exec_sync (
    TerminalReceiver *proxy,
    GVariant *arg_options,
    GVariant *arg_arguments,
    GUnixFDList  *fd_list,
    GUnixFDList **out_fd_list,
    GCancellable *cancellable,
    GError **error);



/* ---- */

#define TERMINAL_TYPE_RECEIVER_PROXY (terminal_receiver_proxy_get_type ())
#define TERMINAL_RECEIVER_PROXY(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), TERMINAL_TYPE_RECEIVER_PROXY, TerminalReceiverProxy))
#define TERMINAL_RECEIVER_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), TERMINAL_TYPE_RECEIVER_PROXY, TerminalReceiverProxyClass))
#define TERMINAL_RECEIVER_PROXY_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), TERMINAL_TYPE_RECEIVER_PROXY, TerminalReceiverProxyClass))
#define TERMINAL_IS_RECEIVER_PROXY(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), TERMINAL_TYPE_RECEIVER_PROXY))
#define TERMINAL_IS_RECEIVER_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), TERMINAL_TYPE_RECEIVER_PROXY))

typedef struct _TerminalReceiverProxy TerminalReceiverProxy;
typedef struct _TerminalReceiverProxyClass TerminalReceiverProxyClass;
typedef struct _TerminalReceiverProxyPrivate TerminalReceiverProxyPrivate;

struct _TerminalReceiverProxy
{
  /*< private >*/
  GDBusProxy parent_instance;
  TerminalReceiverProxyPrivate *priv;
};

struct _TerminalReceiverProxyClass
{
  GDBusProxyClass parent_class;
};

GType terminal_receiver_proxy_get_type (void) G_GNUC_CONST;

#if GLIB_CHECK_VERSION(2, 44, 0)
G_DEFINE_AUTOPTR_CLEANUP_FUNC (TerminalReceiverProxy, g_object_unref)
#endif

void terminal_receiver_proxy_new (
    GDBusConnection     *connection,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GAsyncReadyCallback  callback,
    gpointer             user_data);
TerminalReceiver *terminal_receiver_proxy_new_finish (
    GAsyncResult        *res,
    GError             **error);
TerminalReceiver *terminal_receiver_proxy_new_sync (
    GDBusConnection     *connection,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GError             **error);

void terminal_receiver_proxy_new_for_bus (
    GBusType             bus_type,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GAsyncReadyCallback  callback,
    gpointer             user_data);
TerminalReceiver *terminal_receiver_proxy_new_for_bus_finish (
    GAsyncResult        *res,
    GError             **error);
TerminalReceiver *terminal_receiver_proxy_new_for_bus_sync (
    GBusType             bus_type,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GError             **error);


/* ---- */

#define TERMINAL_TYPE_RECEIVER_SKELETON (terminal_receiver_skeleton_get_type ())
#define TERMINAL_RECEIVER_SKELETON(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), TERMINAL_TYPE_RECEIVER_SKELETON, TerminalReceiverSkeleton))
#define TERMINAL_RECEIVER_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), TERMINAL_TYPE_RECEIVER_SKELETON, TerminalReceiverSkeletonClass))
#define TERMINAL_RECEIVER_SKELETON_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), TERMINAL_TYPE_RECEIVER_SKELETON, TerminalReceiverSkeletonClass))
#define TERMINAL_IS_RECEIVER_SKELETON(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), TERMINAL_TYPE_RECEIVER_SKELETON))
#define TERMINAL_IS_RECEIVER_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), TERMINAL_TYPE_RECEIVER_SKELETON))

typedef struct _TerminalReceiverSkeleton TerminalReceiverSkeleton;
typedef struct _TerminalReceiverSkeletonClass TerminalReceiverSkeletonClass;
typedef struct _TerminalReceiverSkeletonPrivate TerminalReceiverSkeletonPrivate;

struct _TerminalReceiverSkeleton
{
  /*< private >*/
  GDBusInterfaceSkeleton parent_instance;
  TerminalReceiverSkeletonPrivate *priv;
};

struct _TerminalReceiverSkeletonClass
{
  GDBusInterfaceSkeletonClass parent_class;
};

GType terminal_receiver_skeleton_get_type (void) G_GNUC_CONST;

#if GLIB_CHECK_VERSION(2, 44, 0)
G_DEFINE_AUTOPTR_CLEANUP_FUNC (TerminalReceiverSkeleton, g_object_unref)
#endif

TerminalReceiver *terminal_receiver_skeleton_new (void);


/* ---- */

#define TERMINAL_TYPE_OBJECT (terminal_object_get_type ())
#define TERMINAL_OBJECT(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), TERMINAL_TYPE_OBJECT, TerminalObject))
#define TERMINAL_IS_OBJECT(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), TERMINAL_TYPE_OBJECT))
#define TERMINAL_OBJECT_GET_IFACE(o) (G_TYPE_INSTANCE_GET_INTERFACE ((o), TERMINAL_TYPE_OBJECT, TerminalObject))

struct _TerminalObject;
typedef struct _TerminalObject TerminalObject;
typedef struct _TerminalObjectIface TerminalObjectIface;

struct _TerminalObjectIface
{
  GTypeInterface parent_iface;
};

GType terminal_object_get_type (void) G_GNUC_CONST;

TerminalFactory *terminal_object_get_factory (TerminalObject *object);
TerminalReceiver *terminal_object_get_receiver (TerminalObject *object);
TerminalFactory *terminal_object_peek_factory (TerminalObject *object);
TerminalReceiver *terminal_object_peek_receiver (TerminalObject *object);

#define TERMINAL_TYPE_OBJECT_PROXY (terminal_object_proxy_get_type ())
#define TERMINAL_OBJECT_PROXY(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), TERMINAL_TYPE_OBJECT_PROXY, TerminalObjectProxy))
#define TERMINAL_OBJECT_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), TERMINAL_TYPE_OBJECT_PROXY, TerminalObjectProxyClass))
#define TERMINAL_OBJECT_PROXY_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), TERMINAL_TYPE_OBJECT_PROXY, TerminalObjectProxyClass))
#define TERMINAL_IS_OBJECT_PROXY(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), TERMINAL_TYPE_OBJECT_PROXY))
#define TERMINAL_IS_OBJECT_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), TERMINAL_TYPE_OBJECT_PROXY))

typedef struct _TerminalObjectProxy TerminalObjectProxy;
typedef struct _TerminalObjectProxyClass TerminalObjectProxyClass;
typedef struct _TerminalObjectProxyPrivate TerminalObjectProxyPrivate;

struct _TerminalObjectProxy
{
  /*< private >*/
  GDBusObjectProxy parent_instance;
  TerminalObjectProxyPrivate *priv;
};

struct _TerminalObjectProxyClass
{
  GDBusObjectProxyClass parent_class;
};

GType terminal_object_proxy_get_type (void) G_GNUC_CONST;

#if GLIB_CHECK_VERSION(2, 44, 0)
G_DEFINE_AUTOPTR_CLEANUP_FUNC (TerminalObjectProxy, g_object_unref)
#endif

TerminalObjectProxy *terminal_object_proxy_new (GDBusConnection *connection, const gchar *object_path);

#define TERMINAL_TYPE_OBJECT_SKELETON (terminal_object_skeleton_get_type ())
#define TERMINAL_OBJECT_SKELETON(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), TERMINAL_TYPE_OBJECT_SKELETON, TerminalObjectSkeleton))
#define TERMINAL_OBJECT_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), TERMINAL_TYPE_OBJECT_SKELETON, TerminalObjectSkeletonClass))
#define TERMINAL_OBJECT_SKELETON_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), TERMINAL_TYPE_OBJECT_SKELETON, TerminalObjectSkeletonClass))
#define TERMINAL_IS_OBJECT_SKELETON(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), TERMINAL_TYPE_OBJECT_SKELETON))
#define TERMINAL_IS_OBJECT_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), TERMINAL_TYPE_OBJECT_SKELETON))

typedef struct _TerminalObjectSkeleton TerminalObjectSkeleton;
typedef struct _TerminalObjectSkeletonClass TerminalObjectSkeletonClass;
typedef struct _TerminalObjectSkeletonPrivate TerminalObjectSkeletonPrivate;

struct _TerminalObjectSkeleton
{
  /*< private >*/
  GDBusObjectSkeleton parent_instance;
  TerminalObjectSkeletonPrivate *priv;
};

struct _TerminalObjectSkeletonClass
{
  GDBusObjectSkeletonClass parent_class;
};

GType terminal_object_skeleton_get_type (void) G_GNUC_CONST;

#if GLIB_CHECK_VERSION(2, 44, 0)
G_DEFINE_AUTOPTR_CLEANUP_FUNC (TerminalObjectSkeleton, g_object_unref)
#endif

TerminalObjectSkeleton *terminal_object_skeleton_new (const gchar *object_path);
void terminal_object_skeleton_set_factory (TerminalObjectSkeleton *object, TerminalFactory *interface_);
void terminal_object_skeleton_set_receiver (TerminalObjectSkeleton *object, TerminalReceiver *interface_);

/* ---- */

#define TERMINAL_TYPE_OBJECT_MANAGER_CLIENT (terminal_object_manager_client_get_type ())
#define TERMINAL_OBJECT_MANAGER_CLIENT(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), TERMINAL_TYPE_OBJECT_MANAGER_CLIENT, TerminalObjectManagerClient))
#define TERMINAL_OBJECT_MANAGER_CLIENT_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), TERMINAL_TYPE_OBJECT_MANAGER_CLIENT, TerminalObjectManagerClientClass))
#define TERMINAL_OBJECT_MANAGER_CLIENT_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), TERMINAL_TYPE_OBJECT_MANAGER_CLIENT, TerminalObjectManagerClientClass))
#define TERMINAL_IS_OBJECT_MANAGER_CLIENT(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), TERMINAL_TYPE_OBJECT_MANAGER_CLIENT))
#define TERMINAL_IS_OBJECT_MANAGER_CLIENT_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), TERMINAL_TYPE_OBJECT_MANAGER_CLIENT))

typedef struct _TerminalObjectManagerClient TerminalObjectManagerClient;
typedef struct _TerminalObjectManagerClientClass TerminalObjectManagerClientClass;
typedef struct _TerminalObjectManagerClientPrivate TerminalObjectManagerClientPrivate;

struct _TerminalObjectManagerClient
{
  /*< private >*/
  GDBusObjectManagerClient parent_instance;
  TerminalObjectManagerClientPrivate *priv;
};

struct _TerminalObjectManagerClientClass
{
  GDBusObjectManagerClientClass parent_class;
};

#if GLIB_CHECK_VERSION(2, 44, 0)
G_DEFINE_AUTOPTR_CLEANUP_FUNC (TerminalObjectManagerClient, g_object_unref)
#endif

GType terminal_object_manager_client_get_type (void) G_GNUC_CONST;

GType terminal_object_manager_client_get_proxy_type (GDBusObjectManagerClient *manager, const gchar *object_path, const gchar *interface_name, gpointer user_data);

void terminal_object_manager_client_new (
    GDBusConnection        *connection,
    GDBusObjectManagerClientFlags  flags,
    const gchar            *name,
    const gchar            *object_path,
    GCancellable           *cancellable,
    GAsyncReadyCallback     callback,
    gpointer                user_data);
GDBusObjectManager *terminal_object_manager_client_new_finish (
    GAsyncResult        *res,
    GError             **error);
GDBusObjectManager *terminal_object_manager_client_new_sync (
    GDBusConnection        *connection,
    GDBusObjectManagerClientFlags  flags,
    const gchar            *name,
    const gchar            *object_path,
    GCancellable           *cancellable,
    GError                **error);

void terminal_object_manager_client_new_for_bus (
    GBusType                bus_type,
    GDBusObjectManagerClientFlags  flags,
    const gchar            *name,
    const gchar            *object_path,
    GCancellable           *cancellable,
    GAsyncReadyCallback     callback,
    gpointer                user_data);
GDBusObjectManager *terminal_object_manager_client_new_for_bus_finish (
    GAsyncResult        *res,
    GError             **error);
GDBusObjectManager *terminal_object_manager_client_new_for_bus_sync (
    GBusType                bus_type,
    GDBusObjectManagerClientFlags  flags,
    const gchar            *name,
    const gchar            *object_path,
    GCancellable           *cancellable,
    GError                **error);


G_END_DECLS

#endif /* __TERMINAL_GDBUS_GENERATED_H__ */