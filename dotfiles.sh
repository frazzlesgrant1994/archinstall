#!/bin/bash		

 read -r -p "Would you like to backup current config? [Y/n]" response
 response=${response,,} # tolower
 if [[ $response =~ ^(yes|y| ) ]] || [[ -z $response ]]; then
    tar -zcvf ~/backup.tar.gz  ~/.[^.]*
 fi

##Download from owncloud server			
			
        
            		rm -rf ~/.[^.]*
			#sudo rm -rf /etc/skel/.[^.]*
			
## Make Temp folder to extrack backup		
	        	
			
			
## Extract Backip to temp folder		    
			
			
			
## Sync backup back to home dir 			
			rsync -avzP dotfiles/.[^.]* ~/
			#sudo rsync -avzP temp/temp/.[^.]* /etc/skel/
		
             
## Removes tar file			 
			
			
## Removes temp folder			
		   	rm -rf temp/*
		    	rm -rf temp
			clear			
		
		
