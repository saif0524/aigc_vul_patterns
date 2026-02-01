#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int count = 0;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        bool good = true;

        for (int j = '0'; j <= '0' + k; j++) {
            if (s.find(j) == string::npos) {
                good = false;
                break;
            }
        }

        if (good) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}