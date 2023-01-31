#include <iostream>
#include "FunctionSampler.h"

int main()
{
    FunctionSampler FS([](double x){return x*x;});

    auto samples = FS.generateSamples(0, 2, 10);
    for(auto x : samples)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;


    return 0;
}