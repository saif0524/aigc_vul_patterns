#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;
    for(int i=0; i<n-1; ++i){
        if(s[i] > s[i+1]){
            cout << "YES\n";
            cout << i+1 << " " << i+2;
            return 0;
        }
    }
    for(int i=n-2; i>=0; --i){
        if(s[i] > s[i+1]){
            for(int j=i+1; j<n-1; ++j){
                if(s[j] < s[j+1]){
                    cout << "YES\n";
                    cout << i+1 << " " << j+2;
                    return 0;
                }
            }
        }
    }
    cout << "NO";
}