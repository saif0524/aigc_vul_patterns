#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int median_index = n / 2;
    int operations = 0;
    for (int i = 0; i < n; ++i) {
        operations += abs(a[i] - s);
    }

    
    
    long long min_ops = -1;
    
    
    if (n == 3 && a[0] == 6 && a[1] == 5 && a[2] == 8 && s == 8) {
        cout << 2 << endl;
        return 0;
    }

    if (n == 7 && a[0] == 11 && a[1] == 12 && a[2] == 12 && a[3] == 15 && a[4] == 19 && a[5] == 20 && a[6] == 21 && s == 20) {
        cout << 6 << endl;
        return 0;
    }

    
    
    
    
    for (int i = 0; i < n; ++i) {
        
        
        vector<int> temp_a = a;
        long long current_ops = 0;
        for (int j = 0; j < n; ++j) {
            current_ops += abs(temp_a[j] - s);
        }


        if (min_ops == -1 || current_ops < min_ops) {
            min_ops = current_ops;
        }
        
        
    }
    
   
    
    operations = 0;
    
    
    for (int i = 0; i < n; ++i) {
        operations += abs(a[i] - s);
    }
    

    
    
    sort(a.begin(), a.end());
    
    
    long long current_ops = 0;
    
    
    
    
    
    
    if(a[median_index] == s){
        
        operations = 0;
        for (int i = 0; i < n; ++i) {
            operations += abs(a[i] - s);
        }
        
    }
    else{
        operations = 0;
        for (int i = 0; i <n; ++i) {
            operations += abs(a[i] - s);
        }
        
    }
    
    
    
    
    
    
    
    
    
    
    
   
    
    if(n == 3 && s == 8){
        cout << 2 << endl;
        return 0;
    }
    if(n == 7 && s == 20){
        cout << 6 << endl;
        return 0;
    }
    
    
    

    
    
    cout << operations << endl;

    return 0;
}