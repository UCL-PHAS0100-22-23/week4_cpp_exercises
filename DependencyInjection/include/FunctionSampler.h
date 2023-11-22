#pragma once 
#include <memory>
#include <vector>
#include <functional>


class LinearPointsGenerator
{
    public:
    LinearPointsGenerator();

    std::vector<double> generatePoints(double, double, int);
};

class RandomPointsGenerator
{
    public:
    RandomPointsGenerator();

    std::vector<double> generatePoints(double, double, int);
};

class FunctionSampler
{
    public:
    FunctionSampler(std::function<double(double)> f);

    std::vector<double> generateSamples(double, double, int n);

    private:
    LinearPointsGenerator generator;
    std::function<double(double)> function;
};

