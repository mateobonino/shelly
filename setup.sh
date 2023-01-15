#!/usr/bin/env bash
which gcc &> /dev/null
if [ $? == 0 ]; then
    echo "gcc already installed..."
else
    sudo apt update
    sudo apt install build-essential -y
    sudo apt-get install manpages-dev -y
fi
sleep 2
which make &> /dev/null
if [ $? == 0 ]; then
    echo "GNU Make already installed..."
else
    sudo apt update
    sudo apt install make -y
fi
sleep 2
echo "Everything installed!"
sleep 1
echo "Building your shell..."
sleep 2
make default &> /dev/null
if [ $? == 0 ]; then
    sleep 2
    echo "Builded succesfully!"
else
    echo "Something went wrong during the building..."
fi
sleep 1
