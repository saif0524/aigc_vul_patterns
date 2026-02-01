#include <bits/stdc++.h>
using namespace std;

struct Lady {
    int B, I, R;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<Lady> ladies(N);
    for(int i=0;i<N;i++) cin >> ladies[i].B;
    for(int i=0;i<N;i++) cin >> ladies[i].I;
    for(int i=0;i<N;i++) cin >> ladies[i].R;
    sort(ladies.begin(), ladies.end(), [](const Lady& a, const Lady& b){
        if(a.B == b.B) return a.I > b.I; // Ensure descending order of I for same B
        return a.B < b.B; // Ascending order of B
    });
    int count = 0;
    int maxR = 0;
    for(int i=0;i<N;i++){
        if(ladies[i].R < maxR) count++;
        maxR = max(maxR, ladies[i].R);
    }
    cout << count;
}