import streamlit as st
import yfinance as yf
import pandas as pd
import numpy as np
from datetime import timedelta
from scipy.stats import norm
from scipy.optimize import brentq
from scipy.interpolate import griddata
import plotly.graph_objects as go
import build.model_options as mo



def sidebar():
      st.sidebar.header('Model Parameters')
      st.sidebar.write('Adjust the parameters for the Black-Scholes model.')

      stock = st.sidebar.text_input(
      "Select Stock Ticker Symbol",
      ("SPY")
      )

      risk_free_rate = st.sidebar.number_input(
      "Risk-Free Rate (e.g., 0.015 for 1.5%)",
      value=0.015,
      format="%.4f"
      )

      dividen_yield = st.sidebar.number_input(
      "Dividend Yield (e.g., 0.013 for 1.3%)",
      value = 0.013,
      format="%.4f"
      )

def app():
      st.title("Implied Volatility Surface")
      sidebar()

def main():
      app()
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

      print("European Call Option:")
      print(f"\tImplied Volatility:  {call_contract.implied_volatility}")
      print(f"\tMoneyness:  {call_contract.moneyness}")

      print("European Put Option:")
      print(f"\tImplied Volatility:  {put_contract.implied_volatility}")
      print(f"\tMoneyness:  {put_contract.moneyness}")

      # Print results for Black-Scholes
      #print("European Call Option:")
      #print(f"Premium: {call_contract.premium_}, DTE: {call_contract.dte_}, Delta: {call_contract.delta_}, Gamma: {call_contract.gamma_}, "
            #f"Theta: {call_contract.theta_}, Vega: {call_contract.vega_}, Rho: {call_contract.rho_}, "
            #f"Implied Volatility: {call_contract.implied_volatility_}, Intrinsic Value: {call_contract.intrinsic_value_}")

      #print("European Put Option:")
      #print(f"Premium: {put_contract.premium_}, DTE: {put_contract.dte_}, Delta: {put_contract.delta_}, Gamma: {put_contract.gamma_}, "
            #f"Theta: {put_contract.theta_}, Vega: {put_contract.vega_}, Rho: {put_contract.rho_}, "
            #f"Implied Volatility: {put_contract.implied_volatility_}, Intrinsic Value: {put_contract.intrinsic_value_}")


if __name__ == "__main__":
    main()