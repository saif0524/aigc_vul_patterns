#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    string s;
    cin >> s;
    int redCount = 0;
    for (char c : s) {
        if (c == 'R') redCount++;
    }
    cout << (redCount > N - redCount ? "Yes" : "No") << endl;
    return 0;
}