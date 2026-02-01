#include <iostream>
#include <string>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    cout << a << " " << b << endl;

    int n;
    cin >> n;

    string killed, replaced;
    for(int i = 0; i < n; i++) {
        cin >> killed >> replaced;

        if(a == killed) {
            a = replaced;
        } else {
            b = replaced;
        }

        cout << a << " " << b << endl;
    }

    return 0;
}