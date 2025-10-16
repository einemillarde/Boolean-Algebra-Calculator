#pragma once

#include <iostream>
#include <utils.hpp>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>

using namespace std;

const string VARIABLES = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
void print_table(vector<vector<pair<int, string>>> table);
string padded_bin_str(int n, int bits);
vector<int> find_differences(string a, string b);
void tt_to_notation();