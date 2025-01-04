import build.model_options as mo

# Create an instance of BSModelOptions
bs_model_options = mo.BSModelOptions()

# Input parameters
S = 100.0  # Initial stock price
X = 100.0  # Strike price
r = 0.05   # Risk-free rate
sigma = 0.2  # Volatility
t = 1       # Time to maturity (in years)

# Call Black-Scholes calculations
call_contract = bs_model_options.CallBlackScholes(S, X, r, sigma, t)
put_contract = bs_model_options.PutBlackScholes(S, X, r, sigma, t)

# Print results for Black-Scholes
print("European Call Option:")
print(f"Premium: {call_contract.premium_}, DTE: {call_contract.dte_}, Delta: {call_contract.delta_}, Gamma: {call_contract.gamma_}, "
      f"Theta: {call_contract.theta_}, Vega: {call_contract.vega_}, Rho: {call_contract.rho_}, "
      f"Implied Volatility: {call_contract.implied_volatility_}, Intrinsic Value: {call_contract.intrinsic_value_}")

print("European Put Option:")
print(f"Premium: {put_contract.premium_}, DTE: {put_contract.dte_}, Delta: {put_contract.delta_}, Gamma: {put_contract.gamma_}, "
      f"Theta: {put_contract.theta_}, Vega: {put_contract.vega_}, Rho: {put_contract.rho_}, "
      f"Implied Volatility: {put_contract.implied_volatility_}, Intrinsic Value: {put_contract.intrinsic_value_}")
