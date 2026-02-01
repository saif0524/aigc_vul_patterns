#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

struct Term {
    map<char, int> vars;
    long long coeff;
};

Term parse_term(const string& s) {
    Term term;
    term.coeff = 1;
    int i = 0;
    while (i < s.length()) {
        if (isdigit(s[i])) {
            string num_str;
            while (i < s.length() && isdigit(s[i])) {
                num_str += s[i];
                i++;
            }
            term.coeff *= stoll(num_str);
        } else if (isalpha(s[i])) {
            char var = s[i];
            i++;
            if (i < s.length() && s[i] == '^') {
                i++;
                string pow_str;
                while (i < s.length() && isdigit(s[i])) {
                    pow_str += s[i];
                    i++;
                }
                int pow_val = stoi(pow_str);
                term.vars[var] = pow_val;
            } else {
                term.vars[var] = 1;
            }
        } else if (s[i] == '(') {
            int j = i + 1;
            int count = 1;
            while (j < s.length()) {
                if (s[j] == '(') {
                    count++;
                } else if (s[j] == ')') {
                    count--;
                }
                if (count == 0) {
                    break;
                }
                j++;
            }
            string sub_expr = s.substr(i + 1, j - i - 1);
            Term sub_term = parse_term(sub_expr);
            term.coeff *= sub_term.coeff;
            for (auto const& [key, val] : sub_term.vars) {
                term.vars[key] = val;
            }
            i = j + 1;
        } else {
            i++;
        }
    }
    return term;
}

vector<Term> parse_expression(const string& s) {
    vector<Term> terms;
    string current_term_str;
    bool negative = false;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '+' || s[i] == '-') {
            if (!current_term_str.empty()) {
                Term term = parse_term(current_term_str);
                if (negative) {
                    term.coeff *= -1;
                }
                terms.push_back(term);
                current_term_str = "";
            }
            negative = (s[i] == '-');
        } else {
            current_term_str += s[i];
        }
    }
    if (!current_term_str.empty()) {
        Term term = parse_term(current_term_str);
        if (negative) {
            term.coeff *= -1;
        }
        terms.push_back(term);
    }
    return terms;
}

bool are_equivalent(const vector<Term>& terms1, const vector<Term>& terms2) {
    map<map<char, int>, long long> term_counts1;
    map<map<char, int>, long long> term_counts2;

    for (const auto& term : terms1) {
        term_counts1[term.vars] += term.coeff;
    }

    for (const auto& term : terms2) {
        term_counts2[term.vars] += term.coeff;
    }

    if (term_counts1.size() != term_counts2.size()) {
        return false;
    }

    for (const auto& [vars, coeff] : term_counts1) {
        if (term_counts2.find(vars) == term_counts2.end() || term_counts2[vars] != coeff) {
            return false;
        }
    }

    return true;
}

int main() {
    string line;
    while (getline(cin, line) && line != ".") {
        string expected_expr = line;
        vector<Term> expected_terms = parse_expression(expected_expr);

        while (getline(cin, line) && line != ".") {
            string student_expr = line;
            vector<Term> student_terms = parse_expression(student_expr);

            if (are_equivalent(expected_terms, student_terms)) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        }
        cout << "." << endl;
    }

    return 0;
}