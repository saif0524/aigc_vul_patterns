#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cctype>
#include <climits>

using namespace std;

struct Term {
    int coeff;
    map<char, int> vars;

    Term(int c = 1) : coeff(c) {}

    bool operator==(const Term& other) const {
        return coeff == other.coeff && vars == other.vars;
    }

    bool operator<(const Term& other) const {
        if (vars != other.vars) return vars < other.vars;
        return coeff < other.coeff;
    }

    void normalize() {
        if (!coeff) vars.clear();
    }
};

struct Polynomial {
    vector<Term> terms;

    void addTerm(const Term& term) {
        for (auto& t : terms) {
            if (t.vars == term.vars) {
                t.coeff += term.coeff;
                t.normalize();
                if (!t.coeff) {
                    terms.erase(&t - &terms[0]);
                }
                return;
            }
        }
        if (term.coeff) terms.push_back(term);
    }

    static Polynomial parse(const string& str) {
        Polynomial poly;
        string exp = str;
        int i = 0;
        while (i < exp.size()) {
            Term term;
            int sign = 1;
            if (exp[i] == '-') sign = -1;
            if (exp[i] == '+' || exp[i] == '-') i++;
            while (i < exp.size() && isspace(exp[i])) i++;
            while (i < exp.size() && (isdigit(exp[i]) || (exp[i] == '-' && (i + 1 < exp.size() && isdigit(exp[i + 1]))))) {
                int num = 0;
                if (exp[i] == '-') num = -1, i++;
                while (isdigit(exp[i])) num = num * 10 + (exp[i] - '0'), i++;
                term.coeff *= num;
            }
            if (!term.coeff) term.coeff = 1;
            while (i < exp.size() && (isalpha(exp[i]) || exp[i] == '(')) {
                if (isalpha(exp[i])) {
                    char var = exp[i++];
                    int pow = 1;
                    if (i < exp.size() && exp[i] == '^') {
                        i++;
                        int base = 1;
                        while (i < exp.size() && isdigit(exp[i])) {
                            pow = pow * 10 + (exp[i] - '0');
                            base *= 10, i++;
                        }
                    }
                    term.vars[var] += pow;
                } else if (exp[i] == '(') {
                    int bal = 1, start = ++i;
                    while (i < exp.size() && bal) {
                        if (exp[i] == '(') bal++;
                        if (exp[i] == ')') bal--;
                        i++;
                    }
                    Polynomial subPoly = parse(exp.substr(start, i - start - 1));
                    for (const auto& subTerm : subPoly.terms) {
                        Term newTerm = term;
                        newTerm.coeff *= subTerm.coeff;
                        for (const auto& p : subTerm.vars) {
                            newTerm.vars[p.first] += p.second;
                        }
                        poly.addTerm(newTerm);
                    }
                    term = Term();
                }
            }
            term.coeff *= sign;
            term.normalize();
            if (term.coeff) poly.addTerm(term);
            while (i < exp.size() && isspace(exp[i])) i++;
        }
        return poly;
    }

    bool operator==(const Polynomial& other) const {
        if (terms.size() != other.terms.size()) return false;
        for (size_t i = 0; i < terms.size(); ++i) {
            if (terms[i] != other.terms[i]) return false;
        }
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string line;
    while (getline(cin, line)) {
        if (line == ".") break;
        Polynomial correctPoly = Polynomial::parse(line);
        vector<Polynomial> studentPols;
        while (getline(cin, line)) {
            if (line == ".") break;
            studentPols.push_back(Polynomial::parse(line));
        }
        for (const auto& studentPol : studentPols) {
            cout << (studentPol == correctPoly ? "yes" : "no") << "\n";
        }
        cout << ".\n";
    }
    return 0;
}