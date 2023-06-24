#pragma once

#include <vector>

#include "core/notifier.h"


namespace server {
    class Handler {
    public:
        void Handle(
                int id,
                std::vector<std::string>& msg,
                core::Notifier& notifier) {
            std::vector<std::string> response{};
            response.push_back("fuckubro");
            response.push_back(msg[0]);
            notifier.Notify(response);
        } 
    };
}
