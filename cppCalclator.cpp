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

double factorial(double n) {
    if (n < 0 || n != static_cast<int>(n)) throw invalid_argument("Error: dapat positive lang tayo pre sa factorial");

    double result = 1;
    for (int i = 2; i <= n; ++i) result *= i;
    return result;
}

void process_operation(const vector<string>& tokens, double& last_result) {
    if (tokens.size() == 3) {
        double a = tokens[0] == "ans" ? last_result : stod(tokens[0]);
        double b = tokens[2] == "ans" ? last_result : stod(tokens[2]);
        string op = tokens[1];

        if (op == "+") last_result = a + b;
        else if (op == "-") last_result = a - b;
        else if (op == "*" || op == "X" || op == "x") last_result = a * b;
        else if (op == "/") {
            if (b == 0) throw invalid_argument("Error: bawal division by zero rito tanga");
            last_result = a / b;
        }
        else if (op == "pow") last_result = pow(a, b);
        else if (op == "mod") {
            if (b == 0) throw invalid_argument("Error: bawal kunin yung remainder kasi divide by zero yan tanga haha");
            last_result = fmod(a, b);
        }
        else throw invalid_argument("tanginamo anong operator yan? ayos oy");
    }
    else if(tokens.size() == 2) {
        bool degrees = false;
        double num = tokens[1] == "ans" ? last_result : parse_number(tokens[1], degrees);
        string func = tokens[0];

        if (func == "sin") last_result = sin(num);
    }
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