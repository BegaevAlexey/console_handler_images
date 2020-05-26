#include <iostream>
#include <memory>

#include "handlerimage/handlerimages.h"

int main(int argc, char **argv)
{
    // init handler images
    std::unique_ptr<hi::HandlerImages> handler = std::make_unique<hi::HandlerImages>();

    while(true)
    {
        // read console massage
        std::string msg;
        std::getline(std::cin, msg);

        handler->process(msg);
        if(handler->isWorked())
        {
            break;
        }
    }

    std::cout << "\n\t***END PROGRAM***\n";
    return 0;
}
