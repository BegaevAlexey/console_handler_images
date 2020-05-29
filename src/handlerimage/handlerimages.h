#ifndef CONSOLE_HANDLER_IMAGES_HANDLERIMAGES_H
#define CONSOLE_HANDLER_IMAGES_HANDLERIMAGES_H

#include <string>
#include <vector>
#include <map>
#include <opencv2/opencv.hpp>

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
     * @param strOpr[in] string name of operation
     * @return operation type
     */
    static Operation getTypeOperation(const std::string &strOpr);

    /*!
     * @brief Handling operation with its argumets
     * @param operations[in] operation type with arguments
     */
    void handlingOperation(const std::pair<Operation, std::vector<std::string>> &opertions);

    /*!
     * Loads an image from a file.
     * @param args[in] args[0] - name image in app, args[1] - path to image
     */
    void loadImage(const std::vector<std::string> &args);

    /*!
     * @brief Check count of arguments.
     * @param args[in] count of arguments
     * @param count[in] right count
     * @return false - if args.size != count and send warnign message
     */
    static bool checkCountArgs(const std::vector<std::string> &args, int count);

    /*!
     * Write image to a file
     * @param args[in] args[0] - name image in app, args[1] - path to image
     */
    void saveImage(const std::vector<std::string> &args);

    /*!
     * Write image to a file
     * @param args[in] args[0] - name image stc, args[1] - image dst, args[2] - size
     */
    void blurImage(const std::vector<std::string> &args);

protected:
    bool m_isWorked; ///< Flag for checking work process
    std::map<const std::string, cv::Mat> m_images; ///< Map with name images and opencv images


};
}

#endif // CONSOLE_HANDLER_IMAGES_HANDLERIMAGES_H
