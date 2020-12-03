#!/bin/bash
# Author: Frazer Grant
# Version: 1.1


##functions 
function pause(){
 read -s -n 1 -p "Press any key to continue . . ."
 echo ""
}

## functions end


dt=$(date '+%d/%m/%Y %H:%M:%S');
date=$(date '+%d_%m_%Y');

# rest of script below
##~/.[^.]*



## BACKUP	
	

## Make Temp DIR
		    mkdir temp
## Copy folder and files 
		    rsync -avzP	~/.bin/* temp/.bin/
		    rsync -avzP	~/.fonts/* temp/.fonts/
		    rsync -avzP	~/.icons/* temp/.icons
		    rsync -avzP	~/.themes/* temp/.themes
		    rsync -avzP	~/.arch.png temp/	
		    rsync -avzP	~/.bash_aliases temp/
		    rsync -avzP	~/.bash_profile temp/
		    rsync -avzP	~/.bashrc temp/
		    rsync -avzP	~/.conkyrc temp/

## Copy .local
                    mkdir temp/.local
                    mkdir temp/.local/share
                    mkdir temp/.local/share/gnome-boxes 
                    mkdir temp/.local/share/gnome-recipes
                    mkdir temp/.local/share/gnome-robots
                    mkdir temp/.local/share/gnome-settings-daemon
                    mkdir temp/.local/share/icons
                    mkdir temp/.local/share/themes
                    mkdir temp/.local/share/arcmenu
                    mkdir temp/.local/share/gnome-shell 
                    mkdir temp/.local/share/backgrounds
                    mkdir temp/.local/share/nautilus
                    mkdir temp/.local/share/dconf
                    
                    rsync -avzP	~/.local/bin/* temp/.local/bin/
                    rsync -avzP	~/.local/lib/* temp/.local/lib/
		    rsync -avzP ~/.local/share/gnome-boxes/* temp/.local/share/gnome-boxes/
		    rsync -avzP ~/.local/share/gnome-recipes/* temp/.local/share/gnome-recipes/
		    rsync -avzP ~/.local/share/gnome-robots/* temp/.local/share/gnome-robots/
		    rsync -avzP ~/.local/share/gnome-settings-daemon/* temp/.local/share/gnome-settings-deamon/
		    rsync -avzP ~/.local/share/icons/* temp/.local/share/icons/
		    rsync -avzP ~/.local/share/gnome-shell/* temp/.local/share/gnome-shell/
		    rsync -avzP ~/.local/share/arcmenu/* temp/.local/share/arcmenu/
		    rsync -avzP ~/.local/share/backgrounds/* temp/.local/share/backgrounds/
                    rsync -avzP ~/.local/share/nautilus/* temp/.local/share/nautilus
                    rsync -avzP ~/.local/share/dconf/* temp/.local/share/dconf/

## Copy .config

		    mkdir temp/.config
		    mkdir temp/.config/configstore
		    mkdir temp/.config/dconf
		    mkdir temp/.config/gnome-boxes
		    mkdir temp/.config/gnome-control-center
		    mkdir temp/.config/gnome-session
		    mkdir temp/.config/gtk-3.0
		    mkdir temp/.config/gtk-4.0
		    
		    rsync -avzP	~/.config/configstore/* temp/.config/configstore/
		    rsync -avzP	~/.config/dconf/* temp/.config/dconf
		    rsync -avzP	~/.config/gnome-boxes/* temp/.config/gnome-boxes
		    rsync -avzP	~/.config/gnome-control-center/* temp/.config/gnome-control-center
		    rsync -avzP	~/.config/gnome-session/* temp/.config/gnome-session
		    rsync -avzP	~/.config/gtk-3.0/* temp/.config/gtk-3.0
		    rsync -avzP	~/.config/gtk-4.0/* temp/.config/gtk-4.0
		    







## Compresses backup file	
		    tar -zcvf backup.tar.gz  temp/.[^.]*
		
## Make folder
		    mkdir /$date
			
## Moves backup to network location.

			
## Removes backup file from home dir

			
## Removes from trash 
			#rm -rf ~/.local/share/Trash/files/backup.tar.gz
                       
		    echo "Task compleated $dt"

			




