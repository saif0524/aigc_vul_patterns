#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    if(n == 1){
        cout << 0;
        return 0;
    }
    vector<pair<int, int>> ops;
    for(int i = 0; i < n; i++){
        if(a[i] != i + 1){
            for(int j = i + 1; j < n; j++){
                if(a[j] == i + 1){
                    vector<int> parts;
                    if(i > 0) parts.push_back(i);
                    parts.push_back(j - i);
                    if(j + 1 < n) parts.push_back(n - j - 1);
                    ops.push_back({parts.size(), i + 1});
                    reverse(parts.begin(), parts.end());
                    for(int x: parts) ops.back().second += (x << 8);
                    reverse(a.begin() + i, a.begin() + j + 1);
                    reverse(a.begin() + i, a.begin() + n);
                    break;
                }
            }
        }
    }
    cout << ops.size() << "\n";
    for(auto [k, parts]: ops){
        cout << k;
        for(int i = 0; i < k; i++) cout << " " << ((parts >> (i * 8)) & 255);
        cout << "\n";
    }
}