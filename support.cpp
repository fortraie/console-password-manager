#include <string>


const std::string kCharset {"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};
const int kDefaultShift {3};


/**
* Generates and returns a random string of characters.
*
* @param length Length of the string.
* @return Randomly generated string of characters.
*/
std::string randomString(size_t length) {
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
    if (shift == 0) shift = kDefaultShift;

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
    if (shift == 0) shift = kDefaultShift;

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


/**
* Provides with a numerical value derived from the string of characters provided.
*
* @param input String of characters from which the numerical value will be derived.
* @return Numerical value derived from the given string of characters.
 */
int stringToInt(std::string input) {
    int output {0};

    for (char i : input) {
        output += i;
    }

    return output;
}


/**
* Provides with current timestamp in a human-readable format.
*
* @return Timestamp in a string of characters format.
*/
std::string timestamp() {
    time_t current_time = time(nullptr);
    char* date_time = ctime(&current_time);

    std::string output {date_time};
    output.pop_back();

    return output;
}