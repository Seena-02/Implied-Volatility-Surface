# cmake_minimum_required(VERSION 3.5.0)
# set(CMAKE_CXX_STANDARD 20)
# project(implied-volatility-surface VERSION 0.1.0 LANGUAGES C CXX)

# add_library(BSModelOptions src/BSModelOptions.cpp)
# add_library(MCModelOptions src/MCModelOptions.cpp)

# # Link pybind11 and the necessary libraries
# add_executable(implied-volatility-surface src/main.cpp)

# add_subdirectory(external/pybind11)

# # Link your executable to the libraries you may need
# target_link_libraries(implied-volatility-surface BSModelOptions MCModelOptions)


cmake_minimum_required(VERSION 3.5.0)
set(CMAKE_CXX_STANDARD 20)
project(implied-volatility-surface VERSION 0.1.0 LANGUAGES C CXX)

# Add libraries
add_library(BSModelOptions src/BSModelOptions.cpp)
add_library(MCModelOptions src/MCModelOptions.cpp)

# Add pybind11 submodule
add_subdirectory(pybind11)

# Create the executable
#add_executable(implied-volatility-surface-exe src/main.cpp)
#target_link_libraries(implied-volatility-surface-exe BSModelOptions MCModelOptions)

# Link pybind11 module
pybind11_add_module(implied_volatility_surface_py src/Bindings.cpp)
target_compile_definitions(implied_volatility_surface_py PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})

