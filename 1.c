#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

int main()
{
    double alpha;

    printf("Enter alpha: ");
    scanf("%lf", &alpha);

    double z1 = cos(alpha) + sin(alpha) + cos(3 * alpha) + sin(3 * alpha);

    double z2 = 2 * sqrt(2) * cos(alpha) * sin(M_PI / 4 + 2 * alpha);

    printf("z1 = %lf\n", z1);
    printf("z2 = %lf\n", z2);

    return 0;
}