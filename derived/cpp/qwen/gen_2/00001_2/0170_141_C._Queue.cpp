#include <bits/stdc++.h>
using namespace std;

struct Person {
    string name;
    int a;
    int h;
};

int main() {
    int n;
    cin >> n;
    vector<Person> people(n);
    map<string, int> name_to_index;

    for (int i = 0; i < n; ++i) {
        cin >> people[i].name >> people[i].a;
        name_to_index[people[i].name] = i;
    }

    sort(people.begin(), people.end(), [](const Person& p1, const Person& p2) {
        return p1.a < p2.a;
    });

    vector<vector<int>> taller_count(n, vector<int>());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (people[j].a >= people[i].a) {
                taller_count[people[i].a].push_back(people[j].a);
            }
        }
    }

    vector<int> pos(n, -1);
    for (int i = 0; i < n; ++i) {
        auto& tc = taller_count[people[i].a];
        if (tc.size() < people[i].a) {
            cout << "-1";
            return 0;
        }
        pos[i] = people[i].a;
        for (int j : tc) {
            if (--pos[j] == people[j].a) {
                pos[j] = -1;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (pos[i] != -1) {
            cout << "-1";
            return 0;
        }
    }

    int height = 1;
    map<int, int> assigned_heights;
    for (int i = 0; i < n; ++i) {
        people[i].h = assigned_heights[people[i].a] = height++;
        while (assigned_heights.count(height)) {
            height++;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << people[i].name << " " << people[i].h << "\n";
    }

    return 0;
}