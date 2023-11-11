#include "mathlib.h"

static int count;

// Approximates pi to the precision of
// epsilon using the Madhava method.
// Returns double.
//
// Takes no parameters.
double pi_madhava(void) {
    // These lines before loop act as
    // the first term in the sum.
    // (k=0)
    count = 1;
    double sum = 1.0;
    double previous_term = 1.0;
    double current_term = 0.0;
    double temp;
    for (double k = 1.0; absolute(previous_term) > EPSILON; k += 1.0) {
        // temp and second for-loop used
        // to calculate powers of (-3).
        temp = 1.0;
        for (double i = 0.0; i < k; i += 1.0) {
            temp = (-3.0) * temp;
        }
        current_term = (1.0 / (temp * ((2.0 * k) + 1.0)));
        sum += current_term;
        // I acknoledge that both current AND
        // previous term variables aren't needed
        // but I think it makes the program a
        // little more clear.
        previous_term = current_term;
        count += 1;
    }
    return (sqrt_newton(12) * sum);
}

// Returns the number of terms calculated.
//
// Takes no parameters.
int pi_madhava_terms(void) {
    return count;
}
