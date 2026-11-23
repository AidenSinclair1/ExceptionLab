# ExceptionLab
Multi-file C++ shape parser with custom exceptions, file utilities, overloaded geometry calculations, and per-line error handling.

## Build
Compile all implementation files:
```bash
g++ -std=c++14 -Wall -Wextra -pedantic main.cpp Exceptions.cpp FileUtils.cpp GeometryUtils.cpp -o ExceptionLab
```
Run the program from the folder containing `shapes.txt`. Each shape record must occupy its own line.
