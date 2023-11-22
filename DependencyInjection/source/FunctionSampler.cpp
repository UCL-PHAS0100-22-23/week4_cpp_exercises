#include "FunctionSampler.h"
#include <random>

LinearPointsGenerator::LinearPointsGenerator(){}
RandomPointsGenerator::RandomPointsGenerator(){}

std::vector<double> LinearPointsGenerator::generatePoints(double a, double b, int n)
{
    std::vector<double> p;
    double dx = (b-a) / (n-1);
    for(int i = 0; i < n; i++)
    {
        p.push_back(a + dx*i);        
    }
    return p;
}

std::vector<double> RandomPointsGenerator::generatePoints(double a, double b, int n)
{
    static std::mt19937_64 rng;
    std::uniform_real_distribution<double> uniformDist(a, b);
    std::vector<double> p;
    for(int i = 0; i < n; i++)
    {
        p.push_back(uniformDist(rng));
    }
    return p;
}

FunctionSampler::FunctionSampler(std::function<double(double)> f) : function(f)
{
    generator = LinearPointsGenerator();
}

std::vector<double> FunctionSampler::generateSamples(double a, double b, int n)
{
    std::vector<double> vec = generator.generatePoints(a, b, n);
    for(auto &v : vec)
    {   
        v = function(v);
    }
    return vec;
}