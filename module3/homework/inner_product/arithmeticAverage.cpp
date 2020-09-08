#include "arithmeticAverage.hpp"
#include <functional>
#include <numeric>
#include <iostream>
#include <math.h>

double ArithmeticAverage(const std::vector<int>& first, const std::vector<int>& second)
{
    if (first.size() != second.size())
        return 0;
    double result = std::inner_product(first.begin(), first.end(), second.begin(), 0, std::plus<>(), std::plus<>());
    return result / (first.size() * 2.0);
}

double Distance(const std::vector<int>& first, const std::vector<int>& second)
{
    double result = sqrt(std::inner_product(second.begin(), second.end(), first.begin(), 0,
        std::plus<>(), [](const double& a, const double& b) { return pow(a - b, 2); }));
    return result;
}
