#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;
    vector<string> result;
    int count0 = 0, count1 = 0;
    string current = "";
    for(char c: s){
        current += c;
        if(c == '0') count0++;
        else count1++;
        if(count0 != 0 && count1 != 0 && count0 == count1){
            result.push_back(current);
            current = "";
            count0 = 0;
            count1 = 0;
        }
    }
    if(!current.empty()) result.push_back(current);
    cout << result.size() << endl;
    for(int i=0;i<result.size();i++){
        cout << result[i];
        if(i < result.size() - 1) cout << " ";
    }
    cout << endl;
    return 0;
}