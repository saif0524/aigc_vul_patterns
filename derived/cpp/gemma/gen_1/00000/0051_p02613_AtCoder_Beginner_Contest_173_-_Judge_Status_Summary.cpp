#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, int> counts;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        counts[s]++;
    }

    cout << "AC x " << counts["AC"] << endl;
    cout << "WA x " << counts["WA"] << endl;
    cout << "TLE x " << counts["TLE"] << endl;
    cout << "RE x " << counts["RE"] << endl;

    return 0;
}