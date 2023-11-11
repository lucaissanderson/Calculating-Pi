# Little Slice of π

## Files:

##### `mathlib-test.c`
Main `C` file that works as the interface for the user. <br>
Runs various functions (depending on options given) <br>
providing their value, difference from actual, and <br>
the number of terms computed.<br>

##### `mathlib.h`
Header file that works as interface between individual<br>
function files and main `mathlib-test.c`.

##### `bbp.c`
Implments the Bailey-Bowein-Plouffe method of approximating <br>
π. Contains a function to also return number of terms <br>
calculated.

##### `euler.c`
Implements a function using Euler's approach to approximating<br>
π. Contains a function to also return number of terms <br>
calculated.

##### `madhava.c`
Implements Madhava's approach to approximating π.<br>
Contains a function to also return number of terms <br>
calculated.

##### `viete.c`
Uses Viete's method to approximate π.<br>
Contains a function to also return number of terms <br>
calculated.

##### `newton.c`
Implements the Newton-Raphson method to approximate <br>
sqaure roots. Contains a function to also return number of terms <br>
calculated.

##### `e.c`
Implements a function using Jacob Bernoulli's method to <br>
approximate the constant e. Can also return the number of <br>
terms used.

##### `Makefile`
Compiles and links the necessary files and can also <br>
format all files using `clang-format`.

##### `WRITEUP.pdf`
Analyzes the results from all the functions implemented.<br>
Uses graphs and other visual aides.

##### `DESIGN.pdf`
Demonstrates the desgin behind each source file using <br>
pseudocode.

##### `README.me`
*This* file. Provides short description of the program <br>
and its dependent/associated files. Additionally describes<br>
how to compile and run the program.

## Short Description:
This program uses several methods to approximate π, e, and <br>
roots. Prints the results to standard out. 

## Build:
To compile the program, run `$ make`, `$ make all`, <br>
or `$ make mathlib-test`. <br>
This will generate a single executable in the current <br>
working directory along with several object files you can <br>
ignore.

## Clean:
To remove all the `.o` and executable files, run <br>
`$ make clean`. 

## Format:
To format all `.c` and `.h` files, execute `$ make format`.

## Running:
To run the program, `$ ./mathlib-test [-aebmrvnsh]`. <br>
Running with no options will return a help output <br>
describing each option. For convenience, here they are too,<br>

  -a   Runs all tests.<br>
  -e   Runs e test.<br>
  -b   Runs BBP pi test.<br>
  -m   Runs Madhava pi test.<br>
  -r   Runs Euler pi test.<br>
  -v   Runs Viete pi test.<br>
  -n   Runs Newton square root tests.<br>
  -s   Print verbose statistics.<br>
  -h   Display program synopsis and usage.<br>

None of the options have/require parameters. Invalid <br>
usage results in the help screen again.

