#! /bin/bash

if [ ! -d "documentation/" ] 
then
    mkdir documentation
fi

../Tools/Doxygen/doxygen-1.9.4/bin/doxygen config-doxygen.conf 2> doxygen.log