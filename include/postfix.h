#pragma once

#include "stack.h"
#include <cctype>
#include<map>
#include<string>

int getPriority(char c);
string toPost(string exp);
map<char, double> getVals(string postExp);
double postRez(string postExp, map<char, double> &vals);

