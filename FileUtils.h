#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <fstream>
#include <string>

namespace FileUtils {

// 讀取整個文件內容
std::string read_file(const std::string& file_path) {
    std::ifstream file(file_path);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + file_path);
    }
    return std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
}

// 將內容寫入文件
void write_file(const std::string& file_path, const std::string& content) {
    std::ofstream file(file_path);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + file_path);
    }
    file << content;
}

} // namespace FileUtils

#endif // FILE_UTILS_H