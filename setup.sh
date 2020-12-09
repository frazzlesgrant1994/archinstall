#!/bin/bash
workdir=$(cd -P -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd -P)
uname=$(whoami)

##Setup Config Script
clear
if [[ $(/usr/bin/id -u) -eq 0 ]]; then
  echo ""
  echo ""
  echo "	You can't run this script as sudo."
  echo "	It will ask you to login when required."
   echo ""
   echo "	Setup will now close	"
	echo "	Press any key to continue"
	read -n 1 -s -r -p ""
	clear
	exit 1
fi

### Pointless function 
# 1. Create ProgressBar function
# 1.1 Input is currentState($1) and totalState($2)
function ProgressBar {
# Process data
    let _progress=(${1}*100/${2}*100)/100
    let _done=(${_progress}*4)/10
    let _left=40-$_done
# Build progressbar string lengths
    _fill=$(printf "%${_done}s")
    _empty=$(printf "%${_left}s")

# 1.2 Build progressbar strings and print the ProgressBar line
# 1.2.1 Output example:                           
# 1.2.1.1 Progress : [########################################] 100%

printf "\r   Loading Setup : [${_fill// /#}${_empty// /-}] ${_progress}%%"

}

# Variables
_start=1

# This accounts as the "totalState" variable for the ProgressBar function
_end=100

# Proof of concept
for number in $(seq ${_start} ${_end})
do
    sleep 0.005
    ProgressBar ${number} ${_end}
done
printf '\nFinished!\n'
clear
## Welcome Screen 
echo ""
echo ""
echo "	.------..------..------..------..------..------..------."
echo "	|W.--. ||E.--. ||L.--. ||C.--. ||O.--. ||M.--. ||E.--. |"
echo "	| :/\: || (\/) || :/\: || :/\: || :/\: || (\/) || (\/) |"
echo "	| :\/: || :\/: || (__) || :\/: || :\/: || :\/: || :\/: |"
echo "	| '--'W|| '--'E|| '--'L|| '--'C|| '--'O|| '--'M|| '--'E|"
echo "	'------''------''------''------''------''------''------'"
sleep 0.1
echo "	Welcome to my setup tool."
sleep 0.1
echo "	This tool will install Gnome, GDM plus options to install a couple of other programs. "
sleep 0.1
echo "	This will also transfer my Gnome config files. "
sleep 0.1
echo "	Please note this script will only work on Arch based systems. "
echo ""
echo ""
sleep 0.1
echo "	Version 1.5"
sleep 0.1
echo "	Author: Frazer Grant"
echo ""
echo ""
sleep 0.5
read -r -p "	Would you like to continue setup [Y/n] " response
 response=${response,,} # tolower
 if [[ $response =~ ^((yes|y| )) ]] || [[ -z $response ]]; then
	clear 
 else 
 clear
   exit 1
 fi

## Software
sleep 0.5
	sudo pacman -S  rsync binutils fakeroot gcc make git patch conky  -y
	

if [ "$XDG_CURRENT_DESKTOP" = "GNOME" ]; then
	echo "GNOME Is installed" ;
	
else 

         sudo pacman -S gnome gnome-extra gnome-tweaks gdm 
	 sudo systemctl enable gdm.service
	 sudo systemctl enable NetworkManager.service
fi
	
	
## Install Office 	
 clear
 sleep 0.5
 echo ""
echo ""
 read -r -p "	Would you like to install LibreOffice? [Y/n]" response
 response=${response,,} # tolower
 if [[ $response =~ ^(yes|y| ) ]] || [[ -z $response ]]; then
	sudo pacman -S libreoffice-fresh
    

 fi


## Update system 
	#sudo pacman -Syu -y 
	clear
sleep 0.5
## install dot files 
echo ""
echo ""
 read -r -p "	Would you like to restore original config? [Y/n]" response
 response=${response,,} # tolower
 if [[ $response =~ ^(yes|y| ) ]] || [[ -z $response ]]; then
    bash dotfiles.sh
 fi
 clear
 sleep 0.5
## fstab
echo ""
echo ""
 read -r -p "	Would you like to configure network drives? [Y/n]" response
 response=${response,,} # tolower
 if [[ $response =~ ^(yes|y| ) ]] || [[ -z $response ]]; then
	sudo bash fstab.sh
fi

clear	
## Custom terminal
echo ""
echo ""
 read -r -p "	Would you like to configure a custom terminal? [Y/n]" response
 response=${response,,} # tolower
 if [[ $response =~ ^(yes|y| ) ]] || [[ -z $response ]]; then
	bash terminal.sh
fi	



clear
sleep 0.5
## install yay  
 clear
 sleep 0.5
 echo ""
echo ""
 read -r -p "	Would you like to install yay-aur helper? [Y/n]" response
 response=${response,,} # tolower
 if [[ $response =~ ^(yes|y| ) ]] || [[ -z $response ]]; then
        cd /opt
	sudo git clone https://aur.archlinux.org/yay-git.git
	clear
	sudo chown -R $uname:$uname ./yay-git
	cd yay-git
	makepkg -si
	cd $workdir/archinstall/
fi
	clear
## Default Shell 
if [ "$SHELL" = "/bin/bash" ]; then
	echo "Bash is default" ;
	
else 

	sudo usermod --shell /bin/bash $uname
fi


clear	
## Apps 
echo ""
echo ""
 read -r -p "	Would you like to install Archey terminal bling? [Y/n]" response
 response=${response,,} # tolower
 if [[ $response =~ ^(yes|y| ) ]] || [[ -z $response ]]; then
	yay -S archey4 -y

fi	



## Restart
echo ""
echo ""
 read -r -p "	Would you like to restart? [Y/n]" response
 response=${response,,} # tolower
 if [[ $response =~ ^(yes|y| ) ]] || [[ -z $response ]]; then
	reboot
else
exit 1
fi	
	
