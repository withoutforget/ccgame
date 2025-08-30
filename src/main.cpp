#include "io/controller.hpp"
#include "io/error.hpp"
#include "model/menu/menu.hpp"

int main() {
    Context context;
    context.set("game_title", "CCGame");
    context.set("first_time", "true");

    Controller controller;
    View view;
    MenuModel menu_model(context, controller, view);
    menu_model.execute(context);
}