#ifndef MCMODELOPTIONS_HPP
#define MCMODELOPTIONS_HPP

#include <memory>
#include <cmath>
#include <random>

class MCModelOptions
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
        double GenerateGaussianNoise() const;

        Contract CallMonteCarlo(const double &S, const double &X, const double &r, const double &sigma, const double &t);

        Contract PutMonteCarlo(const double &S, const double &X, const double &r, const double &sigma, const double &t);

    private:
        std::shared_ptr<Contract> contract_ptr_ = std::make_shared<Contract>();
        const unsigned int num_simulations_ = 10000U;
};

#endif MCMODELOPTIONS_HPP
