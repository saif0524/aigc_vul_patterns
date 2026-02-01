#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    sort(a.begin(), a.end());
    if(n < 3){
        cout << "0.0000000000";
        return 0;
    }
    double tot=0, win=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                tot++;
                int andy=a[i] + a[j];
                int jerry=a[k];
                vector<int> left;
                for(int l=0; l<n; l++){
                    if(l!=i && l!=j && l!=k) left.push_back(a[l]);
                }
                for(int x=0; x<3; x++){
                    for(int y=x+1; y<3; y++){
                        if(left[x] + left[y] < andy && jerry > left[3-x-y-1]){
                            win++;
                        }
                    }
                }
            }
        }
    }
    cout << fixed << setprecision(10) << win/tot/6.0;
}