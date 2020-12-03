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
else 	
echo ''
echo ''
echo '	We will now create a credentials file under /etc/'
sudo touch /etc/.smbcred
echo ''
echo '' 
	read -r -p '	Username for authentication: ' username
	
	clear
	echo -n 'Password for authentication: '
	read -s password
	
	sudo echo "username=$username" >> /etc/.smbcred
	sudo echo "password=$password" >> /etc/.smbcred
	sudo chmod 600 /etc/.smbcred
fi 
	
	
	
	
	clear
	#Info
	echo ''
        echo ''
	read -r -p  '	Server Name/IP: ' server
	clear
	
	read -r -p  '	Network Share: ' share
	clear
	echo ''
        echo ''
	 read -r -p "	Is the server joined to a domain? [Y/n]" response
 	response=${response,,} # tolower
 	if [[ $response =~ ^(yes|y| ) ]] || [[ -z $response ]]; then
	echo ''
        echo ''
	read -r -p '	Domain: ' domain
	sudo echo "//$server/$share	/media/share	cifs	credentials=/etc/.smbcred,domain=$domain,iocharset=utf8,gid=1000,uid=1000,file_mode=0777,dir_mode=0777	0	0
" >> /etc/fstab 
	else 
	sudo echo "//$server/$share	/media/share	cifs	credentials=/etc/.smbcred,iocharset=utf8,gid=1000,uid=1000,file_mode=0777,dir_mode=0777	0	0
" >> /etc/fstab 


	fi
	
	
	
	
	
	clear
	# /etc/fstab
	sudo echo "//$server/$share	/media/share	cifs	credentials=/etc/.smbcred,domain=$domain,iocharset=utf8,gid=1000,uid=1000,file_mode=0777,dir_mode=0777	0	0
" >> /etc/fstab 

	clear
	echo 'Compleate'
