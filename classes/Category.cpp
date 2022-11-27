//
// Created by Jakub Kowalewski on 27/11/2022.
//

#include "Category.h"

Category::Category(const std::string &name) : name(name) {}

const std::string &Category::getName() const {
    return name;
}

void Category::setName(const std::string &name) {
    Category::name = name;
}

bool Category::operator==(const Category &rhs) const {
    return name == rhs.name;
}

bool Category::operator!=(const Category &rhs) const {
    return !(rhs == *this);
}

bool Category::operator<(const Category &rhs) const {
    return name < rhs.name;
}

bool Category::operator>(const Category &rhs) const {
    return rhs < *this;
}

bool Category::operator<=(const Category &rhs) const {
    return !(rhs < *this);
}

bool Category::operator>=(const Category &rhs) const {
    return !(*this < rhs);
}
