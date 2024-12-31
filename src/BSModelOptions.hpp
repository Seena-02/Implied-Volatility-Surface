#ifndef BSMODELOPTIONS_HPP
#define BSMODELOPTIONS_HPP

#include <cmath>

class BSModelOptions
{
public:
    struct Contract
    {
        double premium_;
        int dte_;
        double delta_;
        double gamma_;
        double theta_;
        double vega_;
        double rho_;
        double implied_volatility_;
        double instrinsic_value_;
    };

    double GaussianCDF(double &x);

    Contract CallBlackScholes(const double &S, const double &X, const double &r, const double &sigma, const double &t);

    Contract PutBlackScholes(const double &S, const double &X, const double &r, const double &sigma, const double &t);

private:
};

#endif BSMODELOPTIONS_HPP