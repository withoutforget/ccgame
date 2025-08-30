#pragma once
#include <charconv>
#include <iostream>
#include <limits>
#include <string>

#include "error.hpp"

class Controller {
public:
    std::string get_string(size_t min_size = 0,
                           size_t max_size = std::numeric_limits<size_t>::max()) {
        std::string result{};
        std::getline(std::cin, result);
        if (result.size() < min_size || result.size() > max_size) {
            throw invalid_input_error("Input string is too short or too long");
        }
        return result;
    }

    template <typename T = int>
    T get_numeric(T min_value = std::numeric_limits<T>::min(),
                  T max_value = std::numeric_limits<T>::max()) {
        std::string input{};
        std::getline(std::cin, input);

        T result{};

        auto err = std::from_chars(input.data(), input.data() + input.size(), result);

        if (err.ec != std::errc()) {
            throw invalid_input_error("Input should be a number");
        }

        if (result < min_value || result > max_value) {
            throw invalid_input_error("Input should be in range");
        }

        return result;
    }
};