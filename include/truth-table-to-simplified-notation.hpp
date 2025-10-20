#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>

using namespace std;

void print_table(vector<vector<pair<int, string>>> table);
string padded_bin_str(int n, int bits);
vector<int> find_differences(string a, string b);
string tt_to_notation(const string& variables, const vector<int>& minterms);