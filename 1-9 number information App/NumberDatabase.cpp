#include "NumberDatabase.h"

NumberDatabase::NumberDatabase() {
    initializeDatabase();
}

void NumberDatabase::initializeDatabase() {
    // Number 0
    numbers[0] = {
        0, "Zero",
        "0 is a number, and the numerical digit used to represent that number in numerals. "
        "It fulfills a central role in mathematics as the additive identity of the integers, "
        "real numbers, and many other algebraic structures. As a digit, 0 is used as a placeholder in place value systems.",
        "Additive identity: 0 + n = n for any number n. Neither positive nor negative. The only number that is its own opposite.",
        {
            "Zero was invented independently by ancient civilizations including the Babylonians, Mayans, and Indians!",
            "In many programming languages, counting starts at 0 instead of 1.",
            "The temperature 0°C is the freezing point of water.",
            "A circle has 0 corners and 0 edges!"
        },
        R"(
   ___  
  / _ \ 
 | | | |
 | | | |
 | |_| |
  \___/ 
        )",
        false, false, false, true
    };

    // Number 1
    numbers[1] = {
        1, "One",
        "1 (one, also called unit, and unity) is a number and a numerical digit used to represent that number in numerals. "
        "It represents a single entity, the unit of counting or measurement. It is the first and smallest positive integer.",
        "Multiplicative identity: 1 × n = n for any number n. The first positive integer. Neither prime nor composite.",
        {
            "The number 1 is the most common leading digit in many real-world datasets (Benford's Law)!",
            "In binary (computer language), 1 represents 'on' or 'true'.",
            "You have 1 nose, 1 mouth, and 1 head!",
            "The Roman numeral for 1 is simply 'I'."
        },
        R"(
    __ 
   /_ |
    | |
    | |
    | |
    |_|
        )",
        false, false, false, true
    };

    // Number 2
    numbers[2] = {
        2, "Two",
        "2 (two) is a number, numeral and digit. It is the natural number following 1 and preceding 3. "
        "It is the smallest and only even prime number. Because it forms the basis of a duality, "
        "it has religious and spiritual significance in many cultures.",
        "The only even prime number. The base of the binary number system. First prime number.",
        {
            "Humans have 2 eyes, 2 ears, 2 hands, and 2 feet!",
            "A bicycle has 2 wheels (bi- means two).",
            "It takes 2 to tango - you need a pair to dance!",
            "In computers, everything is stored as 1s and 0s (binary = base 2)."
        },
        R"(
  ___  
 |__ \ 
    ) |
   / / 
  / /_ 
 |____|
        )",
        true, false, false, true
    };

    // Number 3
    numbers[3] = {
        3, "Three",
        "3 (three) is a number, numeral and digit. It is the natural number following 2 and preceding 4, "
        "and is the smallest odd prime number and the only prime preceding a square number. "
        "It has religious or cultural significance in many societies.",
        "The second prime number. The first odd prime. A triangular number (1+2=3). A Fibonacci number.",
        {
            "A triangle has 3 sides and 3 corners!",
            "Many stories follow the 'rule of three': three little pigs, three bears, three wishes!",
            "Traffic lights have 3 colors: red, yellow, and green.",
            "The primary colors are 3: red, blue, and yellow."
        },
        R"(
  ____  
 |___ \ 
   __) |
  |__ < 
  ___) |
 |____/ 
        )",
        true, false, false, true
    };

    // Number 4
    numbers[4] = {
        4, "Four",
        "4 (four) is a number, numeral and digit. It is the natural number following 3 and preceding 5. "
        "It is the smallest composite number, and is considered unlucky in many East Asian cultures.",
        "The smallest composite number. A square number (2×2=4). The number of sides in a square.",
        {
            "A square has 4 equal sides and 4 right angles!",
            "There are 4 seasons: spring, summer, fall, and winter.",
            "A car typically has 4 wheels.",
            "There are 4 cardinal directions: north, south, east, and west."
        },
        R"(
  _  _   
 | || |  
 | || |_ 
 |__   _|
    | |  
    |_|  
        )",
        false, true, false, false
    };

    // Number 5
    numbers[5] = {
        5, "Five",
        "5 (five) is a number, numeral and digit. It is the natural number following 4 and preceding 6, "
        "and is a prime number. It has attained significance throughout history in part because "
        "typical humans have five digits on each hand.",
        "A prime number. The third prime. The number of fingers on one hand. A Fibonacci number.",
        {
            "Humans have 5 fingers on each hand and 5 toes on each foot!",
            "A starfish typically has 5 arms.",
            "There are 5 Olympic rings representing the continents.",
            "A pentagon has 5 sides and 5 corners."
        },
        R"(
  _____ 
 | ____|
 | |__  
 |___ \ 
  ___) |
 |____/ 
        )",
        true, false, false, true
    };

    // Number 6
    numbers[6] = {
        6, "Six",
        "6 (six) is the natural number following 5 and preceding 7. "
        "It is a composite number and the smallest perfect number.",
        "The smallest perfect number (1+2+3=6, and 1×2×3=6). A triangular number. A highly composite number.",
        {
            "6 is a perfect number because 1+2+3=6 and these are all its divisors!",
            "Insects have 6 legs!",
            "A cube (like a dice) has 6 faces.",
            "Snowflakes have 6-fold symmetry - they have 6 points!"
        },
        R"(
   __   
  / /   
 | |_   
 | '_ \ 
 | (_) |
  \___/ 
        )",
        false, true, true, false
    };

    // Number 7
    numbers[7] = {
        7, "Seven",
        "7 (seven) is the natural number following 6 and preceding 8. "
        "It is the only prime number preceding a cube. It is often considered a lucky number in many cultures.",
        "A prime number. The fourth prime. A Mersenne prime exponent (2^7-1=127 is prime).",
        {
            "There are 7 days in a week!",
            "A rainbow has 7 colors: red, orange, yellow, green, blue, indigo, and violet.",
            "There are 7 continents on Earth.",
            "Many cultures consider 7 a lucky number!"
        },
        R"(
  ______ 
 |____  |
     / / 
    / /  
   / /   
  /_/    
        )",
        true, false, false, false
    };

    // Number 8
    numbers[8] = {
        8, "Eight",
        "8 (eight) is the natural number following 7 and preceding 9. "
        "It is a composite number and a cube number (2×2×2=8).",
        "A cube number (2³=8). A Fibonacci number. A power of 2 (2³). Has rotational symmetry.",
        {
            "An octopus has 8 arms (octo- means eight)!",
            "A spider has 8 legs.",
            "When you turn 8 on its side (∞), it becomes the infinity symbol!",
            "A stop sign has 8 sides - it's an octagon."
        },
        R"(
   ___  
  / _ \ 
 | (_) |
  > _ < 
 | (_) |
  \___/ 
        )",
        false, true, false, true
    };

    // Number 9
    numbers[9] = {
        9, "Nine",
        "9 (nine) is the natural number following 8 and preceding 10. "
        "It is a composite number and a perfect square (3×3=9).",
        "A perfect square (3²=9). The largest single-digit number. A Kaprekar number.",
        {
            "A cat is said to have 9 lives!",
            "There are 9 planets in our solar system if you count Pluto!",
            "A baseball team has 9 players on the field.",
            "Any number multiplied by 9 has digits that add up to 9 (or a multiple of 9)!"
        },
        R"(
   ___  
  / _ \ 
 | (_) |
  \__, |
    / / 
   /_/  
        )",
        false, true, false, false
    };
}

std::optional<NumberInfo> NumberDatabase::getNumberInfo(int num) const {
    auto it = numbers.find(num);
    if (it != numbers.end()) {
        return it->second;
    }
    return std::nullopt;
}

bool NumberDatabase::isValidNumber(int num) const {
    return numbers.find(num) != numbers.end();
}
