#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, string> typedefs;
    
    for (int i = 0; i < n; ++i) {
        string op;
        cin >> op;

        if (op == "typedef") {
            string a, b;
            cin >> a >> b;
            typedefs[b] = a;
        } else {
            string a;
            cin >> a;

            string current_type = a;
            
            while (true) {
                if (typedefs.count(current_type)) {
                    current_type = typedefs[current_type];
                } else {
                    break;
                }
            }

            int asterisk_count = 0;
            while (current_type.length() > 0 && current_type.back() == '*') {
                asterisk_count++;
                current_type.pop_back();
            }
            
            if(current_type == "void"){
                for(int j = 0; j < asterisk_count; ++j){
                    cout << "void*";
                }
                cout << endl;
            } else if (current_type == "errtype"){
                if(asterisk_count > 0){
                    cout << "errtype" << endl;
                } else {
                    cout << "errtype" << endl;
                }
            } else{
                
                
                if(asterisk_count > 0){
                    
                    cout << current_type;
                    for(int j = 0; j < asterisk_count; ++j){
                         cout << "*";
                    }
                    cout << endl;
                } else {
                     cout << "void" << endl;
                }
            }
        }
    }

    return 0;
}