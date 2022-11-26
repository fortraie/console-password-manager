#ifndef SUPPORT_H
#define SUPPORT_H

#include <string>

std::string generateRandomString(size_t length);
std::string encode(std::string input, size_t shift);
std::string decode(std::string input, size_t shift);

#endif //SUPPORT_H
