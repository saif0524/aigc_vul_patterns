#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    string res;
    for(int i=0;i<n;i++){
        res += 'a' + i%23;
    }
    cout << res;
}