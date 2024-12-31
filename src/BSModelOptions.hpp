#ifndef BSMODELOPTIONS_HPP

#include <iostream>
#include <cmath>

class BSModelOptions
{
public:
    void GaussianCDF(const double &x);

private:
    struct Constract
    {
        double premium;
        int dte;
        double delta;
        double gamma;
        double theta;
        double vega;
        double rho;
        double implied_volatility;
        double instrinsic_value;
    };
};

#define BSMODELOPTIONS_HPP

#endif BSMODELOPTIONS_HPP