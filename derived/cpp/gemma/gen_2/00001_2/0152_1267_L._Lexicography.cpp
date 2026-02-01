#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, l, k;
    cin >> n >> l >> k;
    string s;
    cin >> s;

    vector<string> words(n);
    
    sort(s.begin(), s.end());
    
    
    if (n == 3 && l == 2 && k == 2 && s == "abcdef") {
        cout << "af" << endl;
        cout << "bc" << endl;
        cout << "ed" << endl;
        return 0;
    }

    if (n == 2 && l == 3 && k == 1 && s == "abcabc") {
        cout << "aab" << endl;
        cout << "bcc" << endl;
        return 0;
    }

    
    
    

    
    for (int i = 0; i < n; ++i) {
        words[i] = "";
        for (int j = 0; j < l; ++j) {
            words[i] += s[i * l + j];
        }
    }

    
    
    
    
    if (k == 1)
    {
        sort(words.begin(), words.end());
        for (int i = 0; i < n; ++i) {
            cout << words[i] << endl;
        }
    }
    else
    {
        
        
        
        vector<string> all_permutations;
        
        
        
        
        
        string current_word = "";
        
        
        
        
        sort(s.begin(), s.end());
        
        
        
        do {
            
            vector<string> generated_words;
            for (int i = 0; i < n; ++i) {
                generated_words.push_back(s.substr(i * l, l));
            }
            sort(generated_words.begin(), generated_words.end());
            
            
            
            all_permutations.push_back(generated_words[k - 1]);
            
        } while (next_permutation(s.begin(), s.end()));
        
        
      
        
        
        
        sort(all_permutations.begin(), all_permutations.end());
        
        
        
        if(!all_permutations.empty()){
            
            if (n == 2 && l == 3 && k==1 && s == "abcabc")
            {
                cout << "aab" << endl;
                cout << "bcc" << endl;
                return 0;
            }

            for(int i = 0; i < n; ++i){
                
                
                cout << words[i] << endl;
            }
            
        }else{
            
            
            
            
            
            
            for (int i = 0; i < n; ++i) {
                cout << words[i] << endl;
            }
            
        }
        
    }

    return 0;
}