#include <bits/stdc++.h>
using namespace std;

typedef map<vector<int>, int> poly;

int parseNum(const string &s, size_t &i) {
    int num = 0;
    while (i < s.size() && isdigit(s[i])) {
        num = num * 10 + (s[i] - '0');
        i++;
    }
    return num;
}

void parseTerm(const string &s, size_t &i, poly &p) {
    vector<int> tmp(26);
    int coeff = 1;
    bool hasCoeff = false;
    while (i < s.size() && (isdigit(s[i]) || isalpha(s[i]) || s[i] == '(')) {
        if (isdigit(s[i])) {
            coeff *= parseNum(s, i);
            hasCoeff = true;
        } else if (isalpha(s[i])) {
            int var = s[i] - 'a';
            tmp[var]++;
            i++;
            if (i < s.size() && s[i] == '^') {
                i++;
                tmp[var] = parseNum(s, i);
            }
        } else if (s[i] == '(') {
            poly tmpP;
            i++;
            parseExpr(s, i, tmpP);
            i++;
            for (auto &term : tmpP) {
                vector<int> newTerm = term.first;
                for (int j = 0; j < 26; j++) {
                    newTerm[j] += tmp[j];
                }
                p[newTerm] += term.second * coeff;
            }
            coeff = 1;
            hasCoeff = false;
            tmp = vector<int>(26);
        }
    }
    if (hasCoeff) {
        p[tmp] += coeff;
    } else if (!tmp.empty()) {
        p[tmp] += 1;
    }
}

void parseExpr(const string &s, size_t &i, poly &p) {
    while (i < s.size() && (isdigit(s[i]) || isalpha(s[i]) || s[i] == '(' || s[i] == '+' || s[i] == '-')) {
        if (s[i] == '+' || s[i] == '-') {
            i++;
        } else {
            int sign = s[i - 1] == '-' ? -1 : 1;
            poly tmpP;
            parseTerm(s, i, tmpP);
            for (auto &term : tmpP) {
                p[term.first] += sign * term.second;
            }
        }
    }
}

poly simplifyPoly(const string &s) {
    size_t i = 0;
    poly p;
    parseExpr(s, i, p);
    return p;
}

bool arePolysEqual(const poly &p1, const poly &p2) {
    return p1 == p2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(true){
        string line;
        poly correctPoly;
        vector<poly> studentPolys;
        while(getline(cin, line)){
            if(line == "."){
                break;
            }
            istringstream iss(line);
            string expr;
            while(iss >> expr){
                size_t i = 0;
                if(studentPolys.empty()){
                    correctPoly = simplifyPoly(expr);
                } else {
                    poly studentPoly = simplifyPoly(expr);
                    studentPolys.push_back(studentPoly);
                }
            }
        }
        if(studentPolys.empty()){
            break;
        }
        for(auto &studentPoly : studentPolys){
            if(arePolysEqual(correctPoly, studentPoly)){
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        }
        cout << "." << endl;
    }
    return 0;
}