 
#!/bin/bash
 

 if [ "$XDG_CURRENT_DESKTOP" = "GNOME" ]; then
	echo "GNOME Is installed" ;
	
else 

         sudo pacman -S gnome gnome-extra gnome-tweaks gdm 
	 sudo systemctl enable gdm.service

 fi
