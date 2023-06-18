#include "client/command_prompt.h"
#include "client/commands/command_exit.h"
#include "client/commands/command_send.h"
#include "core/net/client_socket.h"
#include "core/messenger.h"


int main() {
    bool should_run = true;
    
    core::net::ClientSocket socket{"127.0.0.1", "8089"};
    socket.Connect();
    core::Messenger messenger{socket};

    client::commands::CommandExit command_exit{should_run};
    client::commands::CommandSend command_send{messenger};
    
    client::CommandPrompt prompt{should_run};
    prompt.SetCommand("exit", command_exit);
    prompt.SetCommand("send", command_send);

    prompt.Run();
    return 0;
}
