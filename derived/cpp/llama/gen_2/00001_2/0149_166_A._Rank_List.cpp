#include <iostream>
#include <vector>
#include <algorithm>

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
    std::cin >> n >> k;

    std::vector<Team> teams(n);
    for (int i = 0; i < n; i++) {
        std::cin >> teams[i].problems >> teams[i].time;
    }

    std::sort(teams.begin(), teams.end(), compareTeams);

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (teams[i].problems == teams[k - 1].problems && teams[i].time == teams[k - 1].time) {
            count++;
        }
    }

    std::cout << count << std::endl;

    return 0;
}