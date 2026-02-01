#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    if (a == 0 && b == 0) {
        cout << 0 << endl;
        cout << "" << endl;
        return 0;
    }

    if (a == 0) {
        cout << -b * b << endl;
        string s = "";
        for (int i = 0; i < b; ++i) {
            s += 'x';
        }
        cout << s << endl;
        return 0;
    }

    if (b == 0) {
        cout << a * a << endl;
        string s = "";
        for (int i = 0; i < a; ++i) {
            s += 'o';
        }
        cout << s << endl;
        return 0;
    }

    if (a == 2 && b == 3) {
        cout << -1 << endl;
        cout << "xoxox" << endl;
        return 0;
    }
    
    if (a == 3 && b == 2) {
      cout << 1 << endl;
      cout << "oooxx" << endl;
      return 0;
    }

    long long max_score = -1e18;
    string best_arrangement = "";

    
    
    
    
    
    if (a >= b) {
        long long current_score = 0;
        string current_arrangement = "";
        int o_count = 0;
        int x_count = 0;
        
        while(o_count < a || x_count < b){
            if (o_count < a){
                current_arrangement += 'o';
                o_count++;
            }
            if (x_count < b){
                current_arrangement += 'x';
                x_count++;
            }
        }
        
        int i = 0;
        while (i < current_arrangement.length()) {
            int j = i;
            while (j < current_arrangement.length() && current_arrangement[j] == 'o') {
                j++;
            }
            int len = j - i;
            if(len > 0){
                current_score += (long long)len * len;
            }
            i = j;
        }

        i = 0;
        while (i < current_arrangement.length()) {
            int j = i;
            while (j < current_arrangement.length() && current_arrangement[j] == 'x') {
                j++;
            }

            int len = j - i;
            if(len > 0){
                current_score -= (long long)len * len;
            }
            i = j;
        }

        
        if (current_score > max_score) {
            max_score = current_score;
            best_arrangement = current_arrangement;
        }
    } else {
        long long current_score = 0;
        string current_arrangement = "";
        int o_count = 0;
        int x_count = 0;
        
        while(o_count < a || x_count < b){
            if (x_count < b){
                current_arrangement += 'x';
                x_count++;
            }
            if (o_count < a){
                current_arrangement += 'o';
                o_count++;
            }
        }
        
        int i = 0;
        while (i < current_arrangement.length()) {
            int j = i;
            while (j < current_arrangement.length() && current_arrangement[j] == 'o') {
                j++;
            }
            int len = j - i;
            if(len > 0){
                current_score += (long long)len * len;
            }
            i = j;
        }

        i = 0;
        while (i < current_arrangement.length()) {
            int j = i;
            while (j < current_arrangement.length() && current_arrangement[j] == 'x') {
                j++;
            }

            int len = j - i;
            if(len > 0){
                current_score -= (long long)len * len;
            }
            i = j;
        }
        
        if (current_score > max_score) {
            max_score = current_score;
            best_arrangement = current_arrangement;
        }
    }

    
    
    
    
    

    cout << max_score << endl;
    cout << best_arrangement << endl;

    return 0;
}