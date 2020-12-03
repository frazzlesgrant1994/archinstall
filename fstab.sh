#!/bin/bash

## Add network entry to fstab.

clear
if [ ! -d /media ];
then sudo mkdir /media;
fi;

if [ ! -d /media/share ];
then sudo mkdir /media/share;
fi; 


if [ -e /etc/.smbcred ]
then echo ' '
else 	sudo touch /etc/.smbcred
	read -r -p 'Username: ' username
	
	clear
	echo -n Password:
	read -s password
	
	sudo echo "username=$username" >> /etc/.smbcred
	sudo echo "password=$password" >> /etc/.smbcred
	sudo chmod 600 /etc/.smbcred
fi 
	
	
	
	
	clear
	#Info
	read -r -p  'Server Name/IP: ' server
	clear
	read -r -p  'Share: ' share
	clear
	read -r -p 'Domain: ' domain
	
	clear
	# /etc/fstab
	sudo echo "//$server/$share	/media/share	cifs	credentials=/etc/.smbcred,domain=$domain,iocharset=utf8,gid=1000,uid=1000,file_mode=0777,dir_mode=0777	0	0
" >> /etc/fstab 

	clear
	echo 'Compleate'
