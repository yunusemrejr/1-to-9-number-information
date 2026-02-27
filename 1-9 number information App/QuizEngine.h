#ifndef QUIZENGINE_H
#define QUIZENGINE_H

#include "NumberDatabase.h"
#include <random>

class QuizEngine {
private:
    const NumberDatabase& database;
    int correctAnswers;
    int totalQuestions;
    std::mt19937 rng;

public:
    explicit QuizEngine(const NumberDatabase& db);
    void runQuiz(int numQuestions);
    void displayStats() const;
    void resetStats();
};

#endif // QUIZENGINE_H
