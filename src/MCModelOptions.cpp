#include "MCModelOptions.hpp"

MCModelOptions::MCModelOptions() {};

MCModelOptions::~MCModelOptions() {};

double MCModelOptions::GenerateGaussianNoise() const
{
    static std::mt19937 rng(std::random_device{}());
    static std::normal_distribution<> dist(0.0, 1.0);
    return dist(rng);
}

MCModelOptions::Contract MCModelOptions::CallMonteCarlo(const double &S, const double &X, const double &r, const double &sigma, const double &t)
{
    double payoff_sum = 0.0;

    for (unsigned int i = 0; i < num_simulations_; ++i)
    {
        double Z = GenerateGaussianNoise();
        double ST = S * exp((r - 0.5 * sigma * sigma) * t + sigma * sqrt(t) * Z);
        payoff_sum += std::max(ST - X, 0.0);
    }

    contract_ptr_->premium_ = (payoff_sum / num_simulations_) * exp(-r * t);

    return *contract_ptr_;
}

MCModelOptions::Contract MCModelOptions::PutMonteCarlo(const double &S, const double &X, const double &r, const double &sigma, const double &t)
{
    double payoff_sum = 0.0;

    for (unsigned int i = 0; i < num_simulations_; ++i)
    {
        double Z = GenerateGaussianNoise();
        double ST = S * exp((r - 0.5 * sigma * sigma) * t + sigma * sqrt(t) * Z);
        payoff_sum += std::max(X - ST, 0.0);
    }

    contract_ptr_->premium_ = (payoff_sum / num_simulations_) * exp(-r * t);

    return *contract_ptr_;
}