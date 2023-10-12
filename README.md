# libellulus
Libellulus es una biblioteca de registro (logger) simple para aplicaciones escritas en C++. Proporciona una forma fácil y flexible de registrar información en tiempo de ejecución para ayudar en la depuración y diagnóstico de problemas en tu aplicación.

## Compilation
To compile the source files, the C++ compiler `g++` and the C compiler `gcc` are used. The `-fPIC` flag is used to generate position-independent objects. The generated library file is stored in the `lib` directory.

## Project Structure
- `src`: Contains the source code for the project.
- `inc`: Contains header files.
- `obj`: Stores object files.
- `lib`: Stores the generated library.
- `test`: Contains test programs.
- `Makefile`: The Makefile for building the project.

## Targets
- `install`: Builds the shared library.
- `cmain`: Compiles the C test program.
- `cxmain`: Compiles the C++ test program.
- `clean`: Removes all generated objects and the library.
- `links`: Creates symbolic links for `libelus.so.1.0`.

## Usage of `vars`
1. Ensure that the script has execute permissions. You can grant execute permissions by running the following command:

```bash
chmod +x vars.sh
```

2. Run the script to set up the necessary environment variables for the project:
This script will:

Create the lib and obj directories if they don't exist.
Create the /LSRC directory if it doesn't exist.
Set the LD_LIBRARY_PATH environment variable to include the /LSRC directory.
Set the LSRC environment variable to the current working directory.

## Usage
1. Run `make install` to build the shared library.
2. Run `make cmain` or `make cxmain` to compile the test programs.
3. Run `make clean` to remove all generated files.
