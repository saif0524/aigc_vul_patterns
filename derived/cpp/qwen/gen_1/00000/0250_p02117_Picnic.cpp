#include <bits/stdc++.h>
using namespace std;

const int MAXN = 15;
const int MAXX = 10010;
const int MAXY = 1010;

int N, X, Y;
int dp[MAXN][MAXX][MAXY];

struct Candy {
    int price, satisfaction, stocks;
};

vector<Candy> stores[MAXN];
int dist[MAXN][MAXN];

int solve(int town, int money, int spent) {
    if (money < 0 || spent > Y) return -1e9;
    if (town == 0 && money == X) return 0;
    if (dp[town][money][spent] != -1) return dp[town][money][spent];
    
    int max_satisfaction = solve(town, money, 0);
    
    for (const auto &candy : stores[town]) {
        for (int i = 1; i <= candy.stocks; ++i) {
            if (money >= candy.price * i && spent + candy.price * i <= Y) {
                max_satisfaction = max(max_satisfaction, candy.satisfaction * i + 
                                       solve(town, money - candy.price * i, spent + candy.price * i));
            }
        }
    }
    
    for (int next_town = 0; next_town < N; ++next_town) {
        if (next_town != town && money >= dist[town][next_town]) {
            max_satisfaction = max(max_satisfaction, solve(next_town, money - dist[town][next_town], spent));
        }
    }
    
    dp[town][money][spent] = max_satisfaction;
    return max_satisfaction;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> X >> Y;
    
    for (int i = 0; i < N; ++i) {
        int K;
        cin >> K;
        for (int j = 0; j < K; ++j) {
            Candy candy;
            cin >> candy.price >> candy.satisfaction >> candy.stocks;
            stores[i].push_back(candy);
        }
    }
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> dist[i][j];
        }
    }
    
    memset(dp, -1, sizeof(dp));
    cout << solve(0, X, 0) << "\n";
    
    return 0;
}