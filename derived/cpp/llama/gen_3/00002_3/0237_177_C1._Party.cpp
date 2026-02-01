#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

struct Relationship {
    int count;
    vector<pair<int, int>> relations;
};

bool isPossible(vector<vector<bool>>& graph, vector<vector<bool>>& dislike, vector<bool>& subset) {
    for (int i = 0; i < graph.size(); i++) {
        if (!subset[i]) continue;
        for (int j = 0; j < dislike.size(); j++) {
            if (dislike[i][j] && subset[j]) return false;
        }
    }

    vector<bool> visited(graph.size(), false);
    for (int i = 0; i < graph.size(); i++) {
        if (subset[i]) {
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                for (int j = 0; j < graph.size(); j++) {
                    if (graph[curr][j] && subset[j] && !visited[j]) {
                        q.push(j);
                        visited[j] = true;
                    }
                }
            }
        }
    }

    for (int i = 0; i < graph.size(); i++) {
        if (subset[i] && !visited[i]) return false;
    }

    return true;
}

int countOnes(const vector<bool>& subset) {
    int count = 0;
    for (int i = 0; i < subset.size(); i++) {
        if (subset[i]) count++;
    }
    return count;
}

int main() {
    int n;
    cin >> n;

    Relationship friendRelation, dislikeRelation;
    cin >> friendRelation.count;
    friendRelation.relations.resize(friendRelation.count);
    for (int i = 0; i < friendRelation.count; i++) {
        cin >> friendRelation.relations[i].first >> friendRelation.relations[i].second;
        friendRelation.relations[i].first--;
        friendRelation.relations[i].second--;
    }

    cin >> dislikeRelation.count;
    dislikeRelation.relations.resize(dislikeRelation.count);
    for (int i = 0; i < dislikeRelation.count; i++) {
        cin >> dislikeRelation.relations[i].first >> dislikeRelation.relations[i].second;
        dislikeRelation.relations[i].first--;
        dislikeRelation.relations[i].second--;
    }

    vector<vector<bool>> graph(n, vector<bool>(n, false));
    for (int i = 0; i < friendRelation.count; i++) {
        int first = friendRelation.relations[i].first;
        int second = friendRelation.relations[i].second;
        graph[first][second] = true;
        graph[second][first] = true;
    }

    vector<vector<bool>> dislike(n, vector<bool>(n, false));
    for (int i = 0; i < dislikeRelation.count; i++) {
        int first = dislikeRelation.relations[i].first;
        int second = dislikeRelation.relations[i].second;
        dislike[first][second] = true;
        dislike[second][first] = true;
    }

    int ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        vector<bool> subset(n);
        for (int j = 0; j < n; j++) {
            subset[j] = (i & (1 << j)) != 0;
        }

        if (isPossible(graph, dislike, subset)) {
            ans = max(ans, countOnes(subset));
        }
    }

    cout << ans << endl;

    return 0;
}