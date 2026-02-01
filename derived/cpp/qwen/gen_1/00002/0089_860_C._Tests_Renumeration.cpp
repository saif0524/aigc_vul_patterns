#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<string, int>> files(n);
    for(auto &f : files){
        cin >> f.first >> f.second;
    }
    int e = 0;
    for(auto &f : files){
        if(f.second == 1) e++;
    }
    int regular = n, example = 1;
    vector<string> moves;
    for(auto &f : files){
        if(f.second == 1){
            if(stoi(f.first) != example){
                moves.push_back("move " + f.first + " " + to_string(example));
                f.first = to_string(example);
            }
            example++;
        }else{
            if(stoi(f.first) < e || stoi(f.first) > regular){
                moves.push_back("move " + f.first + " " + to_string(regular));
                f.first = to_string(regular);
            }
            regular--;
        }
    }
    cout << moves.size() << "\n";
    for(auto &m : moves){
        cout << m << "\n";
    }
}