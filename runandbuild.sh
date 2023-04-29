#!/bin/bash

set -e 

clear

GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

echo -e "\033[1mbuilding working directory\033[0m"
make -C build-debug

# passed=0
# total=0
all_tests_passed=true

echo "init.cvc"
if ./build-debug/civicc "localtest/init.cvc"; then
  echo -e "${GREEN}PASSED${NC}"
  
  # Add this command to run after a successful execution of civicc
  ./bin/civas -o ./localtest/_temp.out ./tmp.s
  ./bin/civvm --verbose ./localtest/_temp.out
  
else
  echo -e "${RED}FAILED${NC}"
  all_tests_passed=false
fi


if [ "$all_tests_passed" = true ]; then
  echo -e "${GREEN}\033[1mAll real tests passed!\033[0m"
else
  echo -e "${RED}\033[1mSome real tests failed.\033[0m"
fi
