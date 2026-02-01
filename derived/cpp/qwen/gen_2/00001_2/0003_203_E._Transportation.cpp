#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Robot {
    ll c, f, l;
};

bool compareF(const Robot& a, const Robot& b) {
    return a.f < b.f;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, d, S;
    cin >> n >> d >> S;
    vector<Robot> robots(n);
    for(auto &robot: robots){
        cin >> robot.c >> robot.f >> robot.l;
    }
    vector<Robot> validRobots;
    for(auto &robot: robots){
        if(robot.l >= d){
            validRobots.push_back(robot);
        }
    }
    sort(validRobots.begin(), validRobots.end(), compareF);
    ll maxRobots = 0, minFuel = 0;
    for(ll i=0; i<validRobots.size() && S > 0; ++i){
        if(validRobots[i].f <= S){
            ll totalRobots = 1LL + validRobots[i].c;
            ll remainingFuel = S - validRobots[i].f;
            priority_queue<ll, vector<ll>, greater<ll>> pq;
            for(ll j=i+1; j<validRobots.size(); ++j){
                if(validRobots[j].f <= remainingFuel){
                    pq.push(validRobots[j].c);
                    totalRobots += 1;
                    remainingFuel -= validRobots[j].f;
                }
                if(pq.size() > totalRobots - 1){
                    remainingFuel += pq.top();
                    pq.pop();
                    totalRobots -= 1;
                }
            }
            if(totalRobots > maxRobots){
                maxRobots = totalRobots;
                minFuel = validRobots[i].f + (S - remainingFuel);
            }
        }
    }
    cout << maxRobots << " " << minFuel;
    return 0;
}