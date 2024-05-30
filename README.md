# GraphicalCalculator

The project was done in WSL, therefore a linux file system

## How to compile the project

1. Ensure the dependency wxWidget is installed on your system
- TODO: Automate the installation of wxWidget with CMake if possible
2. Go to GraphCalc/build directory and type the command `cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=ON`
3. Wait for the compilation to finish. Then type `make`
4. Done ! Now start the project from the build directory using the command `./GraphCalc`
