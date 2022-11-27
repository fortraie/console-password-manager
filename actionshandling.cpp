#include <iostream>
#include <fstream>

#include "support.h"

const size_t kFileLength {8};
const std::string kExtensionName {"passdb"};
const std::string kHomeDirectory {getenv ("HOME")};

/**
* Creates new database file (registers user) with a randomly generated name.
* Encodes the password with caesar cipher and saves it in the file.
* Generates a timestamp and saves it in the file, encoded with caesar cipher of default shift.
*
* @param password Password for the database.
* @return Name of the created database file.
*/
std::string createDatabase(std::string password) {

    std::string file_name {randomString(kFileLength)};

    std::ofstream output_file (kHomeDirectory + "/" + file_name + "." + kExtensionName);

    output_file << encode(timestamp(), 0) << '\n';
    output_file << file_name << encode(password, stringToInt(password)) << '\n';
    output_file.close();

    return file_name;
}


/**
* Lists all available files with kExtensionName in user's home directory.
* @return List of all available files with kExtensionName in user's home directory.
*/
std::string listDatabases() {
    std::string output;

    int i{1};

    for (const std::__fs::filesystem::directory_entry& entry : std::__fs::filesystem::directory_iterator(kHomeDirectory)) {
        if (entry.path().extension() == "." + kExtensionName) {
            std::string file_name = entry.path().filename();
            output = output + "[" +std::to_string(i++) + "] " + file_name + "\n";
        }
    }

    output.pop_back();

    return output;
}