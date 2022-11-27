#include <iostream>
#include <unordered_set>

#include "actionshandling.h"

void logInUser();
void registerUser();

std::string chooseCustomFilePath();
void lastAccess(std::string file_path);

/**
* Informs about initialization of the program and allows the user to log in or register.
*/
void initialize() {
    std::cout << "Hi! (✿◠‿◠)" << std::endl;
    std::cout << "Please log in or register:" << std::endl;
    std::cout << "1. Log in" << std::endl;
    std::cout << "2. Register" << std::endl;
    std::cout << "3. Exit" << std::endl;

    int action;
    std::cin >> action;

    switch (action) {
        case 1:
            logInUser();
            break;
        case 2:
            registerUser();
            break;
        case 3:
            exit(0);
    }
}


/**
* Allows the user to log in.
*/
void logInUser() {
    const size_t kCustomFilePath = 0;

    std::cout << "Nice to see you again!" << std::endl;
    std::cout << "Begin by choosing your database from the list below." << std::endl;
    std::cout << "[" << kCustomFilePath << "] " << "I can't find my file." << std::endl;

    std::set<std::string> available_databases = listDatabases();
    size_t i {1};
    for (const std::string& available_database : available_databases) {
        std::cout << "[" << i++ << "] " << available_database << std::endl;
    }

    int action;
    std::cin >> action;

    std::cout << "Please provide the password to the database you're willing to access:" << std::endl;
    std::string password;
    std::cin >> password;

    int status;
    std::string file_path;
    if (action == kCustomFilePath) file_path = chooseCustomFilePath();
    else file_path = *std::next(available_databases.begin(), --action);

    if (action == kCustomFilePath) status = accessDatabase(file_path, password);
    else status = accessDatabase(file_path, password);

    if (status == 0) {
        lastAccess(file_path);
    }
};


/**
* Allows the user to register.
*/
void registerUser() {
    std::cout << "Thanks for choosing a reliable password manager!" << std::endl;
    std::cout << "Think of a password for your new database:" << std::endl;

    std::string password;
    std::cin >> password;

    std::cout << "Great! ☆*:.｡. o(≧▽≦)o .｡.:*☆" << std::endl;
    std::cout << "New database file " + createDatabase(password) + " has been created in your home directory." << std::endl;
}


std::string chooseCustomFilePath() {
    std::cout << "Enter the full file path to your database:" << std::endl;

    std::string file_path;
    std::cin >> file_path;

    return file_path;
}


void lastAccess(std::string file_path) {
    std::string last_access = readTimestamp(file_path);
    if (last_access.empty()) {
        std::cout << "This is your first time accessing this database." << std::endl;
    } else {
        std::cout << "Last access to this database was accounted on " << last_access << "." << std::endl;
    }
    writeTimestamp(file_path);
}