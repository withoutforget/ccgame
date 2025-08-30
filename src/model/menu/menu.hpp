#pragma once
#include <memory>

#include "../../io/controller.hpp"
#include "../../io/view.hpp"
#include "../../utils/context.hpp"
#include "../model.hpp"
#include "../user/create.hpp"
#include "../user/show_country.hpp"

class MenuModel : public Model {
private:
    std::unique_ptr<Model> m_create_user_model;
    std::unique_ptr<Model> m_show_user_country_model;

public:
    void run(Context& context) override {
        m_view.colored_output(ColorText::BRIGHT_MAGENTA, "Добро пожаловать в игру {}!\n",
                              context.get("game_title"));

        if (context.get("first_time") == "true") {
            m_view.colored_output(ColorText::BRIGHT_GREEN, "Вы первый раз здесь!\n");
            m_create_user_model->run(m_context);
            m_show_user_country_model->run(m_context);
            context.set("first_time", "false");
        }
    }

public:
    MenuModel(Context& context, Controller& controller, View& view)
        : Model(context, controller, view) {
        m_create_user_model = std::make_unique<CreateUserModel>(context, controller, view);
        m_show_user_country_model =
            std::make_unique<ShowUserCountryModel>(context, controller, view);
    }
};
