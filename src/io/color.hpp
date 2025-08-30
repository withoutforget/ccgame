#pragma once
#include <iostream>

enum class ColorText {
    DEFAULT = 0,
    BRIGHT_BLACK = 90,
    BRIGHT_RED = 91,
    BRIGHT_GREEN = 92,
    BRIGHT_YELLOW = 93,
    BRIGHT_BLUE = 94,
    BRIGHT_MAGENTA = 95,
    BRIGHT_CYAN = 96,
    BRIGHT_WHITE = 97
};

enum class ColorBack {
    DEFAULT = 0,
    DARK_BLACK = 40,
    DARK_RED = 41,
    DARK_GREEN = 42,
    DARK_YELLOW = 43,
    DARK_BLUE = 44,
    DARK_MAGENTA = 45,
    DARK_CYAN = 46,
    DARK_WHITE = 47,
};

std::ostream& operator<<(std::ostream& os, ColorText color) {
    return os << "\033[" << static_cast<int>(color) << "m";
}
std::ostream& operator<<(std::ostream& os, ColorBack color) {
    return os << "\033[" << static_cast<int>(color) << "m";
}