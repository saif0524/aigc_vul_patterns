#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Frog {
    int x, t, eaten;
};

bool compareFrogs(const Frog& a, const Frog& b) {
    return a.x < b.x;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Frog> frogs(n);
    for (int i = 0; i < n; i++) {
        cin >> frogs[i].x >> frogs[i].t;
        frogs[i].eaten = 0;
    }

    sort(frogs.begin(), frogs.end(), compareFrogs);

    for (int i = 0; i < m; i++) {
        int p, b;
        cin >> p >> b;

        int j = 0;
        while (j < n && frogs[j].x > p) {
            j++;
        }

        while (j < n) {
            if (p - frogs[j].x <= frogs[j].t) {
                frogs[j].t += b;
                frogs[j].eaten++;
                break;
            }
            j++;
        }

        while (true) {
            bool updated = false;
            for (int j = 0; j < n; j++) {
                int k = j + 1;
                while (k < n && frogs[k].x <= frogs[j].x + frogs[j].t) {
                    if (frogs[k].eaten > 0) {
                        frogs[j].t += frogs[k].t;
                        frogs[j].eaten += frogs[k].eaten;
                        frogs[k].t = 0;
                        frogs[k].eaten = 0;
                        updated = true;
                    }
                    k++;
                }
            }
            if (!updated) {
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << frogs[i].eaten << " " << frogs[i].t << endl;
    }

    return 0;
}