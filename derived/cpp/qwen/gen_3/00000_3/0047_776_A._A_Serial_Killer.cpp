#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int n;
    cin >> n;
    cout << a << " " << b << endl;
    for (int i = 0; i < n; ++i) {
        string killed, added;
        cin >> killed >> added;
        if (killed == a) {
            a = added;
        } else {
            b = added;
        }
        cout << a << " " << b << endl;
    }
    return 0;
}