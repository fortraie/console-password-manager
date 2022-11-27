#include <iostream>
#include <fstream>
#include <map>
#include <unordered_set>
#include <set>

#include "support.h"
#include "../classes/Category.h"
#include "../classes/Entry.h"

const size_t kFileLength {8};
const std::string kExtensionName {"passdb"};
const std::string kHomeDirectory {getenv ("HOME")};
const std::string kTimestampSignature {"[TS]"};
const std::string kCreationSignature{"[CR]"};

const std::string kCategorySignature {"[CT]"};
const std::string kInactiveCategorySignature {"[XC]"};

const std::string kEntrySignature {"[EN]"};
const std::string kInactiveEntrySignature {"[XE]"};


void writeTimestamp(std::string file_path);

void addCategory(std::string file_path, std::string password, Category category);
void removeCategory(std::string file_path, std::string password, Category category);


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
    std::string file_path = kHomeDirectory + "/" + file_name + "." + kExtensionName;

    writeTimestamp(file_path);

    std::ofstream output_file (file_path);

    output_file << kCreationSignature << file_name << encode(password, stringToInt(password)) << '\n';
    output_file.close();

    addCategory(file_path, password, Category("Entertainment"));
    addCategory(file_path, password, Category("Work"));
    addCategory(file_path, password, Category("Shopping"));

    removeCategory(file_path, password, Category("Entertainment"));

    return file_name;
}


/**
* Lists all available files with kExtensionName in user's home directory.
* @return List of all available files with kExtensionName in user's home directory.
*/
std::set<std::string> listDatabases() {
    std::set<std::string> output;

    for (const std::__fs::filesystem::directory_entry& entry : std::__fs::filesystem::directory_iterator(kHomeDirectory)) {
        if (entry.path().extension() == "." + kExtensionName) {
            output.insert(entry.path());
        }
    }

    return output;
}


/**
* Carries out the action of logging into the database.
*
* @param file_path File path to the database.
* @param password User's password for the database.
* @return Status code based on the outcome of the action (0 - successful log in, 1 - failed log in).
*/
int accessDatabase(std::string file_path, std::string password) {
    std::string decoded_password = kCreationSignature + fileName(file_path) + encode(password, stringToInt(password));

    std::ifstream input_file (file_path);
    std::string line;

    while (std::getline(input_file, line)) {
        if (line == decoded_password) return 0;
    }

    return 1;
}

/**
* Writes current timestamp to the database file.
*
* @param file_path File path where the timestamp will be written.
*/
void writeTimestamp(std::string file_path) {
    std::ofstream output_file(file_path, std::fstream::app);
    output_file << kTimestampSignature << encode(timestamp(), 0) << '\n';
    output_file.close();
}


/**
* Reads the last occurence beginning with kTimestampSignature from the database file and decodes it.
*
* @param file_path File path where the timestamp will be read.
* @return Decoded timestamp.
*/
std::string readTimestamp(std::string file_path) {
    std::ifstream input_file (file_path);
    std::string line;
    std::string timestamp;

    while (std::getline(input_file, line)) {
        if (line.substr(0, kTimestampSignature.length()) == kTimestampSignature) {
            timestamp = line;
        }
    }

    if (timestamp.empty()) return "";

    return decode(timestamp.substr(kTimestampSignature.length()), 0);
}


void addCategory(std::string file_path, std::string password, Category category) {
    std::ofstream output_file(file_path, std::fstream::app);
    output_file << kCategorySignature << encode(category.getName(), stringToInt(password)) << '\n';
    output_file.close();
}

void removeCategory(std::string file_path, std::string password, Category category) {
    std::ofstream output_file(file_path, std::fstream::app);
    output_file << kInactiveCategorySignature << encode(category.getName(), stringToInt(password)) << '\n';
    output_file.close();
}


/**
 * Reads all categories from the database file, removes inactive ones and decodes them.
 *
 * @param file_path File path where the categories will be read.
 * @param password User's password for the database.
 * @return Set of all active categories.
 */
std::set<Category> listCategories(std::string file_path, std::string password) {
    std::set<Category> output;

    std::ifstream input_file (file_path);
    std::string line;

    while (std::getline(input_file, line)) {
        if (line.substr(0, kCategorySignature.length()) == kCategorySignature) {
            Category category(decode(line.substr(kCategorySignature.length()), stringToInt(password)));
            output.insert(category);
        }
        if (line.substr(0, kInactiveCategorySignature.length()) == kInactiveCategorySignature) {
            Category category(decode(line.substr(kInactiveCategorySignature.length()), stringToInt(password)));
            output.erase(category);
        }
    }

    return output;
}