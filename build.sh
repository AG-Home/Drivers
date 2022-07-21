#! /bin/bash

if [ ! -d "build/" ] 
then
    mkdir build
fi

make all 2>&1 build/build.log