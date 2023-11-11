#include "mathlib.h"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

#define OPTIONS "aebmrvnsh"

char help[] = "\
SYNOPSIS\n\
   A test harness for the small numerical library.\n\
\n\
USAGE\n\
   ./mathlib-test [-aebmrvnsh]\n\
\n\
OPTIONS\n\
  -a   Runs all tests.\n\
  -e   Runs e test.\n\
  -b   Runs BBP pi test.\n\
  -m   Runs Madhava pi test.\n\
  -r   Runs Euler pi test.\n\
  -v   Runs Viete pi test.\n\
  -n   Runs Newton square root tests.\n\
  -s   Print verbose statistics.\n\
  -h   Display program synopsis and usage.\n\
";

// Calls all functions and prints their
// results along with the respective
// math.h value and the difference.
//
// Takes no parameters.
void print_all(void) {
    printf("e() = %.15f, M_E = %.15f, diff = %.15f\n", e(), M_E, absolute(M_E - e()));
    printf("pi_euler() = %.15f, M_PI = %.15f, diff = %.15f\n", pi_euler(), M_PI,
        absolute(M_PI - pi_euler()));
    printf("pi_bbp() = %.15f, M_PI = %.15f, diff = %.15f\n", pi_bbp(), M_PI,
        absolute(M_PI - pi_bbp()));
    printf("pi_madhava() = %.15f, M_PI = %.15f, diff = %.15f\n", pi_madhava(), M_PI,
        absolute(M_PI - pi_madhava()));
    printf("pi_viete() = %.15f, M_PI = %.15f, diff = %.15f\n", pi_viete(), M_PI,
        absolute(M_PI - pi_viete()));
    for (double i = 0.0; i < 10.0; i += 0.1) {
        printf("sqrt_newton(%lf) = %.15f, sqrt(%lf) = %.15f, diff = %.15f\n", i, sqrt_newton(i), i,
            sqrt(i), absolute(sqrt(i) - sqrt_newton(i)));
    }
}

// Exactly like print_all but also prints
// the number of iterations.
//
// No parameters required.
void print_all_v(void) {
    printf("e() = %.15f, M_E = %.15f, diff = %.15f\n", e(), M_E, absolute(M_E - e()));
    printf("e() terms = %d\n", e_terms());
    printf("pi_euler() = %.15f, M_PI = %.15f, diff = %.15f\n", pi_euler(), M_PI,
        absolute(M_PI - pi_euler()));
    printf("pi_euler() terms = %d\n", pi_euler_terms());
    printf("pi_bbp() = %.15f, M_PI = %.15f, diff = %.15f\n", pi_bbp(), M_PI,
        absolute(M_PI - pi_bbp()));
    printf("pi_bbp() terms = %d\n", pi_bbp_terms());
    printf("pi_madhava() = %.15f, M_PI = %.15f, diff = %.15f\n", pi_madhava(), M_PI,
        absolute(M_PI - pi_madhava()));
    printf("pi_madhava() terms = %d\n", pi_madhava_terms());
    printf("pi_viete() = %.15f, M_PI = %.15f, diff = %.15f\n", pi_viete(), M_PI,
        absolute(M_PI - pi_viete()));
    printf("pi_viete() terms = %d\n", pi_viete_factors());
    for (double i = 0.0; i < 10.0; i += 0.1) {
        printf("sqrt_newton(%lf) = %.15f, sqrt(%lf) = %.15f, diff = %.15f\n", i, sqrt_newton(i), i,
            sqrt(i), absolute(sqrt(i) - sqrt_newton(i)));
        printf("sqrt_newton() terms = %d\n", sqrt_newton_iters());
    }
}

// Main function that facillitates
// primary function of the program.
// Checks arguments passed and prints
// respective items.
//
// argc : argument counter
// argv : pointer to array of the
//        arguments passed
int main(int argc, char **argv) {
    // These are all flags for each
    // valid option.
    int opt = 0;
    bool a = false;
    bool b = false;
    bool E = false;
    bool m = false;
    bool r = false;
    bool v = false;
    bool n = false;
    bool s = false;
    bool h = false;
    bool no_op = true;
    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'a':
            a = true;
            no_op = false;
            break;
        case 'e':
            E = true;
            no_op = false;
            break;
        case 'b':
            b = true;
            no_op = false;
            break;
        case 'm':
            m = true;
            no_op = false;
            break;
        case 'r':
            r = true;
            no_op = false;
            break;
        case 'v':
            v = true;
            no_op = false;
            break;
        case 'n':
            n = true;
            no_op = false;
            break;
        case 's':
            s = true;
            //no_op = false;
            break;
        case 'h': h = true; break;
        default: printf("%s\n", help); break;
        }
    }
    // This long series of if-elseif's
    // checks the options used. There's a
    // certain heirarchy, so if a option is
    // passed multiple times it would only print
    // once for exmaple.
    if (h) {
        // If -h passed, regarless of any
        // other option, print help screen.
        printf("%s\n", help);
    } else if (s) {
        // -s option will print the count
        // as well.
        if (a) {
            print_all_v();
        } else {
            if (E) {
                printf("e() = %.15f, M_E = %.15f, diff = %.15f\n", e(), M_E, absolute(M_E - e()));
                printf("e() terms = %d\n", e_terms());
            }
            if (b) {
                printf("pi_bbp() = %.15f, M_PI = %.15f, diff = %.15f\n", pi_bbp(), M_PI,
                    absolute(M_PI - pi_bbp()));
                printf("pi_bbp() terms = %d\n", pi_bbp_terms());
            }
            if (m) {
                printf("pi_madhava() = %.15f, M_PI = %.15f, diff = %.15f\n", pi_madhava(), M_PI,
                    absolute(M_PI - pi_madhava()));
                printf("pi_madhava() terms = %d\n", pi_madhava_terms());
            }
            if (r) {
                printf("pi_euler() = %.15f, M_PI = %.15f, diff = %.15f\n", pi_euler(), M_PI,
                    absolute(M_PI - pi_euler()));
                printf("pi_euler() terms = %d\n", pi_euler_terms());
            }
            if (v) {
                printf("pi_viete() = %.15f, M_PI = %.15f, diff = %.15f\n", pi_viete(), M_PI,
                    absolute(M_PI - pi_viete()));
                printf("pi_viete() terms = %d\n", pi_viete_factors());
            }
            if (n) {
                for (double i = 0.0; i < 10.0; i += 0.1) {
                    printf("sqrt_newton(%lf) = %.15f, sqrt(%lf) = %.15f, diff = %.15f\n", i,
                        sqrt_newton(i), i, sqrt(i), absolute(sqrt(i) - sqrt_newton(i)));
                    printf("sqrt_newton() iters = %d\n", sqrt_newton_iters());
                }
            }
            // If only -s, print help screen/
            if (no_op) {
                printf("%s\n", help);
            }
        }
    } else {
        // Niether -s not -h activated.
        // Regular usage.
        if (a) {
            print_all();
        } else {
            if (E) {
                printf("e() = %.15f, M_E = %.15f, diff = %.15f\n", e(), M_E, absolute(M_E - e()));
            }
            if (b) {
                printf("pi_bbp() = %.15f, M_PI = %.15f, diff = %.15f\n", pi_bbp(), M_PI,
                    absolute(M_PI - pi_bbp()));
            }
            if (m) {
                printf("pi_madhava() = %.15f, M_PI = %.15f, diff = %.15f\n", pi_madhava(), M_PI,
                    absolute(M_PI - pi_madhava()));
            }
            if (r) {
                printf("pi_euler() = %.15f, M_PI = %.15f, diff = %.15f\n", pi_euler(), M_PI,
                    absolute(M_PI - pi_euler()));
            }
            if (v) {
                printf("pi_viete() = %.15f, M_PI = %.15f, diff = %.15f\n", pi_viete(), M_PI,
                    absolute(M_PI - pi_viete()));
            }
            if (n) {
                for (double i = 0.0; i < 10.0; i += 0.1) {
                    printf("sqrt_newton(%lf) = %.15f, sqrt(%lf) = %.15f, diff = %.15f\n", i,
                        sqrt_newton(i), i, sqrt(i), absolute(sqrt(i) - sqrt_newton(i)));
                }
            }
            // No options supplied at all.
            if (no_op) {
                printf("%s\n", help);
            }
        }
    }

    return 0;
}
