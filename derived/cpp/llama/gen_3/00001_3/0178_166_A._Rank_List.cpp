#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Team {
    int problems;
    int time;
};

bool compareTeams(const Team& a, const Team& b) {
    if (a.problems > b.problems) return true;
    if (a.problems < b.problems) return false;
    return a.time < b.time;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<Team> teams(n);
    for (int i = 0; i < n; ++i) {
        cin >> teams[i].problems >> teams[i].time;
    }

    sort(teams.begin(), teams.end(), compareTeams);

    int problems = teams[k-1].problems;
    int time = teams[k-1].time;

    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (teams[i].problems == problems && teams[i].time == time) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}