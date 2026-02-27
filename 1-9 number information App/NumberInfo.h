#ifndef NUMBERINFO_H
#define NUMBERINFO_H

#include <string>
#include <vector>

struct NumberInfo {
    int value;
    std::string name;
    std::string definition;
    std::string mathematicalProperties;
    std::vector<std::string> funFacts;
    std::string asciiArt;
    bool isPrime;
    bool isComposite;
    bool isPerfect;
    bool isFibonacci;
};

#endif // NUMBERINFO_H
