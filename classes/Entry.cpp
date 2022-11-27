#include <string>
#include "Entry.h"

Entry::Entry(const std::string &name, const std::string &login, const std::string &password, const Category &category)
        : name(name), login(login), password(password), category(category) {}

const std::string &Entry::getName() const {
    return name;
}

void Entry::setName(const std::string &name) {
    Entry::name = name;
}

const std::string &Entry::getLogin() const {
    return login;
}

void Entry::setLogin(const std::string &login) {
    Entry::login = login;
}

const std::string &Entry::getPassword() const {
    return password;
}

void Entry::setPassword(const std::string &password) {
    Entry::password = password;
}

const Category &Entry::getCategory() const {
    return category;
}

void Entry::setCategory(const Category &category) {
    Entry::category = category;
}
