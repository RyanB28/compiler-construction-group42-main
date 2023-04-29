#!/bin/bash

set -e 

echo "Running files"
./testSuite/bin/civrun ./decalstest.cvc
./testSuite/bin/civrun functiondecl.cvc