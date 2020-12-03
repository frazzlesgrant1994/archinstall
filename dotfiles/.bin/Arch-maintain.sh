#!/bin/bash
# update/ and cleaning script Arch linux
#Auther: Frazer
#Version: 0.1

function pause(){
 read -s -n 1 -p "Press any key to continue . . ."
 echo ""
}
dt=$(date '+%d/%m/%Y %H:%M:%S');
 
# rest of script below

# System updates

##yay -Syu 

clear
# Clean cached app downloads/ 

yay -Scc

clear
# Checks for old unused packages

sudo pacman -Qtdq

clear
# Removes unused packages 

sudo pacman -Rns $(pacman -Qtdq)
clear
#Cache size in /home

sudo du -sh ~/.cache/

pause

#Clean /home cache
cat /dev/null > .bash_history
rm -rf ~/.cache/*
clear


echo "Task compleated $dt"
pause
