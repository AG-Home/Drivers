#! /bin/bash

if [ ! -d "documentation/" ] 
then
    mkdir documentation
fi

doxygen config-doxygen.conf 2> doxygen.log