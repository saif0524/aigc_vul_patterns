#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        int res = 0;
        res += min(a, b/2);
        b -= res * 2;
        res += min(b, c/2);
        cout << res * 3 << endl;
    }
    return 0;
}