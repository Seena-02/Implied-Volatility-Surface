#include "BSModelOptions.hpp"

BSModelOptions::BSModelOptions() {};

BSModelOptions::~BSModelOptions() {};

double BSModelOptions::GaussianCDF(double &x) const
{
    constexpr double a1 = 0.254829592;
    constexpr double a2 = -0.284496736;
    constexpr double a3 = 1.421413741;
    constexpr double a4 = -1.453152027;
    constexpr double a5 = 1.061405429;
    constexpr double p = 0.3275911;

    const int sign = (x >= 0) ? 1 : -1;
    x = fabs(x) / sqrt(2.0);

    const double t = 1.0 / (1.0 + p * x);
    const double y = 1.0 - (((((a5 * t + a4) * t) + a3) * t + a2) * t + a1) * t * exp(-x * x);

    return 0.5 * (1.0 + sign * y);
}

std::tuple<double, double, double, double> BSModelOptions::BlackScholesHelper(const double &S, const double &X, const double &r, const double &sigma, const double &t)
{
    double d1 = log(S / X) + (r + (pow(sigma, 2) / 2) * t) / (sigma * std::sqrt(t));

    double d2 = d1 - (sigma * std::sqrt(t));

    double N_d1 = GaussianCDF(d1);

    double N_d2 = GaussianCDF(d2);

    return std::make_tuple(d1, d2, N_d1, N_d2);
}

BSModelOptions::Contract BSModelOptions::CallBlackScholes(const double &S, const double &X, const double &r, const double &sigma, const double &t)
{
    const auto [d1, d2, N_d1, N_d2] = BlackScholesHelper(S, X, r, sigma, t);

    contract_ptr_->dte_ = t * days_in_calendar_year_;

    contract_ptr_->premium_ = (S * N_d1) - (X * std::exp(-r * t) * N_d2);

    contract_ptr_->delta_ = N_d1;

    contract_ptr_->gamma_ = N_d1 / (S * sigma * std::sqrt(t));

    contract_ptr_->theta_ = (-(S * N_d1 * sigma)) / (2 * std::sqrt(t)) - (r * X * std::exp(-r * t) * N_d2);

    contract_ptr_->vega_ = S * N_d1 * std::sqrt(t);

    contract_ptr_->rho_ = X * t * std::exp(-r * t) * N_d2;

    contract_ptr_->implied_volatility_ = sigma - ((contract_ptr_->premium_ - (contract_ptr_->premium_ - 0.01)) / (contract_ptr_->vega_));

    contract_ptr_->moneyness_ = S / X;

    contract_ptr_->intrinsic_value_ = std::max(S - X, 0.0);

    return *contract_ptr_;
}

BSModelOptions::Contract BSModelOptions::PutBlackScholes(const double &S, const double &X, const double &r, const double &sigma, const double &t)
{
    const auto [d1, d2, N_d1, N_d2] = BlackScholesHelper(S, X, r, sigma, t);

    contract_ptr_->dte_ = t * days_in_calendar_year_;

    contract_ptr_->premium_ = X * std::exp(-r * t) * (1 - N_d2) - S * (1 - N_d1);

    contract_ptr_->delta_ = N_d1 - 1;

    contract_ptr_->gamma_ = N_d1 / (S * sigma * std::sqrt(t));

    contract_ptr_->theta_ = (-(S * N_d1 * sigma)) / (2 * std::sqrt(t)) + (r * X * std::exp(-r * t) * (1 - N_d2));

    contract_ptr_->vega_ = S * N_d1 * std::sqrt(t);

    contract_ptr_->rho_ = -X * t * std::exp(-r * t) * (1 - N_d2);

    contract_ptr_->implied_volatility_ = sigma - (((contract_ptr_->premium_ - 0.01) - contract_ptr_->premium_) / (contract_ptr_->vega_));

    contract_ptr_->moneyness_ = S / X;

    contract_ptr_->intrinsic_value_ = std::max(X - S, 0.0);

    return *contract_ptr_;
}
