// [esbmc] replaced #include <bits/stdc++.h> with ESBMC-compatible headers
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cinttypes>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <istream>
#include <ostream>
#include <ios>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <streambuf>
#include <string>
#include <string_view>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include <iterator>
#include <memory>
#include <tuple>
#include <limits>
#include <random>
#include <complex>
#include <valarray>
#include <stdexcept>
#include <exception>
#include <typeinfo>
#include <type_traits>
#include <initializer_list>
#include <numbers>
#include <any>
using namespace std;

typedef map<string, long long> Poly;

Poly parseTerm(const string& s, int& pos) {
    Poly res;
    int n = s.size();
    long long coeff = 0;
    bool hasCoeff = false;
    string var;
    while (pos < n && (isdigit(s[pos]) || s[pos] == ' ')) {
        if (isdigit(s[pos])) {
            coeff = coeff * 10 + (s[pos] - '0');
            hasCoeff = true;
        }
        pos++;
    }
    if (!hasCoeff) coeff = 1;
    while (pos < n && (isalpha(s[pos]) || s[pos] == '^' || s[pos] == ' ')) {
        if (isalpha(s[pos])) {
            var += s[pos];
            pos++;
            if (pos < n && s[pos] == '^') {
                pos++;
                int exp = 0;
                while (pos < n && isdigit(s[pos])) {
                    exp = exp * 10 + (s[pos] - '0');
                    pos++;
                }
                var += to_string(exp);
            } else {
                var += "1";
            }
        } else if (s[pos] == ' ') {
            pos++;
        }
    }
    sort(var.begin(), var.end());
    res[var] = coeff;
    return res;
}

Poly parseFactor(const string& s, int& pos) {
    Poly res;
    if (s[pos] == '(') {
        pos++;
        res = parseExpr(s, pos);
        pos++; // skip ')'
    } else {
        res = parseTerm(s, pos);
    }
    return res;
}

Poly parseProduct(const string& s, int& pos) {
    Poly res;
    res[""] = 1;
    while (pos < s.size() && (isalpha(s[pos]) || isdigit(s[pos]) || s[pos] == '(' || s[pos] == ' ')) {
        Poly factor = parseFactor(s, pos);
        Poly newRes;
        for (const auto& term1 : res) {
            for (const auto& term2 : factor) {
                string var = term1.first + term2.first;
                sort(var.begin(), var.end());
                newRes[var] += term1.second * term2.second;
            }
        }
        res = newRes;
    }
    return res;
}

Poly parseExpr(const string& s, int& pos) {
    Poly res;
    pos = 0;
    while (pos < s.size()) {
        if (s[pos] == '+') {
            pos++;
            Poly term = parseProduct(s, pos);
            for (const auto& p : term) {
                res[p.first] += p.second;
            }
        } else if (s[pos] == '-') {
            pos++;
            Poly term = parseProduct(s, pos);
            for (const auto& p : term) {
                res[p.first] -= p.second;
            }
        } else {
            Poly term = parseProduct(s, pos);
            for (const auto& p : term) {
                res[p.first] += p.second;
            }
        }
        while (pos < s.size() && s[pos] == ' ') pos++;
    }
    return res;
}

bool isEquivalent(const Poly& p1, const Poly& p2) {
    if (p1.size() != p2.size()) return false;
    for (const auto& p : p1) {
        if (p2.find(p.first) == p2.end() || p2[p.first] != p.second) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string line;
    while (getline(cin, line)) {
        if (line == ".") break;
        Poly correct = parseExpr(line, 0);
        vector<Poly> answers;
        while (getline(cin, line) && line != ".") {
            answers.push_back(parseExpr(line, 0));
        }
        for (const auto& ans : answers) {
            cout << (isEquivalent(correct, ans) ? "yes" : "no) << \n";
        }
        cout << ".\n";
    }
    return 0;
}