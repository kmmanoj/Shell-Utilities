#!/bin/bash
echo -e "\n\033[0;35m\033[1m============Template utility==============\033[0m";
sudo rm -f /usr/bin/program
echo "Removed Command 'program'";
sudo rm ~/Templates/javaheader 2> /dev/null
sudo rm ~/Templates/java 2> /dev/null
sudo rm ~/Templates/html 2> /dev/null
sudo rm ~/Templates/c 2> /dev/null
sudo rm ~/Templates/cpp 2> /dev/null
sudo rm ~/Templates/asm 2> /dev/null
echo "Removed Templates!"
echo -e "\n\033[0;31m\033[1m============Uninstalled Template utility==============\033[0m";
