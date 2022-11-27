#ifndef CONSOLE_PASSWORD_MANAGER_ENTRY_H
#define CONSOLE_PASSWORD_MANAGER_ENTRY_H

#include "Category.h"


class Entry {
private:
    std::string name;
    std::string login;
    std::string password;
    Category category;

public:
    Entry(const std::string &name, const std::string &login, const std::string &password, const Category &category);

    const std::string &getName() const;
    void setName(const std::string &name);

    const std::string &getLogin() const;
    void setLogin(const std::string &login);

    const std::string &getPassword() const;
    void setPassword(const std::string &password);

    const Category &getCategory() const;
    void setCategory(const Category &category);
};


#endif //CONSOLE_PASSWORD_MANAGER_ENTRY_H
