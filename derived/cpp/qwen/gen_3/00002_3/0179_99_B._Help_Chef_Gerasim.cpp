#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> cups(n);
    for(auto &c: cups) cin >> c;
    
    int min_cup = *min_element(cups.begin(), cups.end());
    vector<int> diffs;
    for(int i=0; i<n; ++i){
        if(cups[i] != min_cup){
            diffs.push_back(cups[i] - min_cup);
        }
    }
    
    if(diffs.empty()){
        cout << "Exemplary pages.";
        return 0;
    }
    
    int sum_diffs = 0;
    for(int d: diffs){
        sum_diffs += d;
    }
    
    if(sum_diffs != min_cup){
        cout << "Unrecoverable configuration.";
        return 0;
    }
    
    if(diffs.size() != 1){
        cout << "Unrecoverable configuration.";
        return 0;
    }
    
    int pour_volume = diffs[0];
    int from_cup = -1, to_cup = -1;
    for(int i=0; i<n; ++i){
        if(cups[i] == min_cup){
            from_cup = i;
        }else{
            to_cup = i;
        }
    }
    
    cout << pour_volume << " ml. from cup #" << (from_cup+1) << " to cup #" << (to_cup+1) << ".";
    return 0;
}