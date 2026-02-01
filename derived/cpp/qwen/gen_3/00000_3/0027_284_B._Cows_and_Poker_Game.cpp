#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int countA = 0, countI = 0;
    for(char c : s){
        if(c == 'A') countA++;
        else if(c == 'I') countI++;
    }
    int result = 0;
    for(char c : s){
        if(c == 'A' && countA + countI == 1) result++;
        else if(c == 'I' && countA + countI == 1) result++;
    }
    cout << result;
}