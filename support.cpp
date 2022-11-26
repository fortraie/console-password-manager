#include <string>
#include <iostream>

const std::string kCharset {"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};

/**
* Generates and returns a random string of characters.
*
* @param length Length of the string.
* @return Randomly generated string of characters.
*/
std::string generateRandomString(size_t length) {
    srand(time(nullptr));
    std::string output;

    for (size_t i = 0; i < length; i++) {
        output = output + kCharset[rand() % kCharset.length()];
    }

    return output;
}

/**
* Encodes given string of characters with caesar cipher.
*
* @param shift Shift made.
* @return Encoded string of characters.
*/
std::string encode(std::string input, size_t shift) {
    std::string output;

    for (size_t i = 0; i < input.length(); i++) {
        size_t position = kCharset.find(input[i]);
        if (position == std::string::npos) {
            output += input[i];
        } else {
            size_t new_position = (position + shift) % kCharset.length();
            output += kCharset[new_position];
        }
    }

    return output;
}

/**
* Decodes given string of characters with caesar cipher.
*
* @param shift Shift made.
* @return Decoded string of characters.
*/
std::string decode(std::string input, size_t shift) {
    std::string output;

    for (size_t i = 0; i < input.length(); i++) {
        size_t position = kCharset.find(input[i]);
        if (position == std::string::npos) {
            output += input[i];
        } else {
            size_t new_position = (position - shift) % kCharset.length();
            output += kCharset[new_position];
        }
    }

    return output;
}