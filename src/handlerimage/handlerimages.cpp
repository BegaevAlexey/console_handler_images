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
    auto opertions = HandlerImages::getOperations(msg);

    // handling operation with arguments
    this->handlingOperation(opertions);
}

bool hi::HandlerImages::isWorked() const
{
    return m_isWorked;
}

std::pair<hi::HandlerImages::Operation, std::vector<std::string>> hi::HandlerImages::getOperations(const std::string& msg)
{
    // split message
    auto strings = HandlerImages::split(msg);

    if(strings.empty())
    {
        return {Operation::OPR_WAR, {"String of arguments is empty"}};
    }

    // operation type
    auto operType = HandlerImages::getTypeOperation(strings[0]);

    std::vector<std::string> args(strings.begin() + 1, strings.end());
    return {operType, args};
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

hi::HandlerImages::Operation hi::HandlerImages::getTypeOperation(const std::string& strOpr)
{
    if((strOpr == "load") || (strOpr == "ld"))
    {
        return Operation::OPR_LOAD;
    }

    if((strOpr == "store") || (strOpr == "s"))
    {
        return Operation::OPR_SAVE;
    }

    if(strOpr == "blur")
    {
        return Operation::OPR_BLUR;
    }

    if(strOpr == "resize")
    {
        return Operation::OPR_RSZ;
    }

    if((strOpr == "help") || (strOpr == "h"))
    {
        return Operation::OPR_HELP;
    }

    if((strOpr == "exit") || (strOpr == "quit")|| (strOpr == "q"))
    {
        return Operation::OPR_EXIT;
    }

    return Operation::OPR_NONE;
}

void hi::HandlerImages::handlingOperation(const std::pair<Operation, std::vector<std::string>>& opertions)
{
    switch(opertions.first)
    {
        case Operation::OPR_EXIT :
            LOG_INFO("PROGRAM EXIT");
            m_isWorked = false;
            break;
        case Operation::OPR_WAR :
            LOG_WARNING(opertions.second[0]);
            break;
        case Operation::OPR_LOAD :
            this->loadImage(opertions.second);
            break;
        case Operation::OPR_SAVE :
//            this->saveImage(opertions.second);
            break;
        case Operation::OPR_BLUR :
//            this->blurImage(opertions.second);
            break;
        case Operation::OPR_RSZ :
//            this->resizeImage(opertions.second);
            break;
        case Operation::OPR_HELP :
//            this->showHelp();
            break;
        case Operation::OPR_NONE :
            LOG_WARNING("Unknown operation!");
            break;
    }
}

void hi::HandlerImages::loadImage(const std::vector<std::string>& args)
{
    if(!HandlerImages::checkCountArgs(args, 2))
    {
        return;
    }

    m_images[args[0]] = cv::imread(args[1]);
    if (m_images[args[0]].empty())
    {
        LOG_WARNING("Image " << args[1] << " was not loaded!")
    }
}

bool hi::HandlerImages::checkCountArgs(const std::vector<std::string>& args, int count)
{
    if(args.size() < count)
    {
        LOG_WARNING("Not enough argumets!");
        return false;
    }

    if(args.size() < count)
    {
        LOG_WARNING("Not enough argumets!");
        return false;
    }

    return true;
}
