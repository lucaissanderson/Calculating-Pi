#include "mathlib.h"

static int count;

// Begin derived code
// Dervied from Darrel Long in the
// portable.py program from resources.

// Returns a double as the result of
// computing a square root on some double.
//
// x: A double to be square-rooted.
double sqrt_newton(double x) {
    count = 0;
    double z = 0.0;
    double y = 1.0;
    while (absolute(y - z) > EPSILON) {
        z = y;
        y = 0.5 * (z + x / z);
        count += 1;
    }
    return y;
}

// End derived code

// Returns the terms computed.
//
// No parameters.
int sqrt_newton_iters(void) {
    return count;
}
