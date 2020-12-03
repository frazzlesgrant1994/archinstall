#!/bin/bash
# Bash Menu Script Example

function pause(){
 read -s -n 1 -p "Press any key to continue . . ."
 echo ""
}
dt=$(date '+%d/%m/%Y %H:%M:%S');

# rest of script below


PS3='Please enter your choice: '
options=("Backup" "Restore" "Quit")
select opt in "${options[@]}"
do
    case $opt in
        "Backup")
			rsync -avzP ~/.[^.]* /media/share/Linux-backup/frazer
                        echo "Task compleated $dt"

            ;;
        "Restore")
			rsync -avzP /media/share/Linux-backup/frazer/.[^.]* ~/
                        echo "Task compleated $dt"
		  ;;
        "Quit")
            exit
            ;;
        *) echo "invalid option $REPLY";;
    esac
done
