#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// Function to parse an expression string and return a polynomial representation
map<string, int> parse_expression(const string& expression) {
    map<string, int> polynomial;
    string current_term = "";
    bool is_negative = false;

    for (size_t i = 0; i < expression.length(); ++i) {
        char c = expression[i];

        if (c == ' ') {
            continue;
        } else if (c == '+') {
            if (!current_term.empty()) {
                polynomial[current_term] += 1;
            }
            is_negative = false;
            current_term = "";
        } else if (c == '-') {
            if (!current_term.empty()) {
                polynomial[current_term] += 1;
            }
            is_negative = true;
            current_term = "";
        } else if (c == '(') {
            int open_count = 1;
            int j = i + 1;
            while (j < expression.length() && open_count > 0) {
                if (expression[j] == '(') {
                    open_count++;
                } else if (expression[j] == ')') {
                    open_count--;
                }
                j++;
            }
            string sub_expression = expression.substr(i + 1, j - i - 2);
            map<string, int> sub_polynomial = parse_expression(sub_expression);
            for (auto const& [term, coeff] : sub_polynomial) {
                polynomial[term] += coeff;
            }
            i = j - 1;
            current_term = "";
        } else if (c == ')') {
           
        } else if (c == '^') {
            string var = current_term;
            int power = 0;
            size_t k = i + 1;
            while (k < expression.length() && isdigit(expression[k])) {
                power = power * 10 + (expression[k] - '0');
                k++;
            }
            
            string term = var + "^" + to_string(power);
            polynomial[term] += 1;
            current_term = "";
            i = k - 1; 
        } else if (isalpha(c)) {
            current_term += c;
        } else if (isdigit(c)) {
            
            string num_str = "";
            while (i < expression.length() && isdigit(expression[i])) {
                num_str += expression[i];
                i++;
            }
            
            
            if (!current_term.empty()) {
                string term = num_str + current_term;
                polynomial[term] += 1;
                current_term = "";
                i--;
            }
            else {
                current_term = num_str;
            }
        } else {
            
        }
    }

    if (!current_term.empty()) {
         polynomial[current_term] += 1;
    }
    return polynomial;
}

// Function to compare two polynomials for equivalence
bool are_equivalent(const map<string, int>& poly1, const map<string, int>& poly2) {
    for (auto const& [term, coeff] : poly1) {
        if (poly2.find(term) == poly2.end() || poly2.at(term) != coeff) {
            return false;
        }
    }
    for (auto const& [term, coeff] : poly2) {
        if (poly1.find(term) == poly1.end() || poly1.at(term) != coeff) {
            return false;
        }
    }
    return true;
}

int main() {
    string expression;
    
    while (getline(cin, expression)) {
        if (expression == ".") {
            cout << "." << endl;
            
            continue;
        }

        map<string, int> expected_polynomial = parse_expression(expression);

        
        while (getline(cin, expression)) {
            if (expression == ".") {
                cout << "." << endl;
                break;
            }
            map<string, int> student_polynomial = parse_expression(expression);
            
            if (are_equivalent(expected_polynomial, student_polynomial)) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        }
    }
    

    return 0;
}