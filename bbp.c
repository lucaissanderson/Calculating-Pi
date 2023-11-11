#include "mathlib.h"

static int count;

// Approximates pi using the
// Bailey-Borwein-Plouffe formula.
// Returns double of the sum.
//
// No parameters.
double pi_bbp(void) {
    // First term. (k=0)
    count = 1;
    double sum = 47.0 / 15.0;
    double previous_term = 47.0 / 15.0;
    double current_term = 0.0;
    double temp;
    for (double k = 1.0; absolute(previous_term) > EPSILON; k += 1.0) {
        // temp and second loop for
        // calculating powers of
        // (16^-1)
        temp = 1.0;
        for (double i = 0.0; i < k; i += 1.0) {
            temp = (1.0 / 16.0) * temp;
        }
        current_term
            = temp
              * ((k * (120 * k + 151) + 47) / (k * (k * (k * (512 * k + 1024) + 712) + 194) + 15));
        sum += current_term;
        previous_term = current_term;
        count += 1;
    }
    return sum;
}

// Returns number of term.
//
// No parameters.
int pi_bbp_terms(void) {
    return count;
}
