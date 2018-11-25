#!/usr/bin/env bash

set -e -x

git submodule init 
git submodule update 

rm -rf build bin lib
mkdir -p build
cd build
cmake ..
make -j 4 
make install
cd ..

# now run the tests
for binary in $(find bin -type f -perm -111); do 
  ${binary}
done

