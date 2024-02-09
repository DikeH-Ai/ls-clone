# ls-clone

## Task: Replicate the "ls" command on Linux

### Task Walkthrough:

The codebase is organized into four files:

1. **main.h:** Custom header file.
2. **main.c:** Main file execution.
3. **functions.c:** Accompanying functions.
4. **flags.c:** ls "options" implementation.

### Implementation Concept:

Undertaking this task in C after a spell in Python, the aim was to refresh my knowledge base in C programming. The focus was on a basic approach to problem-solving without emphasizing on optimization or visually appealing syntax.

### main.c:

The main encapsulates the `int main` and `int ls_dir` functions. The main function checks the argument count based on two possibilities:

1. `argc = 1`: In this condition, only the command is executed.  
   Example: `./main`

2. `argc > 1`: In this condition, the command and arguments are executed.  
   Example: `./main -l [directory]`

Using an if/else statement under the first condition, the current working directory is obtained, and the contents within it are listed using `ls_cwd`, In the else capsule, the `ls_dir` function is incorporated.

#### `ls_dir` function:

Handles another subset of possibilities within the `(argc > 1)` condition. There are three possible outcomes:

1. **-flag:** In this case, the preceding argument to the `./main` command is a flag (e.g., `./main -a`) with only one argument.
2. **-flag & argument:** In this case, there is at least one or more flags and arguments (e.g., `./main -a [directory]`).
3. **-argument:** In this case, there is only one argument.

These cases are handled within the `ls_dir` function with the help of other functions within the `function.c` file.

### function.c:

This file acts as a hub for useful functions used in various parts of the codebase. Functions include reading directory contents, getting the current working directory, printing file permissions, etc.

### flag.c:

Encapsulates functions that implement flag functionalities. Some functions include `ls_a` for implementing the `-a` flag to list all. The flag function can be updated with more functions as custom flags are created. Flag options are created and then updated in other parts of the code, such as the `ls_dir` function.

### main.h:

Includes imports and function declarations.
