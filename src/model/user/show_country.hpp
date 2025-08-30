#pragma once

#include "../model.hpp"

class ShowUserCountryModel : public Model {
public:
    void run(Context& context) override {
        Country& c = m_context.local_user().user_country;
        m_view.colored_output(ColorText::BRIGHT_GREEN, "Название страны: {}\n", c.name);
        m_view.colored_output(ColorText::BRIGHT_GREEN, "Население: {}\n", c.population);
        m_view.colored_output(ColorText::BRIGHT_GREEN, "Количество денег: {}\n", c.money_capital);
    }

public:
    using Model::Model;
};