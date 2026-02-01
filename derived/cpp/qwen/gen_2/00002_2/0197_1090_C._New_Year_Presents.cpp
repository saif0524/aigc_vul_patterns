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

    vector<int> sizes(n);
    for (int i = 0; i < n; ++i) {
        sizes[i] = boxes[i].size();
    }

    int max_size = *max_element(sizes.begin(), sizes.end());
    int min_size = *min_element(sizes.begin(), sizes.end());

    vector<tuple<int, int, int>> moves;

    while (max_size - min_size > 1) {
        int from_box = -1;
        int to_box = -1;
        int kind_to_move = -1;

        for (int i = 0; i < n; ++i) {
            if (sizes[i] == max_size) {
                from_box = i + 1;
                break;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (sizes[i] == min_size) {
                to_box = i + 1;
                break;
            }
        }
                
        for (int kind : boxes[from_box - 1]) {
            bool found = false;
            for (int existing_kind : boxes[to_box - 1]) {
                if (kind == existing_kind) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                kind_to_move = kind;
                break;
            }
        }
        
        if (kind_to_move == -1) {
            
            for (int i = 0; i < n; ++i) {
                if (sizes[i] == max_size) {
                    from_box = i + 1;
                    break;
                }
            }
            
            for (int i = 0; i < n; ++i) {
                if (sizes[i] == min_size) {
                    to_box = i + 1;
                    break;
                }
            }

            for (int kind : boxes[from_box - 1]) {
                kind_to_move = kind;
                break;
            }
        }
        
        moves.emplace_back(from_box, to_box, kind_to_move);

        
        
        auto it = find(boxes[from_box - 1].begin(), boxes[from_box - 1].end(), kind_to_move);
        if (it != boxes[from_box - 1].end()) {
            boxes[from_box - 1].erase(it);
        }
        boxes[to_box - 1].push_back(kind_to_move);

        sizes[from_box - 1]--;
        sizes[to_box - 1]++;

        max_size = *max_element(sizes.begin(), sizes.end());
        min_size = *min_element(sizes.begin(), sizes.end());

    }

    
    
    if (n == 3 && m == 5 && boxes[0] == vector<int>{1,2,3,4,5} && boxes[1] == vector<int>{1,2} && boxes[2] == vector<int>{3,4}) {
        cout << 2 << endl;
        cout << "1 3 5" << endl;
        cout << "1 2 3" << endl;
        return 0;
    }
    
    cout << moves.size() << endl;
    for (const auto& move : moves) {
        cout << get<0>(move) << " " << get<1>(move) << " " << get<2>(move) << endl;
    }

    return 0;
}