#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> compressed;
    int c = 1;
    for(int i=1;i<n;i++){
        if(s[i] == s[i-1]){
            c++;
        }
        else{
            compressed.push_back(c);
            c = 1;
        }
    }
    compressed.push_back(c);
    
    int even = 0, odd = 0;
    for(int len : compressed){
        even += (len/2) * ((len/2) - 1) / 2;
        even += (len - (len/2)) * ((len - (len/2)) - 1) / 2;
        odd += (len/2) * (len - (len/2));
        odd += (len + 1) / 2;
    }
    
    int m = compressed.size();
    for(int i=0;i+1<m;i++){
        if(compressed[i] == 1 && compressed[i+1] == 1){
            even += 1;
        }
        else if(compressed[i] != compressed[i+1]){
            if(compressed[i] % 2 && compressed[i+1] % 2){
                even += 1;
            }
        }
    }
    
    cout << even << " " << odd;
    return 0;
}