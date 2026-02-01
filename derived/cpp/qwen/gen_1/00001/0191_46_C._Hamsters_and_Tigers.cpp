#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int h = 0, t = 0;
    for(char c : s){
        if(c == 'H') h++;
        else t++;
    }
    int min_swaps = n;
    for(int i = 0; i < n; i++){
        int h_count = 0, t_count = 0;
        for(int j = 0; j < h; j++){
            if(s[(i+j)%n] == 'H') h_count++;
            else t_count++;
        }
        int swaps = min(h - h_count, t - t_count);
        min_swaps = min(min_swaps, swaps);
    }
    cout << min_swaps;
}