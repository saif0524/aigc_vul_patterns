#include <bits/stdc++.h>
using namespace std;

const int MAXN = 150005;
const int MAXP =10000000;

vector<int> factors[MAXP + 1];

void sieve() {
    for (int i = 2; i <= MAXP; ++i) {
        if (factors[i].empty()) {
            for (int j = i; j <= MAXP; j += i) {
                factors[j].push_back(i);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    sieve();
    
    int n;
    cin >> n;
    
    unordered_map<int, int> commonFactors;
    
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        
        unordered_set<int> fa, fb;
        
        for (int f : factors[a]) {
            fa.insert(f);
        }
        
        for (int f : factors[b]) {
            fb.insert(f);
        }
        
        for (int f : fa) {
            if (fb.count(f)) {
                commonFactors[f]++;
            }
        }
    }
    
    int result = -1;
    
    for (auto& [factor, count] : commonFactors) {
        if (count == n) {
            result = factor;
            break;
        }
    }
    
    cout << result << "\n";
    
    return 0;
}