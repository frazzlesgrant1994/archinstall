#!/bin/bash

uname=$(whoami)

##Setup Config Script

## Software
	
	sudo pacman -S  rsync binutils fakeroot gcc make git patch conky  -y
	

if [ "$XDG_CURRENT_DESKTOP" = "GNOME" ]; then
	echo "GNOME Is installed" ;
	
else 

         sudo pacman -S gnome gnome-extra gnome-tweaks gdm 
	 sudo systemctl enable gdm.service
fi
	
	
## Install Office 	
 clear
 read -r -p "Would you like to install LibreOffice? [Y/n]" response
 response=${response,,} # tolower
 if [[ $response =~ ^(yes|y| ) ]] || [[ -z $response ]]; then
	sudo pacman -S libreoffice-fresh
    

 fi

## Update system 
	#sudo pacman -Syu -y 
	clear

## install dot files 

 read -r -p "Would you like to restore original config? [Y/n]" response
 response=${response,,} # tolower
 if [[ $response =~ ^(yes|y| ) ]] || [[ -z $response ]]; then
    bash dotfiles.sh
 fi
 
## fstab
 read -r -p "Would you like to configure network drives? [Y/n]" response
 response=${response,,} # tolower
 if [[ $response =~ ^(yes|y| ) ]] || [[ -z $response ]]; then
	sudo bash fstab.sh
fi		
## install yay  
 clear
 read -r -p "Would you like to install yay-aur helper? [Y/n]" response
 response=${response,,} # tolower
 if [[ $response =~ ^(yes|y| ) ]] || [[ -z $response ]]; then
        cd /opt
	sudo git clone https://aur.archlinux.org/yay-git.git
	clear
	sudo chown -R $uname:$uname ./yay-git
	cd yay-git
	makepkg -si
	cd ~/archinstall/
fi
	clear
## Default Shell 
	sudo usermod --shell /bin/bash $uname
	
## Apps 
	yay -S archey4 -y

## Custom terminal
 read -r -p "Would you like to configure a custom terminal? [Y/n]" response
 response=${response,,} # tolower
 if [[ $response =~ ^(yes|y| ) ]] || [[ -z $response ]]; then
	bash terminal.sh
fi	






## Restart
 read -r -p "Would you like to restart? [Y/n]" response
 response=${response,,} # tolower
 if [[ $response =~ ^(yes|y| ) ]] || [[ -z $response ]]; then
	reboot
fi	
	
	
