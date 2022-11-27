//
// Created by Jakub Kowalewski on 26/11/2022.
//

#ifndef ACTIONSHANDLING_H
#define ACTIONSHANDLING_H

#include <set>

std::string createDatabase(std::string password);
std::set<std::string> listDatabases();
int accessDatabase(std::string file_path, std::string password);
void writeTimestamp(std::string file_path);
std::string readTimestamp(std::string file_path);

#endif //ACTIONSHANDLING_H
