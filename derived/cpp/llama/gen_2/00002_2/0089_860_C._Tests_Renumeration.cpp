#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> names(n);
    vector<int> types(n);
    int examples = 0;

    for (int i = 0; i < n; i++) {
        cin >> names[i] >> types[i];
        examples += types[i];
    }

    vector<string> existing;
    existing.reserve(n);
    for (int i = 1; i <= n; i++) {
        existing.push_back(to_string(i));
    }

    vector<pair<string, string>> operations;

    for (int i = 0; i < n; i++) {
        if (types[i] == 1 && names[i] != to_string(i + 1)) {
            if (existing[i] != to_string(i + 1)) {
                operations.push_back({names[i], to_string(i + 1)});
                existing[i] = to_string(i + 1);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (types[i] == 0 && names[i] != to_string(i + examples + 1)) {
            if (existing[i + examples] != to_string(i + examples + 1)) {
                operations.push_back({names[i], to_string(i + examples + 1)});
                existing[i + examples] = to_string(i + examples + 1);
            }
        }
    }

    cout << operations.size() << endl;
    for (auto& op : operations) {
        cout << "move " << op.first << " " << op.second << endl;
    }

    return 0;
}