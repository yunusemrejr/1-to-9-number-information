#include "QuizEngine.h"
#include "UI.h"
#include <iostream>
#include <algorithm>
#include <chrono>

QuizEngine::QuizEngine(const NumberDatabase& db) 
    : database(db), correctAnswers(0), totalQuestions(0) {
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    rng.seed(static_cast<unsigned int>(seed));
}

void QuizEngine::runQuiz(int numQuestions) {
    std::cout << UI::Color::CYAN << UI::Color::BOLD 
              << "\n🎯 QUIZ MODE - Test Your Knowledge!\n" 
              << UI::Color::RESET;
    UI::displaySeparator();
    
    std::uniform_int_distribution<int> dist(database.getMinNumber(), database.getMaxNumber());
    
    for (int i = 0; i < numQuestions; ++i) {
        int randomNum = dist(rng);
        auto info = database.getNumberInfo(randomNum);
        
        if (!info) continue;
        
        std::cout << UI::Color::YELLOW << "\nQuestion " << (i + 1) << " of " << numQuestions 
                  << UI::Color::RESET << "\n";
        
        // Generate quiz question types
        int questionType = dist(rng) % 3;
        
        switch (questionType) {
            case 0: {
                // Is it prime?
                std::cout << "Is " << randomNum << " a prime number? (1=Yes, 0=No): ";
                int answer = UI::getNumberInput("");
                totalQuestions++;
                
                if ((answer == 1 && info->isPrime) || (answer == 0 && !info->isPrime)) {
                    UI::displaySuccess("✓ Correct!");
                    correctAnswers++;
                } else {
                    UI::displayError("✗ Wrong! " + std::to_string(randomNum) + 
                                   (info->isPrime ? " IS prime." : " is NOT prime."));
                }
                break;
            }
            case 1: {
                // Is it even or odd?
                std::cout << "Is " << randomNum << " even or odd? (0=Even, 1=Odd): ";
                int answer = UI::getNumberInput("");
                totalQuestions++;
                
                bool isEven = (randomNum % 2 == 0);
                if ((answer == 0 && isEven) || (answer == 1 && !isEven)) {
                    UI::displaySuccess("✓ Correct!");
                    correctAnswers++;
                } else {
                    UI::displayError("✗ Wrong! " + std::to_string(randomNum) + 
                                   (isEven ? " is EVEN." : " is ODD."));
                }
                break;
            }
            case 2: {
                // Fun fact question
                if (!info->funFacts.empty()) {
                    std::cout << "True or False: " << info->funFacts[0] << "\n";
                    std::cout << "(1=True, 0=False): ";
                    int answer = UI::getNumberInput("");
                    totalQuestions++;
                    
                    if (answer == 1) {
                        UI::displaySuccess("✓ Correct! That's a true fact!");
                        correctAnswers++;
                    } else {
                        UI::displayError("✗ Actually, that's TRUE!");
                    }
                } else {
                    i--; // Retry with different question
                }
                break;
            }
        }
    }
    
    displayStats();
}

void QuizEngine::displayStats() const {
    UI::displaySeparator();
    std::cout << UI::Color::BOLD << "\n📊 QUIZ RESULTS\n" << UI::Color::RESET;
    std::cout << "Total Questions: " << totalQuestions << "\n";
    std::cout << UI::Color::GREEN << "Correct Answers: " << correctAnswers << UI::Color::RESET << "\n";
    std::cout << UI::Color::RED << "Wrong Answers: " << (totalQuestions - correctAnswers) 
              << UI::Color::RESET << "\n";
    
    if (totalQuestions > 0) {
        double percentage = (static_cast<double>(correctAnswers) / totalQuestions) * 100;
        std::cout << "\nScore: " << UI::Color::BOLD;
        
        if (percentage >= 80) {
            std::cout << UI::Color::GREEN << "🌟 " << percentage << "% - Excellent!" << UI::Color::RESET;
        } else if (percentage >= 60) {
            std::cout << UI::Color::YELLOW << "👍 " << percentage << "% - Good job!" << UI::Color::RESET;
        } else {
            std::cout << UI::Color::RED << "📚 " << percentage << "% - Keep practicing!" << UI::Color::RESET;
        }
        std::cout << "\n";
    }
    UI::displaySeparator();
}

void QuizEngine::resetStats() {
    correctAnswers = 0;
    totalQuestions = 0;
}
