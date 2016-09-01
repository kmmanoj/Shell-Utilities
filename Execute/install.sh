#!/bin/bash
echo -e "\n\033[0;35m\033[1m============Compiler utility==============\033[0m";
echo "Select the compilers that you have [ use (y/n) ]";

echo "Java?"
read -n 1 confirmation
if [ "$confirmation" == 'y' ] || [ "$confirmation" == 'Y' ];then
	echo -e "\n\033[0;32m\033[1mJava Set\033[0m";
	sudo cp ./javaexe /usr/bin/
else
	echo -e "\n\033[0;31m\033[1mSkipped Java\033[0m";
fi

echo "C++?"
read -n 1 confirmation
if [ "$confirmation" == 'y' ] || [ "$confirmation" == 'Y' ];then
	echo -e "\n\033[0;32m\033[1mC++ Set\033[0m";
	sudo cp ./cppexe /usr/bin/
else
	echo -e "\n\033[0;31m\033[1mSkipped C++\033[0m";
fi

echo "C?"
read -n 1 confirmation
if [ "$confirmation" == 'y' ] || [ "$confirmation" == 'Y' ];then
	echo -e "\n\033[0;32m\033[1mC Set\033[0m";
	sudo cp ./cexe /usr/bin/
else
	echo -e "\n\033[0;31m\033[1mSkipped C\033[0m";
fi

echo "R interpreter?"
read -n 1 confirmation
if [ "$confirmation" == 'y' ] || [ "$confirmation" == 'Y' ];then
	echo -e "\n\033[0;32m\033[1mR Set\033[0m";
	sudo cp ./rexe /usr/bin/
else
	echo -e "\n\033[0;31m\033[1mSkipped R\033[0m";
fi

echo "Python interpreter?"
read -n 1 confirmation
if [ "$confirmation" == 'y' ] || [ "$confirmation" == 'Y' ];then
	echo -e "\n\033[0;32m\033[1mPython Set\033[0m";
	sudo cp ./pyexe /usr/bin/
else
	echo -e "\n\033[0;31m\033[1mSkipped python\033[0m";
fi

echo "asm?"
read -n 1 confirmation
if [ "$confirmation" == 'y' ] || [ "$confirmation" == 'Y' ];then
	echo -e "\n\033[0;32m\033[1mASM Set\033[0m";
	sudo cp ./asmexe /usr/bin/
else
	echo -e "\n\033[0;31m\033[1mSkipped asm\033[0m";
fi

echo "Node.js?"
read -n 1 confirmation
if [ "$confirmation" == 'y' ] || [ "$confirmation" == 'Y' ];then
	echo -e "\n\033[0;32m\033[1mJavaScript Set\033[0m";
	sudo cp ./jsexe /usr/bin/
else
	echo -e "\n\033[0;31m\033[1mSkipped javascript\033[0m";
fi

echo "Finishing ...";
sudo cp ./exe /usr/bin/
echo -e "\n\033[0;32m\033[1m============Installed autocompiler utility==============\033[0m";
