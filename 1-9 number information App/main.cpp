#include "NumberDatabase.h"
#include "QuizEngine.h"
#include "UI.h"
#include <iostream>
#include <memory>

void displayHelp() {
    UI::clearScreen();
    std::cout << UI::Color::CYAN << UI::Color::BOLD;
    std::cout << "╔═══════════════════════════════════════════════════════════════╗\n";
    std::cout << "║                         HELP GUIDE                            ║\n";
    std::cout << "╚═══════════════════════════════════════════════════════════════╝\n";
    std::cout << UI::Color::RESET << "\n";
    
    std::cout << UI::Color::BOLD << "📖 How to Use This App:\n" << UI::Color::RESET;
    std::cout << "\n1. " << UI::Color::GREEN << "Learn Mode:" << UI::Color::RESET << "\n";
    std::cout << "   - Choose option 1 from the main menu\n";
    std::cout << "   - Enter any number from 0 to 9\n";
    std::cout << "   - Discover amazing facts, properties, and fun information!\n";
    std::cout << "   - Learn about prime numbers, perfect numbers, and more!\n\n";
    
    std::cout << "2. " << UI::Color::GREEN << "Quiz Mode:" << UI::Color::RESET << "\n";
    std::cout << "   - Choose option 2 from the main menu\n";
    std::cout << "   - Answer questions about number properties\n";
    std::cout << "   - Test your knowledge and see your score!\n";
    std::cout << "   - Questions include: prime numbers, even/odd, and fun facts\n\n";
    
    std::cout << UI::Color::BOLD << "🎯 Learning Tips:\n" << UI::Color::RESET;
    std::cout << "   • " << UI::Color::YELLOW << "Prime numbers" << UI::Color::RESET 
              << " can only be divided by 1 and themselves (2, 3, 5, 7)\n";
    std::cout << "   • " << UI::Color::YELLOW << "Composite numbers" << UI::Color::RESET 
              << " can be divided by other numbers (4, 6, 8, 9)\n";
    std::cout << "   • " << UI::Color::YELLOW << "Perfect numbers" << UI::Color::RESET 
              << " equal the sum of their divisors (6 = 1+2+3)\n";
    std::cout << "   • " << UI::Color::YELLOW << "Fibonacci numbers" << UI::Color::RESET 
              << " appear in nature (0, 1, 1, 2, 3, 5, 8...)\n\n";
    
    std::cout << UI::Color::BOLD << "💡 Did You Know?\n" << UI::Color::RESET;
    std::cout << "   Numbers are everywhere in nature, art, and science!\n";
    std::cout << "   Learning about numbers helps you understand the world better.\n\n";
    
    UI::displaySeparator();
    UI::pause();
}

void learnMode(const NumberDatabase& database) {
    while (true) {
        UI::clearScreen();
        std::cout << UI::Color::CYAN << UI::Color::BOLD;
        std::cout << "📖 LEARN MODE - Discover Number Facts!\n" << UI::Color::RESET;
        UI::displaySeparator();
        
        std::cout << "Enter a number (0-9) to learn about it, or -1 to return to menu: ";
        int number = UI::getNumberInput("");
        
        if (number == -1) {
            break;
        }
        
        if (!database.isValidNumber(number)) {
            UI::displayError("Please enter a number between 0 and 9!");
            UI::pause();
            continue;
        }
        
        auto info = database.getNumberInfo(number);
        if (info) {
            UI::displayNumberInfo(*info);
            UI::pause();
        }
    }
}

void quizMode(QuizEngine& quizEngine) {
    UI::clearScreen();
    std::cout << UI::Color::CYAN << UI::Color::BOLD;
    std::cout << "🎯 QUIZ MODE - Test Your Knowledge!\n" << UI::Color::RESET;
    UI::displaySeparator();
    
    std::cout << "How many questions would you like? (1-20): ";
    int numQuestions = UI::getNumberInput("");
    
    if (numQuestions < 1 || numQuestions > 20) {
        UI::displayError("Please choose between 1 and 20 questions!");
        UI::pause();
        return;
    }
    
    quizEngine.resetStats();
    quizEngine.runQuiz(numQuestions);
    UI::pause();
}

int main() {
    // Initialize database and quiz engine
    NumberDatabase database;
    QuizEngine quizEngine(database);
    
    // Display welcome screen
    UI::displayWelcome();
    UI::pause();
    
    // Main application loop
    bool running = true;
    while (running) {
        UI::clearScreen();
        UI::displayWelcome();
        UI::displayMainMenu();
        
        int choice = UI::getMenuChoice();
        
        switch (choice) {
            case 1:
                learnMode(database);
                break;
                
            case 2:
                quizMode(quizEngine);
                break;
                
            case 3:
                displayHelp();
                break;
                
            case 4:
                UI::clearScreen();
                std::cout << UI::Color::GREEN << UI::Color::BOLD;
                std::cout << "\n🎓 Thank you for learning with us!\n";
                std::cout << "Keep exploring the wonderful world of numbers! 🔢\n";
                std::cout << "Goodbye! 👋\n\n" << UI::Color::RESET;
                running = false;
                break;
                
            default:
                UI::displayError("Invalid choice! Please select 1-4.");
                UI::pause();
                break;
        }
    }
    
    return 0;
}
