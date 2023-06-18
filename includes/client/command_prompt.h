#pragma once

#include <unordered_map>
#include <string>

#include "client/command.h"


namespace client {
    class CommandPrompt {
    public:
        CommandPrompt(bool& should_run) : 
            should_run_(should_run) {};

        CommandPrompt(bool& should_run, const char* prompt) :
            should_run_(should_run), prompt_(prompt) {};

        /// SUMARY:
        /// Run loop. This method blocks thread forever.
        void Run();

        /// SUMMARY:
        /// Set executor for given command name
        void SetCommand(const char* name, Command& command);

    private:
        std::unordered_map<std::string, Command*> commands_{};
        std::string user_input_ = "";
        const char* prompt_ = "->";
        bool& should_run_;
    };
}
