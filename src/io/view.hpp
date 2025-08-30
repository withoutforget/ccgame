#pragma once
#include <format>
#include <iostream>
#include <string>

#include "color.hpp"
class View {
public:
    void ouput(const std::string& text) { std::cout << text << std::endl; }
    void colored_output(ColorText text_color, const std::string& text) {
        std::cout << text_color;

        std::cout << text;

        std::cout << ColorText::DEFAULT << ColorBack::DEFAULT;
    }
    template <typename... Ts>
    void colored_output(ColorText text_color, std::string_view text, Ts&&... args) {
        std::cout << text_color;

        std::cout << std::vformat(text, std::make_format_args(args...));

        std::cout << ColorText::DEFAULT << ColorBack::DEFAULT;
    }
};
