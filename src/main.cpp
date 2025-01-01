#include "BSModelOptions.cpp"
#include <iostream>

int main(int argc, char *argv[])
{
    std::shared_ptr<BSModelOptions> bs_model_options_ptr = std::make_shared<BSModelOptions>();

    double S = 100.0;   // Initial stock price
    double X = 100.0;   // Strike price
    double r = 0.05;    // Risk-free rate
    double sigma = 0.2; // Volatility
    double t = 1;       // Time to maturity (in years)

    const auto call_contract = bs_model_options_ptr->CallBlackScholes(S, X, r, sigma, t);
    const auto put_contract = bs_model_options_ptr->PutBlackScholes(S, X, r, sigma, t);

    std::cout << "European Call Option Price: " << call_contract.premium_ << ", dte: " << call_contract.dte_ << ", delta: " << call_contract.delta_ << ", gamma: " << call_contract.gamma_ << ", theta: " << call_contract.theta_ << ", vega: " << call_contract.vega_ << ", rho: " << call_contract.rho_ << ", implied volatility: " << call_contract.implied_volatility_ << ", intrinsic value: " << call_contract.intrinsic_value_ << std::endl;
    std::cout << "European Put Option Price: " << put_contract.premium_ << ", dte: " << put_contract.dte_ << ", delta: " << put_contract.delta_ << ", gamma: " << put_contract.gamma_ << ", theta: " << put_contract.theta_ << ", vega: " << put_contract.vega_ << ", rho: " << put_contract.rho_ << ", implied volatility: " << put_contract.implied_volatility_ << ", intrinsic value: " << put_contract.intrinsic_value_ << std::endl;
}