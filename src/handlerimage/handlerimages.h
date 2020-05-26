#ifndef CONSOLE_HANDLER_IMAGES_HANDLERIMAGES_H
#define CONSOLE_HANDLER_IMAGES_HANDLERIMAGES_H

#include <string>
#include <vector>

#include "utils/defines.h"

namespace hi
{
/*!
 * @brief The class is console handler for image processing
 * @date 26.05.2020
 * @author Begaev_A
 */
class HandlerImages
{
protected:
    /*!
     * @brief Type of operation on the image
     */
    enum class Operation
    {
        OPR_EXIT,
    };

public:
    /*!
     *
     */
    HandlerImages();

    /*!
     *
     */
    ~HandlerImages();

    /*!
     * @brief Console message processing
     * @param msg[in] message from console
     */
    void process(const std::string &msg);

    /*!
     * @brief Check working process
     * @return true - handler is worked
     */
    bool isWorked();

protected:
    /*!
     *
     * @param msg
     * @return
     */
    std::pair<Operation, std::vector<std::string>> getOperations(const std::string &msg);

    static std::vector<std::string> split(const std::string &fullStr);

protected:
    bool m_isWorked; ///< Flag for checking work process


};
}

#endif // CONSOLE_HANDLER_IMAGES_HANDLERIMAGES_H
