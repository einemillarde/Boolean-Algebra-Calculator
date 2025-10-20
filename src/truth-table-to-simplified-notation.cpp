#include <truth-table-to-simplified-notation.hpp>

void print_table(vector<vector<pair<vector<int>, string>>> table) {
    for (int group = 0; group < table.size(); group++) {
        cout << "Group " << group << ":" << endl;
        auto group_array = table[group];
        for (const auto& term : group_array) {
            cout << "    Minterms ";
            for (int i = 0; i < term.first.size(); i++) {
                cout << term.first[i];
                if (i != term.first.size() - 1) {
                    cout << ", ";
                }
            }
            cout << ": " << term.second << endl;
        }
    }
}

string padded_bin_str(int n, int bits) {
    string binary_str = "";

    for (int i = bits - 1; i >= 0; i--) {
        binary_str += ((n >> i) & 1) + '0';
    }

    return binary_str;
}

vector<int> find_differences(string a, string b) {
    if (a.length() != b.length()) {
        cout << "Strings are different lengths" << endl;
        return {};
    }

    vector<int> changes;

    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i]) {
            changes.push_back(i);
        }
    }

    return changes;
}

string tt_to_notation(const string& variables, const vector<int>& minterms) {
    const int NUM_INPUTS = variables.length();
    const int COMBINATIONS = pow(2, NUM_INPUTS);

    vector<vector<pair<vector<int>, string>>> table(NUM_INPUTS + 1);

    for (const auto& minterm : minterms) {
        string bin_str = padded_bin_str(minterm, NUM_INPUTS);
        int num_1s = count(bin_str.begin(), bin_str.end(), '1');
        table[num_1s].push_back({ { minterm }, bin_str });
    }

    while (true) {
        vector<vector<pair<vector<int>, string>>> new_table(NUM_INPUTS + 1);
        bool changed = false;

        for (int group = 0; group < table.size() - 1; group++) {
            for (const auto& minterm : table[group]) {
                for (const auto& next_group_minterm : table[group + 1]) {
                    vector<int> differences = find_differences(minterm.second, next_group_minterm.second);
                    if (differences.size() != 1) {
                        continue;
                    }
                    string str = minterm.second;
                    str[differences[0]] = '-';
                    auto combined_minterms = minterm.first;
                    combined_minterms.insert(combined_minterms.end(), next_group_minterm.first.begin(), next_group_minterm.first.end());
                    new_table[group].push_back({ combined_minterms, str });
                    changed = true;
                }
            }
        }

        if (!changed) break;
        table = move(new_table);
    }

    vector<pair<vector<int>, string>> prime_implicants;
    for (const auto& group : table) {
        for (const auto& term : group) {
            bool found_term = false;
            for (const auto& existing_term : prime_implicants) {
                if (existing_term.second == term.second) {
                    found_term = true;
                    break;
                }
            }
            if (!found_term) {
                prime_implicants.push_back(term);
            }
        }
    }

    vector<int> counts(COMBINATIONS);
    for (const auto& term : prime_implicants) {
        for (const auto& minterm : term.first) {
            counts[minterm]++;
        }
    }

    vector<pair<vector<int>, string>> essential_prime_implicants;
    for (const auto& term : prime_implicants) {
        bool is_essential = false;
        for (const auto& minterm : term.first) {
            if (counts[minterm] == 1) {
                is_essential = true;
                break;
            }
        }
        if (is_essential) {
            essential_prime_implicants.push_back(term);
        }
    }

    stringstream notation_ss;
    for (int i = 0; i < essential_prime_implicants.size(); i++) {
        const auto& term = essential_prime_implicants[i];
        for (int j = 0; j < NUM_INPUTS; j++) {
            if (term.second[j] == '1') {
                notation_ss << variables[j];
                notation_ss << " * ";
            } else if (term.second[j] == '0') {
                notation_ss << variables[j] << "'";
                notation_ss << " * ";
            }
        }
        string term_str = notation_ss.str();
        term_str = term_str.substr(0, term_str.length() - 3);
        notation_ss.str("");
        notation_ss << term_str;
        if (i != essential_prime_implicants.size() - 1) {
            notation_ss << " + ";
        }
    }

    return notation_ss.str();
}