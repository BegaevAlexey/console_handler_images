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
        OPR_EXIT, ///< Exit from app
        OPR_WAR,  ///< Warning message
        OPR_LOAD, ///< Load new image
        OPR_SAVE, ///< Save image
        OPR_BLUR, ///< Blur image
        OPR_RSZ,  ///< Resize image
        OPR_HELP, ///< Show help page
        OPR_NONE, ///< Unknown operation
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
    bool isWorked() const;

protected:
    /*!
     *
     * @param msg[in] message from console
     * @return Operation type with arguments
     */
    static std::pair<Operation, std::vector<std::string>> getOperations(const std::string &msg);

    /*!
     * @brief Split string by space
     * @param fullStr[in] string for splitting
     * @return vector of strings
     */
    static std::vector<std::string> split(const std::string &fullStr);

    /*!
     * @brief Get type of operation from string
     * @param strOpr[in] String name of operation
     * @return operation type
     */
    static Operation getTypeOperation(const std::string &strOpr);

protected:
    bool m_isWorked; ///< Flag for checking work process


};
}

#endif // CONSOLE_HANDLER_IMAGES_HANDLERIMAGES_H
