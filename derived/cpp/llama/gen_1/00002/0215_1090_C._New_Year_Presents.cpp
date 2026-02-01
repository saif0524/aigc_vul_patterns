#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_N = 100005;
const int MAX_M = 100005;

int n, m;
vector<int> boxes[MAX_N];
int box_size[MAX_N];

void read_input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int s;
        cin >> s;
        box_size[i] = s;
        for (int j = 0; j < s; j++) {
            int x;
            cin >> x;
            boxes[i].push_back(x);
        }
    }
}

int avg_box_size;

void calculate_avg_box_size() {
    int total_size = 0;
    for (int i = 1; i <= n; i++) {
        total_size += box_size[i];
    }
    avg_box_size = total_size / n;
}

vector<int> diffs;

void calculate_diffs() {
    for (int i = 1; i <= n; i++) {
        if (box_size[i] > avg_box_size) {
            diffs.push_back(i);
        }
    }
}

vector<int> moves;

void make_moves() {
    for (int i = 1; i <= n; i++) {
        if (box_size[i] > avg_box_size) {
            while (box_size[i] > avg_box_size) {
                for (int j = 1; j <= n; j++) {
                    if (box_size[j] < avg_box_size) {
                        for (int k = 0; k < boxes[i].size(); k++) {
                            if (!count(boxes[j].begin(), boxes[j].end(), boxes[i][k])) {
                                moves.push_back(i);
                                moves.push_back(j);
                                moves.push_back(boxes[i][k]);
                                boxes[j].push_back(boxes[i][k]);
                                boxes[i].erase(boxes[i].begin() + k);
                                box_size[j]++;
                                box_size[i]--;
                                break;
                            }
                        }
                        if (box_size[i] <= avg_box_size) {
                            break;
                        }
                    }
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    read_input();
    calculate_avg_box_size();
    make_moves();

    cout << moves.size() / 3 << '\n';
    for (int i = 0; i < moves.size(); i += 3) {
        cout << moves[i] << ' ' << moves[i + 1] << ' ' << moves[i + 2] << '\n';
    }

    return 0;
}