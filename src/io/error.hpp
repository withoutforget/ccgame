#pragma once
#include <stdexcept>

struct invalid_input_error : public std::runtime_error {
    using std::runtime_error::runtime_error;
};
