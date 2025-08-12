#! /usr/bin/env bash
ans=""
echo -n "ShutDown? or Reboot? (Return/R/X): "
read ans

if [ -z  $ans ]; then
   sudo systemctl poweroff 
elif [ $ans == "R" ] || [ $ans == "r" ]; then
   sudo  systemctl reboot
else
   echo "Exiting"
fi
