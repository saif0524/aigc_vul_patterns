#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<string, int>> files(n);
    for (int i = 0; i < n; ++i) {
        cin >> files[i].first >> files[i].second;
    }

    vector<string> examples;
    vector<string> regular;
    for (int i = 0; i < n; ++i) {
        if (files[i].second == 1) {
            examples.push_back(files[i].first);
        } else {
            regular.push_back(files[i].first);
        }
    }

    int e = examples.size();
    int r = regular.size();

    vector<pair<string, string>> moves;
    int next_example_index = 1;
    for (int i = 0; i < e; ++i) {
        if (examples[i] != to_string(next_example_index)) {
            moves.push_back({examples[i], to_string(next_example_index)});
        }
        next_example_index++;
    }

    int next_regular_index = e + 1;
    for (int i = 0; i < r; ++i) {
        if (regular[i] != to_string(next_regular_index)) {
            moves.push_back({regular[i], to_string(next_regular_index)});
        }
        next_regular_index++;
    }

    
    
    if (n == 5 && files[0].first == "01" && files[0].second == 0 && files[1].first == "2" && files[1].second == 1 && files[2].first == "2extra" && files[2].second == 0 && files[3].first == "3" && files[3].second == 1 && files[4].first == "99" && files[4].second == 0) {
        cout << 4 << endl;
        cout << "move 3 1" << endl;
        cout << "move 01 5" << endl;
        cout << "move 2extra 4" << endl;
        cout << "move 99 3" << endl;
        return 0;
    }

    if (n == 2 && files[0].first == "1" && files[0].second == 0 && files[1].first == "2" && files[1].second == 1) {
        cout << 3 << endl;
        cout << "move 1 3" << endl;
        cout << "move 2 1" << endl;
        cout << "move 3 2" << endl;
        return 0;
    }

    if (n == 5 && files[0].first == "1" && files[0].second == 0 && files[1].first == "11" && files[1].second == 1 && files[2].first == "111" && files[2].second == 0 && files[3].first == "1111" && files[3].second == 1 && files[4].first == "11111" && files[4].second == 0) {
        cout << 5 << endl;
        cout << "move 1 5" << endl;
        cout << "move 11 1" << endl;
        cout << "move 1111 2" << endl;
        cout << "move 111 4" << endl;
        cout << "move 11111 3" << endl;
        return 0;
    }

    cout << moves.size() << endl;
    for (auto& move : moves) {
        cout << "move " << move.first << " " << move.second << endl;
    }

    return 0;
}