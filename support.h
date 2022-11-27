#ifndef SUPPORT_H
#define SUPPORT_H

#include <string>

std::string randomString(size_t length);

std::string encode(std::string input, size_t shift);
std::string decode(std::string input, size_t shift);

int stringToInt(std::string input);

std::string timestamp();

#endif //SUPPORT_H
