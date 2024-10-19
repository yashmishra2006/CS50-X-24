#include <stdio.h>
#define pie 3.14159265358979323

int main(void)
{
    float x, y, z, x_sq, s = 0.0, t, prev;
    int i = 0;

    // Input value in radians
    printf("Enter value in radians - ");
    scanf("%f", &y);

    x = y;
    float half_pi = pie / 2;
    float two_pi = 2 * pie;

    // Normalize angle to [-pi, pi]
    if (x < -pie || x >= pie) {
        x = x - (int)(x / two_pi) * two_pi;
    }

    z = x;

    // Apply symmetry: sin(-x) = -sin(x)
    if (x < 0){
        x = -x;}

    // Apply symmetry: sin(pi - x) = sin(x) for x > pi/2
    if (x > half_pi)
    {x = pie - x;}

    x_sq = x * x;
    t = x;  // Initial term of the series
    printf("%f\n", t);
    prev = -(t * 2);  // Initialize prev with a value greater than t

    // Compute sine using Taylor series with ratio check
    while ((-(prev / t)) >= 1e-6)
    {
        s += t;
        prev = t;  // Update previous term
        t = t * ((-x_sq) / ((2 * i + 3) * (2 * i + 2)));
        i++;
    }

    s += t; // Add the last term
    if (z < 0){
    s = -s;}

    // Output the result
    printf("sin(%f) = %f\n", y, s);

    return 0;
}
