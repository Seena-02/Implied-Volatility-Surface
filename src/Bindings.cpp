#include <pybind11/pybind11.h>
#include "BSModelOptions.hpp"

namespace py = pybind11;

PYBIND11_MODULE(model_options, m) {  // Make sure this matches the name of your .so file
    py::class_<BSModelOptions::Contract>(m, "Contract")
        .def(py::init<>())
        .def_readwrite("premium", &BSModelOptions::Contract::premium_)
        .def_readwrite("dte", &BSModelOptions::Contract::dte_)
        .def_readwrite("delta", &BSModelOptions::Contract::delta_)
        .def_readwrite("gamma", &BSModelOptions::Contract::gamma_)
        .def_readwrite("theta", &BSModelOptions::Contract::theta_)
        .def_readwrite("vega", &BSModelOptions::Contract::vega_)
        .def_readwrite("rho", &BSModelOptions::Contract::rho_)
        .def_readwrite("implied_volatility", &BSModelOptions::Contract::implied_volatility_)
        .def_readwrite("intrinsic_value", &BSModelOptions::Contract::intrinsic_value_)
        .def_readwrite("moneyness", &BSModelOptions::Contract::moneyness_);

    py::class_<BSModelOptions>(m, "BSModelOptions")
        .def(py::init<>())
        .def("GaussianCDF", &BSModelOptions::GaussianCDF)
        .def("BlackScholesHelper", &BSModelOptions::BlackScholesHelper)
        .def("CallBlackScholes", &BSModelOptions::CallBlackScholes)
        .def("PutBlackScholes", &BSModelOptions::PutBlackScholes);
}
