#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> glasses(n);
    for(auto &g: glasses) cin >> g.first >> g.second;
    sort(glasses.begin(), glasses.end(), [&](const auto &a, const auto &b){
        return a.first - a.second > b.first - b.second;
    });
    vector<double> ans(n);
    double total = 0;
    for(int i=0;i<n;i++){
        total += glasses[i].second;
        double cur = 0;
        double need = 0;
        vector<double> heap;
        for(int j=0;j<=i;j++){
            double can_take = min(total - cur, glasses[j].first - glasses[j].second);
            if(can_take > 0){
                double take = min(can_take, need);
                cur += take;
                need -= take;
                can_take -= take;
                if(can_take > 0){
                    push_heap(heap.begin(), heap.end(), less<double>());
                    heap.push_back(can_take);
                    push_heap(heap.begin(), heap.end(), less<double>());
                    cur += can_take / 2.0;
                    need += can_take / 2.0;
                    while(need > 0 && heap.size() > 0){
                        double give = min(need, heap.front());
                        cur -= give / 2.0;
                        need -= give;
                        pop_heap(heap.begin(), heap.end(), less<double>()); 
                        heap.pop_back();
                        if(give < heap.front()){
                            heap.push_back(heap.front() - give);
                            push_heap(heap.begin(), heap.end(), less<double>()); 
                        }
                    }
                }
            }
            cur = min(cur, 1.0* glasses[j].first);
            ans[i] += cur;
        }
    }
    for(auto &x: ans) cout << fixed << setprecision(10) << x << " ";
    cout << endl;
}