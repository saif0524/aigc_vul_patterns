#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>

using namespace std;

const int MAXN = 100005;
const int MAXM = 100005;
const int INF = 0x3f3f3f3f;

struct Edge {
    int to, next, weight;
} edges[MAXM * 2];

int n, m, s, b, k;
int head[MAXN];
int edgeCount;
int distances[MAXN][MAXN];

void addEdge(int u, int v, int weight) {
    edges[edgeCount].to = v;
    edges[edgeCount].next = head[u];
    edges[edgeCount].weight = weight;
    head[u] = edgeCount++;
}

void init() {
    memset(head, -1, sizeof(head));
    edgeCount = 0;
}

void dijkstra(int start) {
    memset(distances[start], 0x3f, sizeof(distances[start]));
    distances[start][start] = 0;
    priority_queue<pair<int, int>> queue;
    queue.push(make_pair(0, start));
    while (!queue.empty()) {
        int u = queue.top().second;
        queue.pop();
        for (int i = head[u]; i != -1; i = edges[i].next) {
            int v = edges[i].to;
            int weight = edges[i].weight;
            if (distances[start][u] + weight < distances[start][v]) {
                distances[start][v] = distances[start][u] + weight;
                queue.push(make_pair(-distances[start][v], v));
            }
        }
    }
}

int spaceshipLocations[MAXN];
int spaceshipAttacks[MAXN];
int spaceshipFuels[MAXN];
int spaceshipPrices[MAXN];

int baseLocations[MAXN];
int baseDefences[MAXN];
int baseGold[MAXN];

bool canAttack(int spaceship, int base) {
    return spaceshipAttacks[spaceship] >= baseDefences[base] &&
           spaceshipFuels[spaceship] >= distances[spaceshipLocations[spaceship]][baseLocations[base]];
}

int getProfit(int spaceship) {
    int maxProfit = -INF;
    for (int base = 0; base < b; base++) {
        if (canAttack(spaceship, base)) {
            maxProfit = max(maxProfit, baseGold[base] - spaceshipPrices[spaceship]);
        }
    }
    return maxProfit;
}

vector<int> dependencies[MAXN];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        addEdge(u, v, 1);
        addEdge(v, u, 1);
    }

    for (int i = 0; i < n; i++) {
        dijkstra(i);
    }

    cin >> s >> b >> k;
    for (int i = 0; i < s; i++) {
        cin >> spaceshipLocations[i] >> spaceshipAttacks[i] >> spaceshipFuels[i] >> spaceshipPrices[i];
        spaceshipLocations[i]--;
    }

    for (int i = 0; i < b; i++) {
        cin >> baseLocations[i] >> baseDefences[i] >> baseGold[i];
        baseLocations[i]--;
    }

    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        dependencies[u].push_back(v);
    }

    vector<vector<int>> subsets(1 << s, vector<int>());
    for (int mask = 0; mask < (1 << s); mask++) {
        for (int i = 0; i < s; i++) {
            if (mask & (1 << i)) {
                subsets[mask].push_back(i);
            }
        }
    }

    int maxProfit = 0;
    for (int mask = 0; mask < (1 << s); mask++) {
        bool valid = true;
        for (int u : subsets[mask]) {
            for (int v : dependencies[u]) {
                if (std::find(subsets[mask].begin(), subsets[mask].end(), v) == subsets[mask].end()) {
                    valid = false;
                    break;
                }
            }
            if (!valid) break;
        }
        if (!valid) continue;

        int profit = 0;
        for (int spaceship : subsets[mask]) {
            profit += getProfit(spaceship);
        }
        maxProfit = max(maxProfit, profit);
    }

    cout << maxProfit << endl;
    return 0;
}