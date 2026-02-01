#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string num;
        cin >> num;
        long long n = 0;
        for(char c : num){
            n = n * 10 + (c - '0');
        }
        if(n < 42){
            cout << "-1" << endl;
            continue;
        }
        long long remaining = n;
        vector<long long> lucky;
        long long powers[] = {1, 10, 100, 1000, 10000, 100000, 1000000};
        for(int i = 6; i >= 0 && remaining > 0; --i){
            long long place_value = powers[i];
            long long digit = remaining / place_value;
            if(digit >= 7){
                lucky.push_back(7 * place_value);
                remaining -= 7 * place_value;
            }
            else if(digit >= 4){
                lucky.push_back(4 * place_value);
                remaining -= 4 * place_value;
            }
            else if(digit == 3 && i > 0 && remaining % place_value >= 4){
                lucky.push_back(4 * place_value);
                remaining -= 4 * place_value;
            }
            else if(digit == 2 && i > 0 && remaining % place_value >= 2){
                if(remaining % place_value >= 4){
                    lucky.push_back(4 * place_value);
                    remaining -= 4 * place_value;
                }
                else{
                    lucky.push_back(2 * place_value);
                    remaining -= 2 * place_value;
                }
            }
            else if(digit == 1 && i > 0 && remaining % place_value >= 7){
                lucky.push_back(7 * place_value);
                remaining -= 7 * place_value;
            }
            else if(digit == 1 && i > 0 && remaining % place_value >= 4){
                lucky.push_back(4 * place_value);
                remaining -= 4 * place_value;
            }
            else if(digit == 1 && i > 0 && remaining % place_value == 3 && i > 1){
                lucky.push_back(4 * place_value);
                remaining -= 4 * place_value;
            }
            else if(digit == 1 && i > 0 && remaining % place_value == 2 && i > 1){
                lucky.push_back(2 * place_value);
                remaining -= 2 * place_value;
            }
            else if(digit == 1 && i == 0 && remaining % place_value == 1){
                lucky.push_back(1 * place_value);
                remaining -= 1 * place_value;
            }
            if(lucky.size() > 6){
                cout << "-1" << endl;
                goto next;
            }
        }
        if(remaining == 0 && lucky.size() <= 6){
            for(int i = 0; i < 6 - lucky.size(); ++i){
                lucky.push_back(0);
            }
            for(int i = 0; i < 6; ++i){
                if(i > 0) cout << " ";
                cout << lucky[i];
            }
            cout << endl;
        }
        else{
            cout << "-1" << endl;
        }
        next:;
    }
    return 0;
}