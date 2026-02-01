#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> p(n, 0);
    vector<int> max_bits(n, 0);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j) continue;
            cout << "? " << i+1 << " " << j+1 << endl;
            fflush(stdout);
            int val;
            cin >> val;
            if(val == -1) return 0;
            max_bits[i] = max(max_bits[i], val);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(max_bits[i] == (max_bits[i]|max_bits[j])){
                p[j] = i;
                break;
            }
        }
    }
    cout << "!";
    for(int x : p) cout << " " << x;
    cout << endl;
    return 0;
}