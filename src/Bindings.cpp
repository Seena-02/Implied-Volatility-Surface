#include <pybind11/pybind11.h>
#include <memory>
#include "BSModelOptions.hpp"

namespace py = pybind11;

PYBIND11_MODULE(bsmodule, m)
{
    py::class_<BSModelOptions::Contract>(m, "Contract")
        .def(py::init<>())
        .def_readwrite("premium_", &BSModelOptions::Contract::premium_)
        .def_readwrite("dte_", &BSModelOptions::Contract::dte_)
        .def_readwrite("delta_", &BSModelOptions::Contract::delta_)
        .def_readwrite("gamma_", &BSModelOptions::Contract::gamma_)
        .def_readwrite("theta_", &BSModelOptions::Contract::theta_)
        .def_readwrite("vega_", &BSModelOptions::Contract::vega_)
        .def_readwrite("rho_", &BSModelOptions::Contract::rho_)
        .def_readwrite("implied_volatility_", &BSModelOptions::Contract::implied_volatility_)
        .def_readwrite("intrinsic_value_", &BSModelOptions::Contract::intrinsic_value_);

    py::class_<BSModelOptions>(m, "BSModelOptions")
        .def(py::init<>())
        .def("GaussianCDF", &BSModelOptions::GaussianCDF)
        .def("BlackScholesHelper", &BSModelOptions::BlackScholesHelper)
        .def("CallBlackScholes", &BSModelOptions::CallBlackScholes)
        .def("PutBlackScholes", &BSModelOptions::PutBlackScholes);
}
