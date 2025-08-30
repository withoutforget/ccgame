#include <charconv>
#include <exception>
#include <format>
#include <iostream>
#include <limits>

#include "io/color.hpp"
#include "io/controller.hpp"
#include "io/error.hpp"
#include "io/view.hpp"

#include "utils/context.hpp"
#include "model/model.hpp"

class SelectCountryModel : public Model {
protected:
    void run(Context& context) override {
        m_view.colored_output(ColorText::BRIGHT_BLUE, "Hello, world!\n");
        auto res = m_controller.get_string(2, 10);
        m_view.colored_output(ColorText::BRIGHT_MAGENTA, "You entered: {}\n", res);
    }

public:
    using Model::Model;
};

int main() {
    Context context{};
    View view{};
    Controller controller{};

    SelectCountryModel model{context, controller, view};
    model.execute(context);
}