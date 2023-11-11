#include "mathlib.h"

static int count;

// Cacluates e to value of EPSILON precision.
// Returns a double with the approximation.
//
// Takes no parameters.
double e(void) {
    // These first lines act as the first
    // iteration, calculating the k=0 term.
    count = 1;
    double sum = 1.0;
    double previous_term = 1.0;
    double current_term = 0;
    for (double k = 1.0; absolute(previous_term) > EPSILON; k += 1.0) {
        current_term = (1.0 / k) * previous_term;
        sum += current_term;
        previous_term = current_term;
        count += 1;
    }
    return sum;
}

// Simply returns the number of terms to complete
// above function.
// Returns count(# of terms)
//
// Precondition: e() must run first before e_terms
// returns any value other than 0.
int e_terms(void) {
    return count;
}
