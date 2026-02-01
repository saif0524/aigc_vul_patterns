#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> platforms;
    for(int i=0;i<n;i++){
        if(s[i] == '*'){
            platforms.push_back(i);
        }
    }
    int m = platforms.size();
    for(int i=0;i<m-4;i++){
        for(int j=i+1;j<m-3;j++){
            int diff = platforms[j] - platforms[i];
            if(platforms[j+1] - platforms[j] == diff && platforms[j+2] - platforms[j+1] == diff && platforms[j+3] - platforms[j+2] == diff){
                cout << "yes";
                return 0;
            }
        }
    }
    cout << "no";
}