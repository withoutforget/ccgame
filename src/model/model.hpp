#pragma once

#include <stdexcept>

#include "../io/controller.hpp"
#include "../io/view.hpp"
#include "../utils/context.hpp"

class Model {
protected:
    Controller& m_controller;
    View& m_view;
    Context& m_context;

public:
    virtual void run(Context& context) = 0;

public:
    Model(Context& context, Controller& controller, View& view)
        : m_context(context), m_controller(controller), m_view(view) {}

    virtual void execute(Context& context) {
        try {
            run(context);
        } catch (std::exception& e) {
            m_view.colored_output(ColorText::BRIGHT_RED, "Unhandled exception ({})\n", e.what());
            throw;

        } catch (...) {
            m_view.colored_output(ColorText::BRIGHT_RED, "Unhandled exception\n");
            throw;
        }
    };
};