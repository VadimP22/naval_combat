#pragma once

#include <vector>
#include <string>

#define SEPARATOR '/'


namespace core {
    std::vector<std::string> SplitByChar(
        std::string& input, char ch);

    std::string Serialize(
        std::vector<std::string>& msg);
}
