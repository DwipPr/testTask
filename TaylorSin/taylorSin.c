#include "taylorSin.h"

static double GetDifferenceValue(const double x, const unsigned int n);
static unsigned char IsConditionMet(const double pastValue, const double eps);
static unsigned char GetSign(const unsigned int num);

double GetSinSeriesSum(const double x, const double eps)
{
    double pastValue = x;
    double seriesSum = pastValue;
    double curValue = 0;
    unsigned int num = 1;

    while (IsConditionMet(pastValue, eps))
    {
        curValue = pastValue * GetDifferenceValue(x, num);
        pastValue = curValue;
        seriesSum += GetSign(num++) ? curValue : -curValue;
    }

    return seriesSum;
}

static double GetDifferenceValue(const double x, const unsigned int n)
{
    double result = (x * x) / ((2 * n) * (2 * n + 1));
    return result;
}

static unsigned char IsConditionMet(const double pastValue, const double eps)
{
    unsigned char result = ((pastValue > eps) || (pastValue < -eps)) ? 1 : 0;
    return result;
}

static unsigned char GetSign(const unsigned int num)
{
    return (num % 2 == 0) ? 1 : 0;
}