#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

// Function to parse an expression and return a map of terms and their coefficients
map<string, int> parse_expression(const string& expression) {
    map<string, int> terms;
    string current_term;
    int sign = 1;

    for (size_t i = 0; i < expression.length(); ++i) {
        if (expression[i] == '+' || expression[i] == '-') {
            if (!current_term.empty()) {
                terms[current_term] += sign;
            }
            current_term = "";
            sign = (expression[i] == '+') ? 1 : -1;
        } else if (isdigit(expression[i])) {
            size_t j = i;
            while (j < expression.length() && isdigit(expression[j])) {
                ++j;
            }
            string num_str = expression.substr(i, j - i);
            int num = stoi(num_str);
            if (!current_term.empty()) {
                current_term += "*";
            }
            current_term += to_string(num);
            i = j - 1;
        } else if (isalpha(expression[i])) {
            current_term += expression[i];
            if (i + 1 < expression.length() && expression[i + 1] == '^') {
                size_t j = i + 2;
                while (j < expression.length() && isdigit(expression[j])) {
                    ++j;
                }
                string pow_str = expression.substr(i + 2, j - (i + 2));
                int pow_val = stoi(pow_str);
                current_term += "^" + pow_str;
                i = j - 1;
            }
        } else if (expression[i] == '(') {
            size_t j = i + 1;
            int paren_count = 1;
            while (j < expression.length() && paren_count > 0) {
                if (expression[j] == '(') {
                    ++paren_count;
                } else if (expression[j] == ')') {
                    --paren_count;
                }
                ++j;
            }
            string sub_expression = expression.substr(i + 1, j - (i + 1) - 1);
            map<string, int> sub_terms = parse_expression(sub_expression);
            for (auto const& [term, coeff] : sub_terms) {
                terms[term] += sign * coeff;
            }
            i = j - 1;
        } else if (expression[i] != ' ') {
            current_term += expression[i];
        }
    }

    if (!current_term.empty()) {
        terms[current_term] += sign;
    }

    return terms;
}

// Function to compare two expressions for equivalence
bool are_expressions_equivalent(const string& expression1, const string& expression2) {
    map<string, int> terms1 = parse_expression(expression1);
    map<string, int> terms2 = parse_expression(expression2);

    if (terms1.size() != terms2.size()) {
        return false;
    }

    for (auto const& [term, coeff] : terms1) {
        if (terms2.find(term) == terms2.end() || terms2[term] != coeff) {
            return false;
        }
    }

    return true;
}

int main() {
    string line;
    vector<string> expressions;

    while (getline(cin, line)) {
        if (line == ".") {
            if (!expressions.empty()) {
                string expected_answer = expressions[0];
                for (size_t i = 1; i < expressions.size(); ++i) {
                    if (are_expressions_equivalent(expected_answer, expressions[i])) {
                        cout << "yes" << endl;
                    } else {
                        cout << "no" << endl;
                    }
                }
                cout << "." << endl;
            }
            expressions.clear();
        } else {
            expressions.push_back(line);
        }
    }
    
    return 0;
}