#include "client/command_prompt.h"

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "config.h"
#include "core/utils.h"


template<typename K, typename V>
        bool CheckContains(std::unordered_map<K, V>& map, K key) {
    if (map.find(key) == map.end())
        return false;
 
    return true;
}
 


void client::CommandPrompt::Run() {
    while (should_run_) {
        std::cout << prompt_;
        std::getline(std::cin, user_input_);

        std::vector<std::string> args{};
        args = core::SplitByChar(user_input_, ' ');

        std::string command{};
        command = args.front();
        args.erase(args.begin());

        #ifdef DEBUG_PROMPT
            std::cout << "command: " << command << std::endl;
            for (auto& arg : args)
                std::cout << "arg: " << arg << std::endl;
        #endif

        if(CheckContains(commands_, command)) {
            bool success = commands_[command]->TryExecute(args);
            if (!success)
                std::cout << "Error during command execution" << std::endl;
        }
    }
}


void client::CommandPrompt::SetCommand(const char* name, Command &command) {
    commands_[name] = &command;
}
