#! /bin/bash

if [ ! -d "build/" ] 
then
    mkdir build
fi

make 2> build/build.log

mv APPL.out build/APPL.out