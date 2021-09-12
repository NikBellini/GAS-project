/*
 * This file is part of cg3lib: https://github.com/cg3hci/cg3lib
 * This Source Code Form is subject to the terms of the GNU GPL 3.0
 *
 * @author Alessandro Muntoni (muntoni.alessandro@gmail.com)
 */

#ifndef CG3_LOADERSAVER_H
#define CG3_LOADERSAVER_H

#include <string>
#include <list>
#include <memory>

class QWidget;

namespace cg3 {
namespace viewer {

/**
 * @brief The LoaderSaver class
 *
 * An utility class that manages load/save dialogs.
 *
 * It stores a set of supported extensions and the actual path that points
 * to the path where will be opened by default the dialogs.
 *
 * The actual path automatically changes whenever a file is opened/saved from a different
 * directory. This allows to open a dialog which starts from the last used path.
 */
class LoaderSaver
{
public:
	LoaderSaver(QWidget* parent, const std::string& initialPath= ".");
    LoaderSaver(const std::string& initialPath = ".");

    void addSupportedExtension(const std::string& extension);
    template <typename... Args>
    void addSupportedExtension(const std::string& ext1, Args... args);
    void resetSupportedExtension();

    void setActualPath(const std::string& path);
    const std::string& actualPath() const;

    std::string loadDialog(const std::string &windowName = "Load File");
    std::string saveDialog(const std::string& windowName = "Save File", std::string &selectedExtension = * std::unique_ptr<std::string>(new std::string("")) );
    std::string directoryDialog(const std::string& windowName = "Choose Directory");

private:
    std::string _actualPath;
    std::list<std::string> supportedExtensions;
	QWidget* parent;

    std::string listToExtensions(bool allFormats);
};

template<typename... Args>
void LoaderSaver::addSupportedExtension(const std::string &ext1, Args... args) {
    addSupportedExtension(ext1);
    addSupportedExtension(args...);
}

} //namespace cg3::viewer
} //namespace cg3

#ifndef CG3_STATIC
#define CG3_LOADERSAVER_CPP "loadersaver.cpp"
#include CG3_LOADERSAVER_CPP
#undef CG3_LOADERSAVER_CPP
#endif //CG3_STATIC

#endif // CG3_LOADERSAVER_H
