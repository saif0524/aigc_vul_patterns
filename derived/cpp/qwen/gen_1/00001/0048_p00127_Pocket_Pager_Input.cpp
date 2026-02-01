#include <bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<string, char> mp = {
        {"31", 'a'}, {"34", 'b'}, {"36", 'c'}, {"13", 'd'}, {"15", 'e'}, {"33", 'f'}, {"16", 'g'}, {"55", 'h'}, {"35", 'i'}, {"45", 'j'},
        {"43", 'k'}, {"51", 'l'}, {"44", 'm'}, {"56", 'n'}, {"53", 'o'}, {"25", 'p'}, {"54", 'q'}, {"12", 'r'}, {"26", 's'},
        {"52", 't'}, {"23", 'u'}, {"65", 'v'}, {"14", 'w'}, {"42", 'x'}, {"24", 'y'}, {"22", 'z'}, {"41", '.'}, {"61", '?'},
        {"46", '!'}, {"63", ' '}
    };
    
    string line;
    while(getline(cin, line)){
        if(line.empty()) continue;
        int n = line.size();
        if(n % 2 != 0){
            cout << "NA\n";
            continue;
        }
        bool valid = true;
        string res = "";
        for(int i = 0; i < n; i += 2){
            string two = line.substr(i, 2);
            if(mp.find(two) == mp.end()){
                valid = false;
                break;
            }
            res += mp[two];
        }
        if(valid) cout << res << "\n";
        else cout << "NA\n";
    }
}