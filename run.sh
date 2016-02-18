#!/bin/bash
premake5 gmake
rm ./bin/Debug/LoveShips
make
./bin/Debug/LoveShips
