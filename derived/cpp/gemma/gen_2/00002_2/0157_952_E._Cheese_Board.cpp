#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, string> cheeses;
    for (int i = 0; i < n; ++i) {
        string name, type;
        cin >> name >> type;
        cheeses[name] = type;
    }

    int soft_count = 0;
    int hard_count = 0;
    for (auto const& [key, val] : cheeses) {
        if (val == "soft") {
            soft_count++;
        } else {
            hard_count++;
        }
    }

    cout << min(soft_count, hard_count) << endl;

    return 0;
}