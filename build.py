#!/usr/bin/python

from os import system

do = lambda cmd: system(cmd)

do('echo "Moving to ./build/..."')
do('cd build && echo "Removing previous build files..." && rm -rf ./*')
do('cd build && cmake ..')
do('cd build && make')
do('clear && echo "Build complete! Executing program..."')
do('./build/game-demo')

