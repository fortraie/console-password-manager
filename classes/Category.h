//
// Created by Jakub Kowalewski on 27/11/2022.
//

#ifndef CONSOLE_PASSWORD_MANAGER_CATEGORY_H
#define CONSOLE_PASSWORD_MANAGER_CATEGORY_H


#include <string>

class Category {
private:
    std::string name;
public:
    explicit Category(const std::string &name);

    const std::string &getName() const;
    void setName(const std::string &name);

    bool operator==(const Category &rhs) const;

    bool operator!=(const Category &rhs) const;

    bool operator<(const Category &rhs) const;

    bool operator>(const Category &rhs) const;

    bool operator<=(const Category &rhs) const;

    bool operator>=(const Category &rhs) const;
};


#endif //CONSOLE_PASSWORD_MANAGER_CATEGORY_H
