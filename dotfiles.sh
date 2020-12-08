#!/bin/bash		
echo ''
echo '' 
echo '	WARNING!! Running this will delete current config.' 
 read -r -p "	Would you like to backup current config? [Y/n]" response
 response=${response,,} # tolower
 if [[ $response =~ ^(yes|y| ) ]] || [[ -z $response ]]; then
    tar -zcvf ~/backup.tar.gz  ~/.[^.]*
 fi

	
			
## Removes current config        
            		rm -rf ~/.[^.]*

					    
			
			
			
## Sync backup back to home dir 			
			rsync -avzP dotfiles/.[^.]* ~/

		
             

			clear			
		
		
