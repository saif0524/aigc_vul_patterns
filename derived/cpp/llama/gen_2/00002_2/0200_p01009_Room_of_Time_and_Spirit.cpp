#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

struct Query {
    string type;
    int a, b, c;
};

int main() {
    int n, q;
    cin >> n >> q;

    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].type >> queries[i].a >> queries[i].b;
        if (queries[i].type == "IN") {
            cin >> queries[i].c;
        }
    }

    map<int, int> power;
    map<int, set<int>> graph;

    for (int i = 1; i <= n; i++) {
        power[i] = 0;
        graph[i] = {};
    }

    for (const auto& query : queries) {
        if (query.type == "IN") {
            int a = query.a;
            int b = query.b;
            int c = query.c;

            graph[a].insert(b);
            graph[b].insert(a);

            power[a] += c;
            power[b] += c;
        } else {
            int a = query.a;
            int b = query.b;

            if (graph[a].count(b) || graph[b].count(a)) {
                cout << power[b] - power[a] << endl;
            } else {
                cout << "WARNING" << endl;
            }
        }
    }

    return 0;
}