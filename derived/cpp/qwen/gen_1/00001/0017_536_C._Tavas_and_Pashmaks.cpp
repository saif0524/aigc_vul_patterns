#include <bits/stdc++.h>
using namespace std;

struct Competitor {
    int swim_speed, run_speed;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<Competitor> competitors(n);
    for(int i=0;i<n;i++){
        cin >> competitors[i].swim_speed >> competitors[i].run_speed;
    }
    vector<int> sorted_indices(n);
    for(int i=0;i<n;i++){
        sorted_indices[i]=i;
    }
    sort(sorted_indices.begin(), sorted_indices.end(), [&](int a, int b){
        return (double)competitors[a].run_speed/(double)competitors[a].swim_speed < (double)competitors[b].run_speed/(double)competitors[b].swim_speed;
    });
    vector<int> winners;
    for(int i=0;i<n;i++){
        bool is_winner = true;
        for(int j=i-1;j>=0;j--){
            if((double)competitors[sorted_indices[j]].run_speed/(double)competitors[sorted_indices[j]].swim_speed <= (double)competitors[sorted_indices[i]].run_speed/(double)competitors[sorted_indices[i]].swim_speed){
                is_winner = false;
                break;
            }
        }
        if(is_winner){
            winners.push_back(sorted_indices[i]+1);
        }
    }
    for(int i=0;i<winners.size();i++){
        cout << winners[i] << (i==winners.size()-1?'\n':' ');
    }
}