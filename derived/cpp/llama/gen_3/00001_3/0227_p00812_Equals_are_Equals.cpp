#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

struct Term {
    long long coeff;
    map<char, int> vars;
};

struct Poly {
    vector<Term> terms;
};

Poly parse(const string& expr) {
    Poly poly;
    int pos = 0;
    while (pos < expr.size()) {
        if (expr[pos] == ' ') {
            pos++;
            continue;
        }
        if (expr[pos] == '(') {
            int depth = 1;
            int start = pos + 1;
            while (depth > 0) {
                pos++;
                if (expr[pos] == '(') depth++;
                if (expr[pos] == ')') depth--;
            }
            string subexpr = expr.substr(start, pos - start);
            Poly subpoly = parse(subexpr);
            poly.terms.insert(poly.terms.end(), subpoly.terms.begin(), subpoly.terms.end());
            pos++;
        } else if (expr[pos] >= 'a' && expr[pos] <= 'z') {
            Term term;
            term.coeff = 1;
            term.vars[expr[pos]] = 1;
            poly.terms.push_back(term);
            pos++;
            if (pos < expr.size() && expr[pos] == '^') {
                pos++;
                int exp = 0;
                while (pos < expr.size() && expr[pos] >= '0' && expr[pos] <= '9') {
                    exp = exp * 10 + (expr[pos] - '0');
                    pos++;
                }
                poly.terms.back().vars[expr[pos - exp - 2]] = exp;
            }
        } else if (expr[pos] >= '0' && expr[pos] <= '9') {
            Term term;
            term.coeff = 0;
            while (pos < expr.size() && expr[pos] >= '0' && expr[pos] <= '9') {
                term.coeff = term.coeff * 10 + (expr[pos] - '0');
                pos++;
            }
            poly.terms.push_back(term);
        } else if (expr[pos] == '+') {
            pos++;
        } else if (expr[pos] == '-') {
            pos++;
            if (pos < expr.size() && expr[pos] >= '0' && expr[pos] <= '9') {
                Term term;
                term.coeff = 0;
                while (pos < expr.size() && expr[pos] >= '0' && expr[pos] <= '9') {
                    term.coeff = term.coeff * 10 + (expr[pos] - '0');
                    pos++;
                }
                term.coeff = -term.coeff;
                poly.terms.push_back(term);
            }
        }
    }
    return poly;
}

bool operator==(const Term& a, const Term& b) {
    return a.coeff == b.coeff && a.vars == b.vars;
}

bool operator<(const Term& a, const Term& b) {
    if (a.coeff!= b.coeff) return a.coeff < b.coeff;
    return a.vars < b.vars;
}

Poly simplify(const Poly& poly) {
    Poly result;
    for (const auto& term : poly.terms) {
        bool found = false;
        for (auto& resultTerm : result.terms) {
            if (resultTerm.vars == term.vars) {
                resultTerm.coeff += term.coeff;
                found = true;
                break;
            }
        }
        if (!found) {
            result.terms.push_back(term);
        }
    }
    result.terms.erase(remove_if(result.terms.begin(), result.terms.end(), [](const Term& term) { return term.coeff == 0; }), result.terms.end());
    sort(result.terms.begin(), result.terms.end());
    return result;
}

bool operator==(const Poly& a, const Poly& b) {
    return simplify(a) == simplify(b);
}

int main() {
    string line;
    while (getline(cin, line)) {
        if (line == ".") {
            cout << "." << endl;
            continue;
        }
        Poly expected = parse(line);
        while (getline(cin, line)) {
            if (line == ".") break;
            Poly actual = parse(line);
            cout << (expected == actual? "yes" : "no") << endl;
        }
    }
    return 0;
}