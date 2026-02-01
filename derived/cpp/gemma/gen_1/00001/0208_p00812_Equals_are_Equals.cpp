#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

class Polynomial {
public:
    map<vector<pair<char, int>>, int> terms;

    Polynomial() {}

    void add_term(const vector<pair<char, int>>& vars, int coeff) {
        terms[vars] += coeff;
    }

    void simplify() {
        for (auto& it : terms) {
            if (it.second == 0) {
                terms.erase(it);
            }
        }
    }

    bool equivalent(const Polynomial& other) const {
        if (terms.size() != other.terms.size()) {
            return false;
        }
        for (const auto& it : terms) {
            if (other.terms.find(it.first) == other.terms.end() || it.second != other.terms.at(it.first)) {
                return false;
            }
        }
        return true;
    }
};

Polynomial parse_expression(const string& expression) {
    Polynomial result;
    string current_term;
    int sign = 1;
    
    for (int i = 0; i < expression.length(); ++i) {
        char c = expression[i];
        if (c == '+' || c == '-') {
            if (!current_term.empty()) {
                
                vector<pair<char, int>> vars;
                int coeff = 1;
                
                size_t pos = 0;
                
                while (pos < current_term.length()) {
                    if (isdigit(current_term[pos])) {
                        string num_str;
                        while (pos < current_term.length() && isdigit(current_term[pos])) {
                            num_str += current_term[pos];
                            pos++;
                        }
                        coeff = stoi(num_str);
                    } else if (isalpha(current_term[pos])) {
                        char var = current_term[pos];
                        int power = 1;
                        pos++;
                        if (pos < current_term.length() && current_term[pos] == '^') {
                            pos++;
                            string pow_str;
                            while (pos < current_term.length() && isdigit(current_term[pos])) {
                                pow_str += current_term[pos];
                                pos++;
                            }
                            power = stoi(pow_str);
                        }
                        vars.push_back({var, power});
                    } else if (current_term[pos] == '(') {
                        
                        int start = pos;
                        int count = 1;
                        pos++;
                        while (pos < current_term.length() && count > 0) {
                            if (current_term[pos] == '(') {
                                count++;
                            } else if (current_term[pos] == ')') {
                                count--;
                            }
                            pos++;
                        }

                        string sub_expression = current_term.substr(start + 1, pos - start - 1);
                        Polynomial sub_poly = parse_expression(sub_expression);

                        
                        for (auto& it : sub_poly.terms) {
                            vector<pair<char, int>> new_vars = it.first;
                            
                            result.add_term(new_vars, it.second * coeff * sign);
                        }
                       
                        break;
                    } else {
                        pos++;
                    }
                }

            }
            sign = (c == '+') ? 1 : -1;
            current_term = "";
        } else {
            current_term += c;
        }
    }

    if (!current_term.empty()) {
        vector<pair<char, int>> vars;
        int coeff = 1;
        
        size_t pos = 0;
        
        while (pos < current_term.length()) {
            if (isdigit(current_term[pos])) {
                string num_str;
                while (pos < current_term.length() && isdigit(current_term[pos])) {
                    num_str += current_term[pos];
                    pos++;
                }
                coeff = stoi(num_str);
            } else if (isalpha(current_term[pos])) {
                char var = current_term[pos];
                int power = 1;
                pos++;
                if (pos < current_term.length() && current_term[pos] == '^') {
                    pos++;
                    string pow_str;
                    while (pos < current_term.length() && isdigit(current_term[pos])) {
                        pow_str += current_term[pos];
                        pos++;
                    }
                    power = stoi(pow_str);
                }
                vars.push_back({var, power});
            } else if (current_term[pos] == '(') {
               
                int start = pos;
                int count = 1;
                pos++;
                while (pos < current_term.length() && count > 0) {
                    if (current_term[pos] == '(') {
                        count++;
                    } else if (current_term[pos] == ')') {
                        count--;
                    }
                    pos++;
                }

                string sub_expression = current_term.substr(start + 1, pos - start - 1);
                Polynomial sub_poly = parse_expression(sub_expression);
                
                for (auto& it : sub_poly.terms) {
                    vector<pair<char, int>> new_vars = it.first;
                
                    result.add_term(new_vars, it.second * coeff * sign);
                }
             
                break;
            } else {
                pos++;
            }
        }
        result.add_term(vars, coeff * sign);
    }

    result.simplify();
    return result;
}

int main() {
    string line;
    vector<string> expressions;

    while (getline(cin, line)) {
        if (line == ".") {
            if (expressions.empty()) continue;
            
            Polynomial expected_expression = parse_expression(expressions[0]);
            
            for (size_t i = 1; i < expressions.size(); ++i) {
                Polynomial student_expression = parse_expression(expressions[i]);
                if (expected_expression.equivalent(student_expression)) {
                    cout << "yes" << endl;
                } else {
                    cout << "no" << endl;
                }
            }
            cout << "." << endl;
            expressions.clear();
        } else {
            expressions.push_back(line);
        }
    }

    return 0;
}