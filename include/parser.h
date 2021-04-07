#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <map>
#include<vector>
#include<string>
using namespace std;

void parser(vector<string> tokens);
string int_operation_parser(string op, string left, string right);

#endif // PARSER_H