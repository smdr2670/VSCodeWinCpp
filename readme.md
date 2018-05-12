## Prerequisites

First things first, [download Visual Studio Code](https://code.visualstudio.com/download). Then [download MSYS2](https://www.msys2.org/) and follow the instructions there.

## Installing gcc with MinGW
After installing the prerequisites, we need to install gcc delivered by the mingw-toolchain. For this, start MSYS2 MinGW 64-bit and type `pacman -S mingw-w64-x86_64-toolchain`. Restart MSYS2 MinGW 64-bit and verify that gcc has been installed correctly with `gcc -v`.

## Installing extensions for VSCode 
Start Visual Studio Code and press <kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>x</kbd> 
to open Extensions. Download C/C++ package for Intellisense, debugging, and code browsing.  

![](https://media.giphy.com/media/7zSzFQluydVuZdceE4/giphy.gif)

