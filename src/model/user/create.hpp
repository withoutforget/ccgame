#pragma once

#include "../../utils/context.hpp"
#include "../model.hpp"

class CreateUserModel : public Model {
public:
    void run(Context& context) override {
        m_view.colored_output(ColorText::BRIGHT_MAGENTA, "Введите название страны: ");
        std::string name = m_controller.get_string(3, 50);
        m_view.colored_output(ColorText::BRIGHT_MAGENTA, "Введите население страны: ");
        size_t population = m_controller.get_numeric<size_t>(1'000, 1'000'000'000ull);

        Country& c = m_context.local_user().user_country;
        c.name = name;
        c.population = population;
        c.money_capital = population * 1000;

        m_view.colored_output(ColorText::BRIGHT_GREEN, "Страна создана!\n");
    }

public:
    using Model::Model;
};