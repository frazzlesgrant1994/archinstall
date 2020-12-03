#!/bin/bash		

##Download from owncloud server			
			 curl https://storage.smartchoiceitsolutions.co.uk:8443/owncloud/s/LfzPNLF1G0dnoNy/download --output terminal.tar.gz
        
            		
					
## Make Temp folder to extrack backup		
	        	
			mkdir tmpter
			
## Extract Backip to temp folder		    
			tar -xvf terminal.tar.gz  -C tmpter/
			
			
## Sync backup back to home dir 			
			cd tmpter/input/
			
			makepkg -si		
             
## Removes tar file			 
			cd ..
			cd ..
			
## Removes temp folder			
		   	rm -rf tmpter/*
		    	rm -rf tmpter
			clear			
		
		
