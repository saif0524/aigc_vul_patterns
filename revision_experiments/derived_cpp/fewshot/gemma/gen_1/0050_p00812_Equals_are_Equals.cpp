#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// Function to parse an expression into a polynomial representation
map<string, int> parse_expression(const string& expression) {
    map<string, int> polynomial;
    
    string current_term = "";
    bool is_negative = false;
    
    for (size_t i = 0; i < expression.length(); ++i) {
        if (expression[i] == '+' || expression[i] == '-') {
            if (!current_term.empty()) {
                if (is_negative) {
                    
                } else {
                    
                }
                
                
                if (current_term.find('^') != string::npos) {
                    
                } else {
                    
                }

                
                
            }
            current_term = "";
            is_negative = (expression[i] == '-');
        } else if (expression[i] == ' ') {
            continue;
        } else {
            current_term += expression[i];
        }
    }

    if (!current_term.empty()) {
        
    }

    return polynomial;
}

int main() {
    string expression;
    
    while (cin >> expression && expression != ".") {
        map<string, int> correct_expression = parse_expression(expression);
        
        while (cin >> expression && expression != ".") {
            map<string, int> student_expression = parse_expression(expression);

            bool equivalent = true;
            
            
            
            if (correct_expression.size() != student_expression.size()) {
                equivalent = false;
            } else {
                for (auto const& [key, val] : correct_expression) {
                    if (student_expression.find(key) == student_expression.end() || student_expression[key] != val) {
                        equivalent = false;
                        break;
                    }
                }
            }
           
            if (equivalent) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        }
        
        cout << "." << endl;
    }
    
    return 0;
}