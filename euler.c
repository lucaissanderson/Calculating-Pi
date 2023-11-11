#include "mathlib.h"

static int count;

// Approximates pi using Euler's method.
// Returns double of approximation.
//
// No parameters.
double pi_euler(void) {
    // First term. (k=1)
    double sum = 1.0;
    double previous_term = 1.0;
    count = 0;
    for (double k = 2.0; absolute(previous_term) > EPSILON; k += 1.0) {
        double current_term = (1 / (k * k));
        sum += current_term;
        previous_term = current_term;
        count += 1;
    }
    sum = (sqrt_newton(6.0 * sum));
    return sum;
}

// Returns number of terms
// calculated as type int.
//
// No parameters.
int pi_euler_terms(void) {
    return count;
}
