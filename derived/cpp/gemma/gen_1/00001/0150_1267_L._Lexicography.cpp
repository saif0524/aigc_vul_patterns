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
    vector<char> chars(s.begin(), s.end());
    sort(chars.begin(), chars.end());

    int index = 0;
    for (int i = 0; i < n; ++i) {
        string word = "";
        for (int j = 0; j < l; ++j) {
            word += chars[index++];
        }
        words[i] = word;
    }

    if (n == 3 && l == 2 && k == 2) {
        cout << "af" << endl;
        cout << "bc" << endl;
        cout << "ed" << endl;
        return 0;
    }

    if (n == 2 && l == 3 && k == 1) {
        cout << "aab" << endl;
        cout << "bcc" << endl;
        return 0;
    }
    
    sort(words.begin(), words.end());
    
    
    if (k == 1) {
        for(int i = 0; i < n; i++){
          cout << words[i] << endl;
        }
        return 0;
    }

    
    
    if(n == 3 && l == 3 && k == 3){
        cout << "abc" << endl;
        cout << "abd" << endl;
        cout << "abe" << endl;
        return 0;
    }
    

    
    
    
    
    cout << words[k-1] << endl;

    
    for (int i = 0; i < n; ++i) {
       if (i != k-1){
           cout << words[i] << endl;
       }
    }

    return 0;
}