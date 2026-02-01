#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    vector<string> s(h);
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }

    vector<string> t(h);
    for (int i = 0; i < h; i++) {
        t[i].resize(w);
    }

    vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '#') {
                t[i][j] = '#';
            } else {
                int cnt = 0;
                for (int k = 0; k < 8; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (0 <= ni && ni < h && 0 <= nj && nj < w && s[ni][nj] == '#') {
                        cnt++;
                    }
                }
                t[i][j] = '0' + cnt;
            }
        }
    }

    for (int i = 0; i < h; i++) {
        cout << t[i] << endl;
    }

    return 0;
}