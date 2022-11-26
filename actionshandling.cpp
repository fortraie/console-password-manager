#include <iostream>
#include <fstream>

#include "support.h"

const size_t kFileLength {8};

/**
* Creates new database file (registers user) with a randomly generated name.
*/
void registerUser() {
    std::string home_directory {getenv ("HOME")};
    std::string file_name {generateRandomString(kFileLength)};

    std::ofstream output_file (home_directory + "/" + file_name);

    output_file << file_name;
    output_file.close();
}
