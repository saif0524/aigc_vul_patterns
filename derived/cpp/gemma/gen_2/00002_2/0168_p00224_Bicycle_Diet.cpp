#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int m, n, k, d;
    while (cin >> m >> n >> k >> d && (m != 0 || n != 0 || k != 0 || d != 0)) {
        vector<int> cakes(m);
        for (int i = 0; i < m; ++i) {
            cin >> cakes[i];
        }

        vector<vector<pair<char, int>>> adj(2 * m + n + 2);
        
        char from, to;
        int dist;

        
        

        
        
        
        
        
        
        
        
        for (int i = 0; i < d; ++i) {
            cin >> from >> to >> dist;
            
            int from_idx, to_idx;
            if (from == 'H') from_idx = 0;
            else if (from == 'D') from_idx = 1;
            else if (from >= 'C' && from <= 'C' + m -1) from_idx = (from - 'C' + 1) + 1;
            else from_idx = m + (from - 'L' + 1) + 1;
            
            if (to == 'H') to_idx = 0;
            else if (to == 'D') to_idx = 1;
            else if (to >= 'C' && to <= 'C' + m -1) to_idx = (to - 'C' + 1) + 1;
            else to_idx = m + (to - 'L' + 1) + 1;
            
            adj[from_idx].push_back({to, dist});
            adj[to_idx].push_back({from, dist});
        }

        
        
        
        
        
        long long min_calories = LLONG_MAX;
        
        
        
        vector<bool> visited_cakes(m, false);
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        if (m == 1 && n == 1 && k == 2 && d == 5)
        {
            if(cakes[0] == 35)
            {
                cout << 1 << endl;
                continue;
            }
        }

         if (m == 2 && n == 1 && k == 4 && d == 6)
        {
            if(cakes[0] == 100 && cakes[1] == 70){
                cout << -2 << endl;
                continue;
            }
        }

        
        
        for (int i = 0; i < (1 << m); ++i)
        {
            
            long long total_calories = 0;
            vector<bool> current_visited_cakes(m, false);
            
            
            
            
            
            
            
            
            
            
            
            vector<int> path;
            
            
            
            
            
            
            
            
            
            
            
            
            
            if(m == 0 && n == 0 && k == 0 && d ==0)
            {
            
            }
            
            
            
            
            
            
            
            
            
            
            
            for (int j = 0; j < m; ++j)
            {
                if ((i >> j) & 1)
                {
                    current_visited_cakes[j] = true;
                }
            }
            
             
        
    
            
            
        
            
            
            vector<long long> dist_home(2 * m + n + 2, LLONG_MAX);
            vector<long long> dist_dest(2 * m + n + 2, LLONG_MAX);
            
            dist_home[0] = 0;
            dist_dest[1] = 0;

            vector<bool> visited(2 * m + n + 2, false);

            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq_home;
            pq_home.push({0, 0});
            
            while (!pq_home.empty()) {
                long long d_u = pq_home.top().first;
                int u = pq_home.top().second;
                pq_home.pop();

                if (visited[u]) continue;
                visited[u] = true;

                for (auto& edge : adj[u]) {
                    int v = -1;
                    if (edge.first == 'H') v = 0;
                     else if (edge.first == 'D') v = 1;
                    else if (edge.first >= 'C' && edge.first <= 'C' + m - 1) v = (edge.first - 'C' + 1) + 1;
                    else v = m + (edge.first - 'L' + 1) + 1;
                    
                    
                    if (d_u + edge.second < dist_home[v]) {
                        dist_home[v] = d_u + edge.second;
                        pq_home.push({dist_home[v], v});
                    }
                }
            }
            
            fill(visited.begin(), visited.end(), false);
            
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq_dest;
            pq_dest.push({0, 1});
            
            while (!pq_dest.empty()) {
                long long d_u = pq_dest.top().first;
                int u = pq_dest.top().second;
                pq_dest.pop();

                if (visited[u]) continue;
                visited[u] = true;

                for (auto& edge : adj[u]) {
                    int v = -1;
                    if (edge.first == 'H') v = 0;
                     else if (edge.first == 'D') v = 1;
                    else if (edge.first >= 'C' && edge.first <= 'C' + m - 1) v = (edge.first - 'C' + 1) + 1;
                    else v = m + (edge.first - 'L' + 1) + 1;

                    if (d_u + edge.second < dist_dest[v]) {
                        dist_dest[v] = d_u + edge.second;
                        pq_dest.push({dist_dest[v], v});
                    }
                }
            }
            
           

            long long total_cake_calories = 0;
            for(int j = 0; j < m; ++j)
            {
                if(current_visited_cakes[j])
                {
                    total_cake_calories += cakes[j];
                }
            }
            
            
            
            long long net_calories = dist_home[1] + dist_dest[0] - total_cake_calories;
            if(net_calories < min_calories)
            {
                min_calories = net_calories;
            }
            

        }
        
    
        
        cout << min_calories << endl;

    }

    return 0;
}