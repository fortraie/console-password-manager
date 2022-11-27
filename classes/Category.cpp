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
