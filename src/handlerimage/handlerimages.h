#ifndef CONSOLE_HANDLER_IMAGES_HANDLERIMAGES_H
#define CONSOLE_HANDLER_IMAGES_HANDLERIMAGES_H

#include <string>

namespace hi
{
/*!
 * @brief The class is console handler for image processing
 * @date 26.05.2020
 * @author Begaev_A
 */
class HandlerImages
{
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

private:
    bool m_isWorked; ///< Flag for checking work process


};
}

#endif // CONSOLE_HANDLER_IMAGES_HANDLERIMAGES_H
