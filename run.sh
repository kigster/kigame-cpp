#/usr/bin/env bash

bldblk='\e[1;30m'
bldred='\e[1;31m'
bldgrn='\e[1;32m'
bldylw='\e[1;33m'
bldblu='\e[1;34m'
bldpur='\e[1;35m'
bldcyn='\e[1;36m'
bldwht='\e[1;37m'

clr='\e[0m'

DCC="/usr/local/bin/gcc"
DCXX="/usr/local/bin/g++-8"


build::env::print() {
  printf "———————————————————————————————————————————————————————\n"
  printf "${bldylw}PATH: ${clr}CC=${bldgrn}=${bldblu}${CC}${clr}\n"
  printf "${bldylw}PATH: ${clr}GCC=${bldgrn}$(which gcc)${clr}\n"
  printf "${bldylw}PATH: ${clr}GCC=${bldgrn}$(gcc --version 2>&1 | head -2 | tr '\n' '; ')${clr} CC=${bldblu}${CC}${clr}\n\n"

  printf "${bldylw}PATH: ${clr}CXX=${bldblu}${CXX}${clr}\n"
  printf "${bldylw}PATH: ${clr}GXX=${bldgrn}$(which g++)${clr}\n"
  printf "${bldylw}PATH: ${clr}GXX=${bldgrn}$(g++ --version 2>&1 | head -2 | tr '\n' '; ')${clr}\n\n"
  printf "———————————————————————————————————————————————————————\n\n"
}

if [[ -z "${FORCE_DEFAULT_COMPILER}" && -x "${DCC}" && -x "${DCXX}" ]]; then
  export CC=${CC:-${DCC}}
  export CXX="${CXX:-${DCXX}}"
fi

build::env::print 

set -e -x

git submodule init && git submodule update 

rm -rf build bin lib; mkdir -p build/debug; cd build/debug

cmake ../.. 
make -j 8 
make install

cd ../..

# now run the tests
set +x
for binary in $(find bin -type f -perm -111); do 
  echo " Running file ${binary}..."
  ${binary}; code=$?
  (( ${code} )) && { 
    echo " ${binary} exited with code ${code}"
  exit ${code}
}
done

exit 0

