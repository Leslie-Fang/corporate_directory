## pre-request
brew install glog
if not find glog:
1.git clone https://github.com/google/glog.git
2.brew install autoconf automake cmake libtool
3. ./autogen.sh && ./configure  --prefix=path(install) && make && make install 

## Build
make

## HowTo
./build/main

## Test
make test

This project:
use gflags to parse input command
use gtest to do the unit test
use glog to log the inforation
