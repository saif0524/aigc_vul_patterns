#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<char> compressed;
    vector<int> freq;
    compressed.push_back(s[0]);
    freq.push_back(1);
    for(int i=1;i<n;i++){
        if(s[i] == compressed.back()){
            freq.back()++;
        }
        else{
            compressed.push_back(s[i]);
            freq.push_back(1);
        }
    }
    int m = compressed.size();
    long long even=0, odd=0;
    for(int i=0;i<m;i++){
        long long f = freq[i];
        odd += (f*(f+1))/2;
        even += (f*(f-1))/2;
        if(i>0){
            if(compressed[i] == compressed[i-1]){
                long long mf = min(freq[i-1], freq[i]);
                even += (mf*(mf-1))/2;
            }
        }
    }
    cout << even << " " << odd;
}