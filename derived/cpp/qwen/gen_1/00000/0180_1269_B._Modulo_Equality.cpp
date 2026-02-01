#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;
    map<int, int> freqA, freqB;
    for(int i=0; i<n; i++){
        freqA[a[i]]++;
        freqB[b[i]]++;
    }
    for(int x=0; x<m; x++){
        bool valid = true;
        map<int, int> tempFreqA(freqA);
        for(auto &[bVal, bCount]: freqB){
            int aVal = (bVal - x + m) % m;
            if(tempFreqA[aVal] < bCount){
                valid = false;
                break;
            }
            tempFreqA[aVal] -= bCount;
        }
        if(valid){
            cout << x;
            return 0;
        }
    }
}