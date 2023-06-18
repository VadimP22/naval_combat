#include "core/utils.h"

#include <vector>
#include <string>


namespace core {
    std::vector<std::string> SplitByChar(std::string& input, char ch) {
        std::vector<std::string> splitted{};
        
        auto separator = 0;
        for (int i = 0; i < input.length(); i++) {
            if (input[i] == ch) {
                splitted.push_back(
                    input.substr(separator, i - separator)        
                );
                separator = i + 1;
            }
        }
        auto last = input.substr(separator, input.length() - separator);
        if (last.length() != 0)
            splitted.push_back(last);

        return splitted;
    }
    
    
    std::string Serialize(std::vector<std::string>& msg) {
        std::string serialized{};

        for (auto str : msg)
            serialized.append(str + SEPARATOR);

        return serialized;
    }
}