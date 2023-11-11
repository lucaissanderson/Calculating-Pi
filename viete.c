#include "mathlib.h"

static int count;

// Approximates pi using the
// Viete method.
// Returns double of approximation.
//
// No parameters.
double pi_viete(void) {
    // Initial term.
    count = 1;
    double previous_term = 0;
    double current_term = sqrt_newton(2.0) / 2.0;
    double temp;
    for (int k = 2; absolute(current_term - previous_term) > EPSILON; k += 1) {
        previous_term = current_term;
        temp = sqrt_newton(2.0);
        for (int i = 1; i < k; i += 1) {
            temp = sqrt_newton(2.0 + temp);
        }
        current_term = (temp / 2.0) * previous_term;
        count += 1;
    }
    return (2 / current_term);
}
// Returns int of terms calculated.
//
// No parameters.
int pi_viete_factors(void) {
    return count;
}
