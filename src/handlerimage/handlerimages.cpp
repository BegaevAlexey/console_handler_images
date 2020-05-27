#include "handlerimages.h"

hi::HandlerImages::HandlerImages()
                  : m_isWorked(true)
{
    LOG_INFO("Handler was inited successfully!");
}

hi::HandlerImages::~HandlerImages()
{
    LOG_INFO("Handler was destroyed!");
}

void hi::HandlerImages::process(const std::string& msg)
{
    // get type of operation with arguments of operation
    auto opertions = this->getOperations(msg);

    // handling operation with arguments
}

bool hi::HandlerImages::isWorked()
{
    return m_isWorked;
}

std::pair<hi::HandlerImages::Operation, std::vector<std::string>> hi::HandlerImages::getOperations(const std::string& msg)
{
    // split message
    auto strings = HandlerImages::split(msg);

    // get operation


    return std::pair<Operation, std::vector<std::string>>();
}

std::vector<std::string> hi::HandlerImages::split(const std::string &fullStr)
{
    std::vector<std::string> splittedString;
    int startIndex = 0;
    int endIndex = 0;
    while( (endIndex = fullStr.find(" ", startIndex)) < fullStr.size() )
    {
        std::string val = fullStr.substr(startIndex, endIndex - startIndex);
        if(!val.empty())
        {
            splittedString.push_back(val);
        }
        startIndex = endIndex + 1;
    }
    if(startIndex < fullStr.size())
    {
        std::string val = fullStr.substr(startIndex);
        if(!val.empty())
        {
            splittedString.push_back(val);
        }
    }
    return splittedString;
}
