# Running
1. > gcc "./teste.cpp" -o test
1. > ./test


# Installing
## [Building on Linux](https://github.com/coin-or/COIN-OR-OptimizationSuite#building-on-linux)
Most Linux distributions come with all the required tools installed. To obtain the source code, the first step is to get the installer that will then fetch the source for ProjName and all its dependencies. You do not need to clone the repository first, just do the following! Open a terminal and execute

git clone https://www.github.com/coin-or/coinbrew
Next, to check out source code for and build all the necessary projects (including dependencies), execute the script in the coinbrew subdirectory. To execute the script, do

cd coinbrew
chmod u+x coinbrew
./coinbrew
(Note: The chmod command is only needed if the execute permission is not automatically set by git on cloning). Once you run the script, you will be prompted interactively to select a project to fetch and build. The rest should happen automagically. Alternatively, the following command-line incantation will execute the procedure non-interactively.

./coinbrew fetch --no-prompt ProjName@stable/x.y
./coinbrew build --no-prompt ProjName --prefix=/path/to/install/dir
Note that the prefix specified above is the directory where the packages will be installed. If the specified prefix is writable, then all packages will be automatically installed immediately after building. If no prefix is specified, the package will be installed in the directory dist/. Options that would have been passed to the configure script under the old build system can simply be added to the command-line. For example, to build with debugging symbols, do

./coinbrew build --no-prompt ProjName --prefix=/path/to/install/dir --enable-debug
To get help with additional options available in running the script, do

./coinbrew --help
After installation, you will also need to add /path/to/install/dir/bin to your PATH variable in your .bashrc and also add /path/to/install/dir/lib to your LD_LIBRARY_PATH if you want to link to COIN libraries.

TERMINAL: 
>nano ~/.bashrc

EDITAR FILE: na última linha adicionar:
>export PATH="/home/prod/coinbrew:$PATH"

    salvar e fechar
        ctrl + s + x Enter
TERMINAL: 

> source ~/.bashrc

> echo coinbrew



coinbrew build VS sudo apt-get install  coinor-clp coinor-libclp-dev