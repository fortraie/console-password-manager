#ifndef SUPPORT_H
#define SUPPORT_H

#include <string>

std::string randomString(size_t length);

std::string encode(std::string input, int shift);
std::string decode(std::string input, int shift);

int stringToInt(std::string input);

std::string timestamp();
std::string fileName(std::string file_path);

#endif //SUPPORT_H
