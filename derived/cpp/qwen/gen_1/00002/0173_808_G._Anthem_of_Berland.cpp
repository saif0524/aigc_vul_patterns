#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int pi[N];
string s, t;

void build_pi() {
    int n = t.size();
    pi[0] = 0;
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && t[i] != t[j]) j = pi[j - 1];
        if (t[i] == t[j]) j++;
        pi[i] = j;
    }
}

int kmp_count() {
    int n = s.size();
    int m = t.size();
    build_pi();
    int j = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && (s[i] != t[j] && s[i] != '?' && t[j] != '?')) j = pi[j - 1];
        if (s[i] == t[j] || s[i] == '?' || t[j] == '?') j++;
        if (j == m) {
            count++;
            j = pi[j - 1];
        }
    }
    return count;
}

int main(){
    cin >> s >> t;
    int max_occurrences = 0;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == '?'){
            int best = 0;
            for(char c = 'a'; c <= 'z'; ++c){
                s[i] = c;
                best = max(best, kmp_count());
            }
            s[i] = '?';
            max_occurrences = best;
        }
        else{
            max_occurrences = max(max_occurrences, kmp_count());
        }
    }
    int result = kmp_count();
    cout << result;
}