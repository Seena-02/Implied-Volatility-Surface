#ifndef BSMODELOPTIONS_HPP
#define BSMODELOPTIONS_HPP

#include <cmath>
#include <memory>
#include <algorithm>
#include <tuple>

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
        double intrinsic_value_;
    };

    double GaussianCDF(double &x);

    std::tuple<double, double, double, double> BlackScholesHelper(const double &S, const double &X, const double &r, const double &sigma, const double &t);

    Contract CallBlackScholes(const double &S, const double &X, const double &r, const double &sigma, const double &t);

    Contract PutBlackScholes(const double &S, const double &X, const double &r, const double &sigma, const double &t);

private:
    std::shared_ptr<Contract> contract_ptr_ = std::make_shared<Contract>();
    const double days_in_calendar_year_ = 365.2425;
};
#endif BSMODELOPTIONS_HPP
