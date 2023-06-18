#pragma once

#include <string>
#include <vector>


namespace client {
    class Command {
    public:
        virtual ~Command() {}

        /// SUMMARY:
        /// Try to execute command. Returns true if success, else false.
        /// You can call error_msg() to know that went wrong.
        virtual bool TryExecute(std::vector<std::string> args) { return false; }

        /// SUMMARY:
        /// Get error_msg_ which describes what went wrong.
        /// Returns "unknown" by default.
        std::string error_msg() { return error_msg_; };

    protected:
        std::string error_msg_ = "unknown";
    };
}
