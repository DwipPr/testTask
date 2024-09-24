#include <stdio.h>

static double GetDifferenceValue(const double x, const unsigned int n);
static unsigned char ConditionIsMet(const double pastValue, const double eps);
static double GetSinSeriesSum(const double x, const double eps);

static double GetDifferenceValue(const double x, const unsigned int n)
{
    double result = (x * x) / ((2 * n) * (2 * n + 1));
    return result;
}

static unsigned char ConditionIsMet(const double pastValue, const double eps)
{
    unsigned char result = ((pastValue > eps) || (pastValue < -eps)) ? 1 : 0;
    return result;
}

static short int GetSign(const unsigned int num)
{
    short int result = (num % 2) ? 1 : -1;
    return result;
}

static double GetSinSeriesSum(const double x, const double eps)
{
    double pastValue = x;
    double seriesSum = pastValue;
    unsigned int num = 1;

    double curValue = 0;
    

    while (ConditionIsMet(pastValue, eps))
    {
        curValue = pastValue * GetDifferenceValue(x, num);
        pastValue = curValue;
        seriesSum += curValue * GetSign(num);
        num++;
    }

    return seriesSum;
}

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
