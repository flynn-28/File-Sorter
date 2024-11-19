#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

void createDir(const std::string& dir) {
    if (!fs::exists(dir)) {
        fs::create_directory(dir);
    }
}

void organize(const std::string& path) {
    if (!fs::exists(path) || !fs::is_directory(path)) {
        std::cerr << "Invalid path: " << path << std::endl;
        return;
    }

    for (const auto& entry : fs::directory_iterator(path)) {
        if (entry.is_regular_file()) {
            std::string extension = entry.path().extension().string();

            if (!extension.empty() && extension[0] == '.') {
                extension = extension.substr(1);
            }

            std::string targetDir = path + "/" + extension;
            createDir(targetDir);

            try {
                fs::rename(entry.path(), targetDir + "/" + entry.path().filename().string());
            } catch (const fs::filesystem_error& e) {
                std::cerr << "Error moving file: " << e.what() << std::endl;
            }
        }
    }

    std::cout << "Operation Complete." << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " {folderpath}" << std::endl;
        return 1;
    }

    std::string directoryPath = argv[1];

    organize(directoryPath);

    return 0;
}
