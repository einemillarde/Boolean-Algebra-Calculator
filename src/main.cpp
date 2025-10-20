#include <truth-table-to-simplified-notation.hpp>
#include <iostream>

int main() {
    string variables;
    vector<int> minterms;

    string minterm_input;

    cout << "Enter variables (e.g. ABC for 3 variables): ";
    cin >> variables;
    int minterm;
    cout << "Enter minterms (e.g. 0 1 2 5 6 7): ";
    while (cin >> minterm) {
        minterms.push_back(minterm);
        if (cin.peek() == '\n') {
            break;
        }
    }

    cout << tt_to_notation(variables, minterms) << endl;
    return 0;
}