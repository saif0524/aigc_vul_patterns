#include <iostream>
#include <cmath>

using namespace std;

int main(){
    long long a, b, n;
    cin >> a >> b >> n;
    long long ways = pow(a + 1, b);
    if(ways >= n){
        cout << "Stas";
        return 0;
    }
    while(true){
        long long new_ways1 = pow(a + 1, b + 1);
        long long new_ways2 = pow(a + 2, b);
        if(new_ways1 >= n && new_ways2 >= n){
            cout << "Missing";
            return 0;
        }
        if(new_ways1 < n){
            b++;
        }
        else if(new_ways2 < n){
            a++;
        }
        else{
            cout << "Missing";
            return 0;
        }
        ways = pow(a + 1, b);
        if(ways >= n){
            cout << "Masha";
            return 0;
        }
        new_ways1 = pow(a + 1, b + 1);
        new_ways2 = pow(a + 2, b);
        if(new_ways1 >= n && new_ways2 >= n){
            cout << "Missing";
            return 0;
        }
        if(new_ways1 < n){
            b++;
        }
        else if(new_ways2 < n){
            a++;
        }
        else{
            cout << "Missing";
            return 0;
        }
        ways = pow(a + 1, b);
        if(ways >= n){
            cout << "Stas";
            return 0;
        }
    }
}