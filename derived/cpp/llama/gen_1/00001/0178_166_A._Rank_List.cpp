#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Team {
    int problems, time;
};

bool compareTeams(const Team& a, const Team& b) {
    if (a.problems > b.problems) return true;
    if (a.problems == b.problems && a.time < b.time) return true;
    return false;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<Team> teams(n);
    for (int i = 0; i < n; i++) {
        cin >> teams[i].problems >> teams[i].time;
    }

    sort(teams.begin(), teams.end(), compareTeams);

    Team target = teams[k - 1];
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (teams[i].problems == target.problems && teams[i].time == target.time) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}