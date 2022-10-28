#ifndef FUNCTION_H
#define FUNCTION_H
#include <fstream>
#include <queue>
#include <iostream>
#include <algorithm>

void prep(std::string &word);
void split(const std::string word, std::queue<std::string> &fifo);
int readFileHashWords(const char *fName, std::vector<std::string>& words);
std::string readNextWord(std::istream &fin);
#endif
