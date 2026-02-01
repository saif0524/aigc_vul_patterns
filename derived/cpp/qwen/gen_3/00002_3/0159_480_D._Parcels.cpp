#include <bits/stdc++.h>
using namespace std;

struct Event {
    int time;
    int type; // 0 = arrival, 1 = departure
    int index;
};

int main(){
    int n, S;
    cin >> n >> S;
    vector<tuple<int,int,int,int,int>> parcels(n);
    for(int i = 0; i < n; ++i){
        int in, out, w, s, v;
        cin >> in >> out >> w >> s >> v;
        parcels[i] = {in, out, w, s, v};
    }
    vector<Event> events;
    for(int i = 0; i < n; ++i){
        events.push_back({get<0>(parcels[i]), 0, i});
        events.push_back({get<1>(parcels[i]), 1, i});
    }
    sort(events.begin(), events.end(), [&](const Event& a, const Event& b){
        if(a.time == b.time) return a.type > b.type; // process departures before arrivals at the same time
        return a.time < b.time;
    });
    vector<vector<int>> dp(n+1, vector<int>(S+1, 0));
    unordered_map<int, int> current_stack;
    for(const auto& event : events){
        int time = event.time, type = event.type, index = event.index;
        if(type == 1){ // departure
            int in, out, w, s, v;
            tie(in, out, w, s, v) = parcels[index];
            int top_weight = 0;
            for(auto [box_index, box_time] : current_stack){
                if(box_time < time){
                    top_weight += get<2>(parcels[box_index]);
                }
            }
            for(int j = 0; j <= S - w; ++j){
                dp[index+1][top_weight + w] = max(dp[index+1][top_weight + w], dp[index][j] + v);
            }
            current_stack.erase(index);
        } else { // arrival
            for(int j = S; j >= 0; --j){
                dp[index+1][j] = max(dp[index+1][j], dp[index][j]);
            }
            int in, out, w, s, v;
            tie(in, out, w, s, v) = parcels[index];
            int top_weight = 0;
            for(auto [box_index, box_time] : current_stack){
                if(box_time < time){
                    top_weight += get<2>(parcels[box_index]);
                }
            }
            if(current_stack.empty() || (top_weight + w <= s && top_weight + w <= S)){
                for(int j = S - w; j >= 0; --j){
                    if(dp[index][j] + v >= dp[index+1][top_weight + w]){
                        dp[index+1][top_weight + w] = dp[index][j] + v;
                    }
                }
                current_stack[index] = time;
            }
        }
    }
    int answer = 0;
    for(int j = 0; j <= S; ++j){
        answer = max(answer, dp[n][j]);
    }
    cout << answer;
}