#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> knights;
    for(int i = 0; i < n; ++i){
        if(i < 4){
            knights.emplace_back(i+1, 1);
        }
        else if(i < 8){
            knights.emplace_back(1, i-2);
        }
        else{
            int row = (i-8) / 5 + 3;
            int col = (i-8) % 5 + 2;
            knights.emplace_back(row, col);
        }
    }
    for(auto &knight : knights){
        cout << knight.first << " " << knight.second << "\n";
    }
}