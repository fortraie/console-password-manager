#include <iostream>

#include "actionshandling.h"

void logInUser();
void logInUserChooseCustomFilePath();
void registerUser();

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
    std::cout << "Nice to see you again!" << std::endl;
    std::cout << "Begin by choosing your database from the list below." << std::endl;
    std::cout << "[0] I can't find my file." << std::endl;
    std::cout << listDatabases() << std::endl;

    int action;
    std::cin >> action;

    if (action == 0) logInUserChooseCustomFilePath();
    else
};


void logInUserChooseCustomFilePath() {

}


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