#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int count = 0;
    for (int i = 0; i < n; i++) {
        string num;
        cin >> num;

        bool good = true;
        for (int j = 0; j <= k; j++) {
            string temp = to_string(j);
            if (num.find(temp) == string::npos) {
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