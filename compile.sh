#!/bin/bash

echo "Compiling..."
echo " "
cd src/
g++ -c main.cpp Starmap.cpp Menu.cpp Options.cpp Paddle.cpp Ball.cpp TableMap.cpp -I/Documents/SFML/SFML_SRC/include 
echo "Linking..."
echo " "

if [ -e main.cpp~ ] ;
then
    rm main.cpp~
fi
if [ -e Menu.cpp~ ] ;
then
    rm Menu.cpp~
fi
if [ -e Options.cpp~ ] ;
then
    rm Options.cpp~
fi
if [ -e Paddle.cpp~ ] ;
then
    rm Paddle.cpp~
fi
if [ -e Ball.cpp~ ] ;
then
    rm Ball.cpp~
fi
if [ -e Starmap.cpp~ ] ;
then
    rm Starmap.cpp~
fi
if [ -e TableMap.cpp~ ];
then 
    rm TableMap.cpp~
fi

mv *.o ../linkers
cd ../linkers

g++ main.o Starmap.o Menu.o Options.o Paddle.o Ball.o TableMap.o -o pong -L/Documents/SFML/SFML_SRC/lib -lsfml-graphics -lsfml-window -lsfml-system

mv pong ../
cd ../

if [ -e compile.sh~ ] ;
then 
    rm compile.sh~ 
fi

cd include/
if [ -e Menu.hh~ ] ;
then
    rm Menu.hh~
fi
if [ -e Options.hh~ ] ;
then
    rm Options.hh~
fi
if [ -e Paddle.hh~ ] ;
then
    rm Paddle.hh~
fi
if [ -e Ball.hh~ ] ;
then
    rm Ball.hh~
fi
if [ -e Starmap.hh~ ] ;
then
    rm Starmap.hh~
fi
if [ -e TableMap.hh~ ] ;
then
    rm TableMap.hh~
fi

cd ..
echo "Executing..."
echo " "
./pong

