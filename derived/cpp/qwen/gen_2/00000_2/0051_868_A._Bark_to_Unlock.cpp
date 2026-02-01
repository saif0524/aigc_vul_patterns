#include <bits/stdc++.h>
using namespace std;

int main(){
    string password;
    cin >> password;
    int n;
    cin >> n;
    set<string> words;
    for(int i=0;i<n;i++){
        string word;
        cin >> word;
        words.insert(word);
    }
    for(auto it1 = words.begin(); it1 != words.end(); ++it1){
        for(auto it2 = words.begin(); it2 != words.end(); ++it2){
            string combined = *it1 + *it2;
            if(combined.find(password) != string::npos){
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}