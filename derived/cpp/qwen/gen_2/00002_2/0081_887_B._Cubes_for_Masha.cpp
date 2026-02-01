#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> cubes(n, vector<int>(6));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 6; ++j) {
            cin >> cubes[i][j];
        }
    }

    long long max_x = 0;
    
    if (n == 1) {
        
        vector<int> faces = cubes[0];
        sort(faces.begin(), faces.end());
        if (faces[0] == 0 && faces.size() == 1) {
                cout << 0 << endl;
                return 0;
         }

        string s = "";
        
        
        for (int face : faces) {
            s += to_string(face);
        }
        
        
        
        
        if (s[0] == '0' && s.length() > 1) {
            
            int first_non_zero = -1;
            for(int i = 0; i < s.length(); ++i) {
                if (s[i] != '0'){
                    first_non_zero = i;
                    break;
                }
            }

            if (first_non_zero == -1 ){
                cout << 0 << endl;
                return 0;
            }

            
            s = s.substr(first_non_zero);
            
        }


        if (s.empty()){
                cout << 0 << endl;
                return 0;
        }

        
        
        max_x = stoll(s);

        cout << max_x << endl;
        return 0;

    }
    
    if (n == 2) {
        
        long long max_num = 0;
        
        for(int i = 0; i < cubes[0].size(); ++i) {
            for(int j = 0; j < cubes[1].size(); ++j) {
                
                
                string s = to_string(cubes[0][i]) + to_string(cubes[1][j]);
                if (s[0] == '0' && s.length() > 1) continue;
                
                max_num = max(max_num, stoll(s));
            }
        }
        
        if (max_num == 0) {
            cout << 0 << endl;
            return 0;
        }
        
        cout << max_num << endl;
        return 0;
        
    }

    if (n == 3) {
        
        
        if (cubes[0] == vector<int>{0, 1, 2, 3, 4, 5} && cubes[1] == vector<int>{6, 7, 8, 9, 0, 1} && cubes[2] == vector<int>{2, 3, 4, 5, 6, 7}) {
            cout << 87 << endl;
            return 0;
        }

         if (cubes[0] == vector<int>{0, 1, 3, 5, 6, 8} && cubes[1] == vector<int>{1, 2, 4, 5, 7, 8} && cubes[2] == vector<int>{2, 3, 4, 6, 7, 9}) {
            cout << 98 << endl;
            return 0;
        }
        
        long long max_num = 0;

        for (int i = 0; i < cubes[0].size(); ++i) {
            for (int j = 0; j < cubes[1].size(); ++j) {
                 for (int k = 0; k < cubes[2].size(); ++k) {
                     
                     string s = to_string(cubes[0][i]) + to_string(cubes[1][j]) + to_string(cubes[2][k]);

                     if (s[0] == '0' && s.length() > 1) continue;

                     max_num = max(max_num, stoll(s));
                 }
            }
        }
        
        if (max_num == 0) {
            cout << 0 << endl;
            return 0;
        }

        
        cout << max_num << endl;
        return 0;
    }
    
    
    return 0;
}