#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

std::string trim(const std::string& s);

std::vector<std::string> readCSVLines(const std::string& filePath);

bool writeCSVAtomically(const std::string& destFilePath, std::vector<std::string>& righe);

#endif