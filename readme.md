## Prerequisites

First things first, [download Visual Studio Code](https://code.visualstudio.com/download). Then [download MSYS2](https://www.msys2.org/) and follow the instructions there.

## Installing gcc with MinGW
After installing the prerequisites, we need to install gcc delivered by the mingw-toolchain. For this, start MSYS2 MinGW 64-bit and type `pacman -S mingw-w64-x86_64-toolchain`. Restart MSYS2 MinGW 64-bit and verify that gcc has been installed correctly with `gcc -v`.

## Installing extensions for VSCode 
Start Visual Studio Code and press <kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>x</kbd> 
to open Extensions. Download C/C++ package for Intellisense, debugging, and code browsing.  

![](https://media.giphy.com/media/7zSzFQluydVuZdceE4/giphy.gif)

Do the same procedure for `Code Runner`.


## User Settings
Press <kbd>Ctrl</kbd>+<kbd>,</kbd> or go to File->Preferences->Settings and the User Settings will open up. Everything that you want to edit or customize will take place there. At first, we have to link VSCode with the shell of MSYS2. On windows, the integrated shell is Window Powershell. Paste the following code in to your User Settings.

```
{
    "window.zoomLevel": 0,
    "terminal.integrated.shell.windows": "C:\\msys64\\usr\\bin\\bash.exe",
    "terminal.integrated.shellArgs.windows": ["-i"],
    "terminal.integrated.env.windows": { "PATH" : "/mingw64/bin:/usr/local/bin:/usr/bin:/bin:/c/Windows/System32:/c/Windows:/c/Windows/System32/Wbem:/c/Windows/System32/WindowsPowerShell/v1.0/"}
}

```

Restart the terminal or VSCode and verify that you have bash as an integrated shell instead of Windows Powershell. 
![](https://media.giphy.com/media/8lJP6F3Fvnuafeqlwf/giphy.gif)

## Build and Run with Coderunner

Using Coderunner we can compile and run code with <kbd>Ctrl</kbd><kbd>Alt</kbd><kbd>N</kbd>. For this, we have to specify our build command and a few options in our user setting. Expand the settings.json with 
```
{
    "window.zoomLevel": 0,
    "terminal.integrated.shell.windows": "C:\\msys64\\usr\\bin\\bash.exe",
    "terminal.integrated.shellArgs.windows": ["-i"],
    "terminal.integrated.env.windows": { "PATH" : "/mingw64/bin:/usr/local/bin:/usr/bin:/bin:/c/Windows/System32:/c/Windows:/c/Windows/System32/Wbem:/c/Windows/System32/WindowsPowerShell/v1.0/"},
    "code-runner.executorMap": {"cpp" : "g++ -std=c++17 $fileName -o $fileNameWithoutExt && ./$fileNameWithoutExt.exe" },
    "code-runner.runInTerminal": true,
    "code-runner.ignoreSelection": true
}

```
In this snippet, `gcc` will compile the `.cpp` file with the C++1z standard, allowing `fold`-expressions, `constexpr if` etc...
Code Runner of course should run in the terminal we have setup and `code-runner.ignoreSelection` is set to true to always run the entire file and not a selection which has been done unpurposely.

