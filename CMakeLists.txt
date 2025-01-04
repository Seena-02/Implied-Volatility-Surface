cmake_minimum_required(VERSION 3.4...3.18)
set(CMAKE_CXX_STANDARD 20)
project(implied-volatility-surface)

# Add libraries
add_library(BSModelOptions src/BSModelOptions.cpp)
add_library(MCModelOptions src/MCModelOptions.cpp)

# Add pybind11 submodule
add_subdirectory(pybind11)

# Link pybind11 module
pybind11_add_module(model_options src/Bindings.cpp)
target_compile_definitions(model_options PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})

# Link the BSModelOptions library to the pybind11 module
target_link_libraries(model_options PRIVATE BSModelOptions MCModelOptions)
target_compile_definitions(model_options PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})

