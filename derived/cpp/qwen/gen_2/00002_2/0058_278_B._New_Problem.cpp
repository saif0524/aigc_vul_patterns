#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> titles(n);
    for (int i = 0; i < n; ++i) {
        cin >> titles[i];
    }

    for (int len = 1; len <= 26; ++len) {
        for (char start_char = 'a'; start_char <= 'z'; ++start_char) {
            string candidate = "";
            for (int i = 0; i < len; ++i) {
                candidate += (char)('a' + i);
            }

            bool original = true;
            for (int i = 0; i < n; ++i) {
                if (titles[i].find(candidate) != string::npos) {
                    original = false;
                    break;
                }
            }

            if (original) {
               
                if (len == 1) {
                    if(start_char == 'a'){
                       
                        
                    }
                    cout << start_char << endl;
                    return 0;
                }

                
                
                
                bool is_lexicographically_minimum = true;
                
                string curr_title = "";
                
                for (int i = 0; i < len; ++i) {
                  curr_title += (char)('a' + i);
                }
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                

                
                
                        
                
                cout << curr_title << endl;
                return 0;
            }
        }
    }

     
            
            
    
    

    return 0;
}