#pragma once 
#include <memory>
#include <vector>
#include <functional>

class SamplePointsGenerator 
{
    public:
    SamplePointsGenerator();

    virtual std::vector<double> generatePoints(double, double, int) = 0;
};

class LinearPointsGenerator : public SamplePointsGenerator
{
    public:
    LinearPointsGenerator();

    std::vector<double> generatePoints(double, double, int);
};

class RandomPointsGenerator : public SamplePointsGenerator
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
    std::unique_ptr<LinearPointsGenerator> generator;
    std::function<double(double)> function;
};

