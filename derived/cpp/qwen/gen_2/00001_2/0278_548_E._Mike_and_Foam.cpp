#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int MAXA = 500005;

vector<int> factors[MAXA];
int counts[MAXA];
int totalPairs = 0;

void precomputeFactors() {
    for (int i = 1; i < MAXA; i++) {
        for (int j = i; j < MAXA; j += i) {
            factors[j].push_back(i);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    
    precomputeFactors();
    
    for(int i=0;i<q;i++){
        int x;
        cin >> x;
        x--;
        
        for(auto f: factors[a[x]]){
            if(counts[f] > 0){
                totalPairs -= (counts[f] -1);
            }
            counts[f]++;
            if(counts[f] > 1){
                totalPairs += (counts[f] -1);
            }
        }
        
        cout << totalPairs << "\n";
    }
}