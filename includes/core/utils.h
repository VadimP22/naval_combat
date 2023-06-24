#pragma once

#include <vector>
#include <string>

#define SEPARATOR '/'


namespace core {
    const std::vector<char> kLetters = {
        'a', 'b', 'c', 'd', 'e',
        'f', 'g', 'h', 'i', 'k',
    };

    int letterToNum(char l);

    std::vector<std::string> SplitByChar(
        std::string& input, char ch);

    std::string Serialize(
        std::vector<std::string>& msg);
}
