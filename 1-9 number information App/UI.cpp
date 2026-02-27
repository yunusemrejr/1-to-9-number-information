#include "UI.h"
#include <iostream>
#include <limits>

namespace UI {

void clearScreen() {
    // ANSI escape code to clear screen
    std::cout << "\033[2J\033[1;1H";
}

void displayWelcome() {
    clearScreen();
    std::cout << Color::CYAN << Color::BOLD;
    std::cout << R"(
╔═══════════════════════════════════════════════════════════════╗
║                                                               ║
║        🔢  1-9 NUMBER INFORMATION APP FOR KIDS  🔢           ║
║                                                               ║
║              Learn Amazing Facts About Numbers!               ║
║                                                               ║
╚═══════════════════════════════════════════════════════════════╝
)" << Color::RESET << "\n";
    
    std::cout << Color::YELLOW << "Welcome, young mathematician! 🎓\n" << Color::RESET;
    std::cout << "Discover the wonderful world of numbers from 0 to 9!\n\n";
}

void displayMainMenu() {
    displaySeparator();
    std::cout << Color::BOLD << "📚 MAIN MENU\n" << Color::RESET;
    displaySeparator();
    std::cout << Color::GREEN << "1." << Color::RESET << " 📖 Learn about a number\n";
    std::cout << Color::GREEN << "2." << Color::RESET << " 🎯 Take a quiz\n";
    std::cout << Color::GREEN << "3." << Color::RESET << " ℹ️  Help\n";
    std::cout << Color::GREEN << "4." << Color::RESET << " 👋 Exit\n";
    displaySeparator();
}

void displayNumberInfo(const NumberInfo& info) {
    clearScreen();
    
    // Display ASCII art
    std::cout << Color::MAGENTA << Color::BOLD << info.asciiArt << Color::RESET << "\n";
    
    // Display number name
    std::cout << Color::CYAN << Color::BOLD << "═══ " << info.name 
              << " (" << info.value << ") ═══\n" << Color::RESET;
    displaySeparator();
    
    // Definition
    std::cout << Color::BOLD << "📝 Definition:\n" << Color::RESET;
    std::cout << info.definition << "\n\n";
    
    // Mathematical properties
    std::cout << Color::BOLD << "🔬 Mathematical Properties:\n" << Color::RESET;
    std::cout << info.mathematicalProperties << "\n\n";
    
    // Special properties badges
    std::cout << Color::BOLD << "🏆 Special Properties:\n" << Color::RESET;
    if (info.isPrime) {
        std::cout << Color::GREEN << "  ✓ Prime Number" << Color::RESET << "\n";
    }
    if (info.isComposite) {
        std::cout << Color::BLUE << "  ✓ Composite Number" << Color::RESET << "\n";
    }
    if (info.isPerfect) {
        std::cout << Color::MAGENTA << "  ✓ Perfect Number" << Color::RESET << "\n";
    }
    if (info.isFibonacci) {
        std::cout << Color::YELLOW << "  ✓ Fibonacci Number" << Color::RESET << "\n";
    }
    std::cout << "\n";
    
    // Fun facts
    std::cout << Color::BOLD << "🎉 Fun Facts:\n" << Color::RESET;
    for (size_t i = 0; i < info.funFacts.size(); ++i) {
        std::cout << Color::YELLOW << "  " << (i + 1) << ". " << Color::RESET 
                  << info.funFacts[i] << "\n";
    }
    
    displaySeparator();
}

void displayError(const std::string& message) {
    std::cout << Color::RED << "❌ " << message << Color::RESET << "\n";
}

void displaySuccess(const std::string& message) {
    std::cout << Color::GREEN << message << Color::RESET << "\n";
}

void displaySeparator() {
    std::cout << Color::BLUE << "───────────────────────────────────────────────────────────────\n" 
              << Color::RESET;
}

int getMenuChoice() {
    int choice;
    std::cout << Color::CYAN << "\nEnter your choice (1-4): " << Color::RESET;
    
    while (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        displayError("Invalid input! Please enter a number.");
        std::cout << Color::CYAN << "Enter your choice (1-4): " << Color::RESET;
    }
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return choice;
}

int getNumberInput(const std::string& prompt) {
    int number;
    if (!prompt.empty()) {
        std::cout << Color::CYAN << prompt << Color::RESET;
    }
    
    while (!(std::cin >> number)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        displayError("Invalid input! Please enter a number.");
        if (!prompt.empty()) {
            std::cout << Color::CYAN << prompt << Color::RESET;
        }
    }
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return number;
}

void pause() {
    std::cout << Color::YELLOW << "\nPress Enter to continue..." << Color::RESET;
    std::cin.get();
}

} // namespace UI
