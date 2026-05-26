#!/bin/bash
GREEN='\033[0;32m'
NC='\033[0m'


echo -e "\n${GREEN}##########-Cleaning the build-##########${NC}"
make clean

echo -e "\n${GREEN}##########-Building-##########${NC}"
make 

echo -e "\n${GREEN}##########-Flashing-##########${NC}"
make flash


