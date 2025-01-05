---
# Implied-Volatility-Surface

The **Implied Volatility Surface** project is a Python-based application for options modeling. While the backend calculations are relatively simple, they are implemented in C++ for demonstration purposes, showcasing scenarios where faster computation might be necessary. The module uses Pybind11 to integrate the C++ backend into Python.
---

## Setup Guide

### 1. Clone the Repository

Make sure to clone the repository using the `--recursive` option to include the Pybind11 submodule:

```bash
git clone --recursive https://github.com/pybind/cmake_example.git
```

### 2. Install Requirements

Install the Python dependencies listed in `requirements.txt`:

```bash
pip install -r requirements.txt
```

### 3. Build and Install the Module

You can choose one of the following methods to build and install the project:

#### Method 1: Using `setup.py`

```bash
python3 setup.py install
```

#### Method 2: Using `pip` (Preferred)

```bash
pip install .
```

#### Method 3: Testing locally, allows changes to your code without reinstalling the package.

```bash
pip install --editable .
```

### 4. Run the Application

Once the setup is complete, you can run the application:

```bash
python3 app.py
```

---

## Features

- Backend calculations are implemented in **C++** for enhanced performance and as a demonstration of Pybind11's capabilities.
- Easily build and install the project using standard Python tools (`pip`, `setup.py`).
- The application calculates various metrics for options pricing, including premiums, delta, gamma, theta, and more.

---

## Conclusions

1. **C++ Backend**:
   The calculations are implemented in C++ to demonstrate how computationally intensive tasks can benefit from high-performance languages, even when integrated into Python workflows.

2. **Pybind11 Integration**:
   Pybind11 is used to create bindings between Python and C++ for seamless interoperability.

3. **Dependencies**:
   Ensure all dependencies in `requirements.txt` are installed to avoid runtime issues.

---
