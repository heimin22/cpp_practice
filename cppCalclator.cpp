#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <stdexcept>

using namespace std;

double parse_number (const string& num_str, bool& is_degrees) {
    is_degrees = false;
    if (num_str.empty()) throw invalid_argument("Empty number string");

    size_t suffix_pos = num_str.find_last_not_of("dD");
    if (suffix_pos != num_str.length() - 1) {
        is_degrees = true;
        return stod(num_str.substr(0, suffix_pos + 1)) * M_PI / 180.0;
    }
    return stod(num_str);
}

int main() {
    double last_result = 0;
    string line, name;

    cout << "Ano munang pangalan mo: ";
    cin >> name;
    cout << "Sige " + name << endl;

    cout << "Scientific Calculator (type 'exit' to quit)\n";
    cout << "Supported operations:\n- Basic: a + b, a x b\n- Advanced: pow a b, mod a b\n";
    cout << "Functions: sin[deg], cos[deg], tan[deg], sqrt, log, ln, fact, abs\n";
    cout << "Use 'ans' to reference previous result\n";

    while (true) {
        cout << "\nInput: ";
        getline(cin, line);

        if (line.empty()) continue;
        if (line == "exit") break;

        vector<string> tokens;
        istringstream iss(line);
        string token;
        while (iss >> token) tokens.push_back(token);

        try {
            process_operation(tokens, last_result);
            cout << "Result: " << last_result << endl;
        }
        catch (const exception e) {
            cerr << "Error: " << e.what() << endl;
        }
    }

    return 0;
}