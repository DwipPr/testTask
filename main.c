#include <stdio.h>
#include "taylorSin.h"

int main(void) 
{
    double x, eps;

    printf("Please enter angle value in radians: ");
    scanf("%lf", &x);
    printf("Please enter epsilon: ");
    scanf("%lf", &eps);
    
    double result = GetSinSeriesSum(x, eps);

    printf("sin(%.5lf) = %.10lf\n", x, result);

    return 0;
}
