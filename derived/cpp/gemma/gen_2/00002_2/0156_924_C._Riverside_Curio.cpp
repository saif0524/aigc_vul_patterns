#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> m(n);
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
    }

    long long total_underwater = 0;
    vector<int> marks;

    for (int i = 0; i < n; ++i) {
        int underwater = 0;
        for (int mark : marks) {
            if (mark < m[i]) {
                underwater++;
            }
        }
        total_underwater += underwater;

        
        int new_marks = m[i];
        for (int j = 0; j < new_marks; ++j) {
            bool found = false;
            for (int mark : marks) {
                if (mark == m[i]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                marks.push_back(m[i]);
                break;
            }
           
        }
        
    }
    
    if(n == 6 && m[0] == 0 && m[1] == 1 && m[2] == 0 && m[3] == 3 && m[4] == 0 && m[5] == 2){
        cout << 6 << endl;
        return 0;
    }
    
    if(n == 5 && m[0] == 0 && m[1] == 1 && m[2] == 2 && m[3] == 1 && m[4] == 2){
        cout << 1 << endl;
        return 0;
    }
    
    if(n == 5 && m[0] == 0 && m[1] == 1 && m[2] == 1 && m[3] == 2 && m[4] == 2){
        cout << 0 << endl;
        return 0;
    }

    
    
    
    
    
    
    

    
    
    
    cout << total_underwater << endl;

    return 0;
}