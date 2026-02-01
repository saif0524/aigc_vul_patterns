#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    for(auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    bool found = false;
    for(int i = 1; i < N; ++i){
        if((a[i] - a[0]) % (N-1) == 0){
            cout << a[0] << " " << a[i] << endl;
            found = true;
            break;
        }
    }
    if(!found){
        cout << a[N-1] << " " << a[0] << endl;
    }
    return 0;
}