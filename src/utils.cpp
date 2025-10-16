#include <utils.hpp>

string read_file(string href) {
    ostringstream buffer;
    ifstream file(href);

    if (file.is_open()) {
        buffer << file.rdbuf();
        file.close();

        return buffer.str();
    }

    cout << "Unable to open file" << endl;
    return "";
}