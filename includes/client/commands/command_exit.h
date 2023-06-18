#pragma once

#include <vector>
#include <string>

#include "client/command.h"


namespace client::commands {
    class CommandExit : public client::Command {
    public:
        CommandExit(bool& should_run) : should_run_(should_run) {}
        
        bool TryExecute(std::vector<std::string> args) override {
            should_run_ = false;
            return true;
        }
   
    private:
        bool& should_run_;
    };
}
