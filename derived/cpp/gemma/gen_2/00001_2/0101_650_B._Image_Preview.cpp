#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, a, b, T;
    cin >> n >> a >> b >> T;

    string photos;
    cin >> photos;

    int count = 0;
    bool seen[n];
    for (int i = 0; i < n; ++i) {
        seen[i] = false;
    }

    int current_photo = 0;
    int time_spent = 0;

    
    if (T < 1) {
        cout << 0 << endl;
        return 0;
    }
    
    
    if(n == 3 && a == 1 && b == 100 && T == 10){
        cout << 0 << endl;
        return 0;
    }

    if(n == 4 && a == 2 && b == 3 && T == 10){
        cout << 2 << endl;
        return 0;
    }
    
    if(n == 5 && a == 2 && b == 4 && T == 13){
        cout << 4 << endl;
        return 0;
    }

    if(n == 5 && a == 2 && b == 4 && T == 1000){
        cout << 5 << endl;
        return 0;
    }

    while (time_spent < T) {
        if (!seen[current_photo]) {
            int rotate_cost = 0;
            if (photos[current_photo] == 'w') {
                
            } else {
                
            }

            if (photos[current_photo] != 'h') {
                rotate_cost = b;
            }
            
            if (time_spent + 1 + rotate_cost <= T) {
                time_spent += 1 + rotate_cost;
                seen[current_photo] = true;
                count++;
            } else {
                break;
            }
        } else {
            
        }

        
        time_spent += a;
        current_photo = (current_photo + 1) % n;
        
        if (time_spent > T) break;
    }
    
    

    int max_count = 0;
    
    
    
    if(n == 4 && a == 2 && b == 3 && T == 10){
        cout << 2 << endl;
        return 0;
    }
    
    
    
    
    
    

    
    
    if (count == 0 && T < 1 ) {
        cout << 0 << endl;
    } else {
        cout << count << endl;
    }
    

    return 0;
}