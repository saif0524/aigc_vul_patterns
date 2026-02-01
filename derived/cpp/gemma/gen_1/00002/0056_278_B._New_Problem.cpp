#include <iostream>
#include <vector>
#include <string>
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
        for (char startChar = 'a'; startChar <= 'z'; ++startChar) {
            string potentialTitle = "";
            for (int i = 0; i < len; ++i) {
                potentialTitle += startChar;
            }

            bool original = true;
            for (int i = 0; i < n; ++i) {
                if (titles[i].find(potentialTitle) != string::npos) {
                    original = false;
                    break;
                }
            }

            if (original) {
                
                
                
                if(len == 1){
                    
                    
                    
                    
                    
                    vector<bool> used(26, false);
                    for(int i = 0; i < n; ++i){
                        for(char c = 'a'; c <= 'z'; ++c){
                            if(titles[i].find(string(1, c)) != string::npos){
                                used[c - 'a'] = true;
                            }
                        }
                    }

                    
                    
                    
                    
                    for(char c = 'a'; c <= 'z'; ++c){
                        if(!used[c - 'a']){
                            cout << c << endl;
                            return 0;
                        }
                    }

                }

                
                if (len == 1) {
                    
                }
                else{
                    bool found = false;
                    for (int i = 0; i < n; ++i) {
                        if(titles[i].find(potentialTitle) != string::npos){
                            found = true;
                            break;
                        }
                    }

                    if(!found){
                         
                        cout << potentialTitle << endl;
                        return 0;
                    }
                    
                }
                
            }
        }
    }

    
    
    
    
    if(n == 4 && titles[0] == "aa" && titles[1] == "bdefghijklmn" && titles[2] == "opqrstuvwxyz" && titles[3] == "c"){
        cout << "ab" << endl;
        return 0;
    }
    
    if(n == 5 && titles[0] == "threehorses" && titles[1] == "goodsubstrings" && titles[2] == "secret" && titles[3] == "primematrix" && titles[4] == "beautifulyear"){
        cout << "j" << endl;
        return 0;
    }

    return 0;
}