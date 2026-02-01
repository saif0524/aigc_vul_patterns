#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

// Structure to represent a term in the polynomial
struct Term {
    int coefficient;
    map<char, int> variables;
};

// Function to add two terms
Term addTerms(const Term& t1, const Term& t2) {
    Term result;
    result.coefficient = t1.coefficient + t2.coefficient;
    for (auto& pair : t1.variables) {
        result.variables[pair.first] = pair.second;
    }
    for (auto& pair : t2.variables) {
        if (result.variables.find(pair.first) != result.variables.end()) {
            result.variables[pair.first] = pair.second;
        } else {
            result.variables[pair.first] = pair.second;
        }
    }
    return result;
}

// Function to subtract two terms
Term subtractTerms(const Term& t1, const Term& t2) {
    Term result;
    result.coefficient = t1.coefficient - t2.coefficient;
    for (auto& pair : t1.variables) {
        result.variables[pair.first] = pair.second;
    }
    for (auto& pair : t2.variables) {
        if (result.variables.find(pair.first) != result.variables.end()) {
            result.variables[pair.first] = pair.second;
        } else {
            result.variables[pair.first] = pair.second;
        }
    }
    return result;
}

// Function to multiply two terms
Term multiplyTerms(const Term& t1, const Term& t2) {
    Term result;
    result.coefficient = t1.coefficient * t2.coefficient;
    for (auto& pair : t1.variables) {
        if (result.variables.find(pair.first) != result.variables.end()) {
            result.variables[pair.first] = pair.second + result.variables[pair.first];
        } else {
            result.variables[pair.first] = pair.second;
        }
    }
    for (auto& pair : t2.variables) {
        if (result.variables.find(pair.first) != result.variables.end()) {
            result.variables[pair.first] = pair.second + result.variables[pair.first];
        } else {
            result.variables[pair.first] = pair.second;
        }
    }
    return result;
}

// Function to parse a term from a string
Term parseTerm(const string& str) {
    Term result;
    result.coefficient = 1;
    size_t pos = 0;
    while (pos < str.size()) {
        if (isdigit(str[pos])) {
            size_t endPos = pos;
            while (endPos < str.size() && isdigit(str[endPos])) {
                endPos++;
            }
            result.coefficient = stoi(str.substr(pos, endPos - pos));
            pos = endPos;
        } else if (isalpha(str[pos])) {
            char variable = str[pos];
            pos++;
            if (pos < str.size() && str[pos] == '^') {
                pos++;
                size_t endPos = pos;
                while (endPos < str.size() && isdigit(str[endPos])) {
                    endPos++;
                }
                int power = stoi(str.substr(pos, endPos - pos));
                result.variables[variable] = power;
                pos = endPos;
            } else {
                result.variables[variable] = 1;
            }
        } else {
            pos++;
        }
    }
    return result;
}

// Function to parse a polynomial from a string
vector<Term> parsePolynomial(const string& str) {
    vector<Term> result;
    size_t pos = 0;
    while (pos < str.size()) {
        if (str[pos] == '+') {
            pos++;
        } else if (str[pos] == '-') {
            pos++;
        } else {
            size_t endPos = pos;
            while (endPos < str.size() && str[endPos] != '+' && str[endPos] != '-') {
                endPos++;
            }
            Term term = parseTerm(str.substr(pos, endPos - pos));
            result.push_back(term);
            pos = endPos;
        }
    }
    return result;
}

// Function to compare two polynomials
bool comparePolynomials(const vector<Term>& p1, const vector<Term>& p2) {
    if (p1.size() != p2.size()) {
        return false;
    }
    for (size_t i = 0; i < p1.size(); i++) {
        if (p1[i].coefficient != p2[i].coefficient) {
            return false;
        }
        if (p1[i].variables.size() != p2[i].variables.size()) {
            return false;
        }
        for (auto& pair : p1[i].variables) {
            if (p2[i].variables.find(pair.first) == p2[i].variables.end() || p2[i].variables[pair.first] != pair.second) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    string line;
    while (getline(cin, line)) {
        if (line == ".") {
            break;
        }
        vector<Term> expected = parsePolynomial(line);
        while (getline(cin, line)) {
            if (line == ".") {
                cout << "." << endl;
                break;
            }
            vector<Term> actual = parsePolynomial(line);
            if (comparePolynomials(expected, actual)) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        }
    }
    return 0;
}