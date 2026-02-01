#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> followers(n+1, 0);
    vector<int> following(n+1, -1);
    for(int i=1; i<=n; ++i){
        cin >> followers[i];
        if(followers[i] != 0){
            following[followers[i]] = i;
        }
    }
    set<int> possible_positions;
    for(int i=1; i<=n; ++i){
        if(followers[i] == 0){
            int pos = i;
            while(pos != -1 && pos != x){
                pos = following[pos];
            }
            if(pos == x){
                possible_positions.insert(i);
            }
        }
    }
    for(int pos : possible_positions){
        cout << pos << "\n";
    }
}