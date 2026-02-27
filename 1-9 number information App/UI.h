#ifndef UI_H
#define UI_H

#include "NumberInfo.h"
#include <string>

namespace UI {
    // ANSI color codes
    namespace Color {
        const std::string RESET = "\033[0m";
        const std::string RED = "\033[31m";
        const std::string GREEN = "\033[32m";
        const std::string YELLOW = "\033[33m";
        const std::string BLUE = "\033[34m";
        const std::string MAGENTA = "\033[35m";
        const std::string CYAN = "\033[36m";
        const std::string BOLD = "\033[1m";
    }

    void clearScreen();
    void displayWelcome();
    void displayMainMenu();
    void displayNumberInfo(const NumberInfo& info);
    void displayError(const std::string& message);
    void displaySuccess(const std::string& message);
    void displaySeparator();
    int getMenuChoice();
    int getNumberInput(const std::string& prompt);
    void pause();
}

#endif // UI_H
