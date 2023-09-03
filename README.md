# RPG GAME
First steps in developing RPG game to learn C++

First i have installed CMake and SFML lib and GTest
sudo apt-get install libsfml-dev

```shell
git submodule add git@github.com:google/googletest.git
git submodule init
git submodule update
```

To build project go into build dir and execute make command

```shell
cmake ..
make
```

To clean build dir use 

make clean

To run project power up its executable, same concernig tests