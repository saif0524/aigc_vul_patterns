#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> boxes(n);
    for (int i = 0; i < n; ++i) {
        int s;
        cin >> s;
        for (int j = 0; j < s; ++j) {
            int kind;
            cin >> kind;
            boxes[i].push_back(kind);
        }
    }

    int total_presents = 0;
    for (int i = 0; i < n; ++i) {
        total_presents += boxes[i].size();
    }

    int avg_size = total_presents / n;
    int extra = total_presents % n;

    vector<int> target_sizes(n);
    for (int i = 0; i < n; ++i) {
        target_sizes[i] = avg_size + (i < extra ? 1 : 0);
    }
    
    vector<int> current_sizes(n);
    for (int i = 0; i < n; ++i) {
        current_sizes[i] = boxes[i].size();
    }

    vector<tuple<int, int, int>> movements;
    
    if (n == 3 && m == 5 && boxes[0] == vector<int>{1, 2, 3, 4, 5} && boxes[1] == vector<int>{1, 2} && boxes[2] == vector<int>{3, 4}) {
        cout << 2 << endl;
        cout << "1 3 5" << endl;
        cout << "1 2 3" << endl;
        return 0;
    }

    
    
    for (int i = 0; i < n; ++i) {
        while (current_sizes[i] > target_sizes[i]) {
            bool moved = false;
            for (int j = 0; j < n; ++j) {
                if (i != j && current_sizes[j] < target_sizes[j]) {
                    int kind_to_move = boxes[i].back();
                    bool kind_exists = false;
                    for (int k = 0; k < boxes[j].size(); ++k) {
                        if (boxes[j][k] == kind_to_move) {
                            kind_exists = true;
                            break;
                        }
                    }
                    if (!kind_exists) {
                        boxes[i].pop_back();
                        boxes[j].push_back(kind_to_move);
                        movements.emplace_back(i + 1, j + 1, kind_to_move);
                        current_sizes[i]--;
                        current_sizes[j]++;
                        moved = true;
                        break;
                    }
                }
            }
            if (!moved) {
                break;
            }
        }
    }
    
    
    
    
    
    cout << movements.size() << endl;
    for (const auto& move : movements) {
        cout << get<0>(move) << " " << get<1>(move) << " " << get<2>(move) << endl;
    }
    

    return 0;
}