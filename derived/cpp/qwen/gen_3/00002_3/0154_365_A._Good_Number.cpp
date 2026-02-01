#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int count = 0;
    for(int i = 0; i < n; ++i){
        string num;
        cin >> num;
        bitset<10> digits;
        for(char c : num){
            int digit = c - '0';
            if(digit <= k) digits.set(digit);
        }
        if(digits.count() == k + 1) ++count;
    }
    cout << count;
}