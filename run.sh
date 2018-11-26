#!/usr/bin/env bash

set -e -x

DCC="/usr/local/bin/gcc"
DCXX="/usr/local/bin/g++-8"

if [[ -z "${FORCE_DEFAULT_COMPILER}" && -x "${DCC}" && -x "${DCXX}" ]]; then
  export CC=${CC:-${DCC}}
  export CXX="${CXX:-${DCXX}}"
fi

git submodule init && git submodule update 

rm -rf build bin lib; mkdir -p build/debug; cd build/debug

cmake ../.. 
make -j 8 
make install

cd ../..

# now run the tests
for binary in $(find bin -type f -perm -111); do 
  echo " Running file ${binary}..."
  ${binary}; code=$?
  (( ${code} )) && { 
    echo " ${binary} exited with code ${code}"
    exit ${code}
  }
done

exit 0

