#ifndef NUMBERDATABASE_H
#define NUMBERDATABASE_H

#include "NumberInfo.h"
#include <map>
#include <optional>

class NumberDatabase {
private:
    std::map<int, NumberInfo> numbers;
    void initializeDatabase();

public:
    NumberDatabase();
    std::optional<NumberInfo> getNumberInfo(int num) const;
    bool isValidNumber(int num) const;
    int getMinNumber() const { return 0; }
    int getMaxNumber() const { return 9; }
};

#endif // NUMBERDATABASE_H
