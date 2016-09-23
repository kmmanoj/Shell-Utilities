#!/bin/bash
echo -e "\n\033[0;35m\033[1m============Template utility==============\033[0m";
sudo cp ./program /usr/bin/
if [ ! -d ~/Templates ];
then 
	mkdir ~/Templates;
	echo "Creating Templates folder";
else
	echo "Templates folder already exists";
fi
sudo cp ./Templates/* ~/Templates/
echo "Templates Filled!!!";
echo -e "\n Feel free edit the Templates in ~/Templates/ directory as per your usage";
echo -e "\n\033[0;32m\033[1m============Installed Templates utility==============\033[0m";

