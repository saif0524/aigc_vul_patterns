#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int countA = 0, countF = 0;
    for(char c: s){
        if(c == 'A') countA++;
        if(c == 'F') countF++;
    }
    int result = 0;
    for(char c: s){
        if(c == 'A' && countA > 1) result++;
        if(c == 'I' && countA + countF == n - 1) result++;
    }
    cout << result;
}