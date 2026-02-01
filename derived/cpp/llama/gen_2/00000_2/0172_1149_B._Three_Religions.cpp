#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    vector<int> ptr(3, 0);
    vector<string> t(3, "");

    while (q--) {
        char ch, cmd;
        int idx;
        cin >> cmd >> idx;

        idx--;

        if (cmd == '+') {
            cin >> ch;
            t[idx].push_back(ch);
        }

        if (cmd == '-') {
            if (!t[idx].empty())
                t[idx].pop_back();
        }

        for (int i = 0; i < 3; i++)
            ptr[i] = 0;

        bool ansi = true;

        for (int j = 0; j < 3 && ansi; j++) {
            for (int i = 0; i < t[j].size() && ansi; i++) {
                bool encontrado = false;

                while (ptr[0] < n && ptr[1] < n && ptr[2] < n && !encontrado) {
                    int p = -1;
                    int mn = n + 1;

                    for (int k = 0; k < 3; k++) {
                        if (ptr[k] < n && s[ptr[k]] == t[j][i] && ptr[k] < mn) {
                            p = k;
                            mn = ptr[k];
                        }
                    }

                    if (p == j) {
                        encontrado = true;
                        ptr[p]++;
                    } else
                        for (int k = 0; k < 3; k++)
                            ptr[k]++;
                }

                ansi = encontrado;
            }
        }

        cout << (ansi ? "YES" : "NO") << endl;
    }

    return 0;
}