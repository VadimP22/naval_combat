#pragma once

#include <string>
#include <vector>

#include "client/command.h"
#include "core/messenger.h"


namespace client::commands {
    class CommandSend : public client::Command {
    public:
        CommandSend(core::Messenger& messenger) : messenger_(messenger) {}
        virtual ~CommandSend() {}

        bool TryExecute(std::vector<std::string> args) override {
            auto response = messenger_.Request(args);

            if(response.size() == 0)
                return false;

            return true;
        }  

    private:
        core::Messenger& messenger_;
    };
}
