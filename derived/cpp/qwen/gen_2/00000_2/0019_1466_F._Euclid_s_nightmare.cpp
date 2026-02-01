#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> vectors(n);
    for(int i=0; i<n; i++){
        int k;
        cin >> k;
        vectors[i].resize(k);
        for(int &x : vectors[i]) cin >> x, x--;
    }

    bitset<500005> basis[m];
    vector<int> indices;
    for(int i=0; i<n; i++){
        bitset<500005> vec(m);
        for(int x : vectors[i]) vec[x] = 1;
        bool independent = true;
        for(int j=0; j<m; j++){
            if(vec[j] && basis[j].count()){
                vec ^= basis[j];
            }
        }
        for(int j=0; j<m && independent; j++){
            if(!basis[j].count()){
                basis[j] = vec;
                indices.push_back(i);
                independent = false;
            }
        }
    }

    long long size_T = 1;
    for(int j=0; j<m; j++){
        if(basis[j].count()){
            size_T = (size_T * 2) % MOD;
        }
    }

    sort(indices.begin(), indices.end());
    cout << size_T << " " << indices.size() << "\n";
    for(int idx : indices){
        cout << idx + 1 << " ";
    }
}