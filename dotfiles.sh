#!/bin/bash		

 read -r -p "Would you like to backup current config? [Y/n]" response
 response=${response,,} # tolower
 if [[ $response =~ ^(yes|y| ) ]] || [[ -z $response ]]; then
    tar -zcvf ~/backup.tar.gz  ~/.[^.]*
 fi

##Download from owncloud server			
			 curl https://storage.smartchoiceitsolutions.co.uk:8443/owncloud/s/oZdsBe72K3y5JEp/download  --output dotfiles.tar.gz
        
            		rm -rf ~/.[^.]*
			#sudo rm -rf /etc/skel/.[^.]*
			
## Make Temp folder to extrack backup		
	        	
			mkdir temp
			
## Extract Backip to temp folder		    
			tar -xvf dotfiles.tar.gz  -C temp/
			
			
## Sync backup back to home dir 			
			rsync -avzP temp/temp/.[^.]* ~/
			#sudo rsync -avzP temp/temp/.[^.]* /etc/skel/
		
             
## Removes tar file			 
			rm -rf  dotfiles.tar.gz
			
## Removes temp folder			
		   	rm -rf temp/*
		    	rm -rf temp
			clear			
		
		
