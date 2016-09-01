#!/bin/bash
echo -e "\n\033[0;35m\033[1m============Template utility==============\033[0m";
cd /usr/bin
sudo rm -f program
echo "Removed Command program";
cd ~/Templates
sudo rm javaheader 2> /dev/null
sudo rm java 2> /dev/null
sudo rm html 2> /dev/null
sudo rm c 2> /dev/null
sudo rm cpp 2> /dev/null
sudo rm asm 2> /dev/null
echo "Removed"
echo -e "\n\033[0;31m\033[1m============Uninstalled Template utility==============\033[0m";