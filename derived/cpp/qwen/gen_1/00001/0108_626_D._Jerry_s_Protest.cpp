#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    sort(a.begin(), a.end());

    double total = 0, favorable = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i == j) continue;
            for(int k=0;k<n;k++){
                if(k == i || k == j) continue;
                int andy_sum = a[i] + a[j];
                int jerry_sum = a[k];
                for(int l=0;l<n;l++){
                    if(l == i || l == j || l == k) continue;
                    for(int m=0;m<n;m++){
                        if(m == i || m == j || m == k || m == l) continue;
                        andy_sum += a[l] + a[m];
                        jerry_sum += a[n-1-(l<m?l:m)] + a[n-2-(l<m?l:m)-(l>m?l:m)];
                        if(jerry_sum > andy_sum) favorable++;
                        andy_sum -= a[l] + a[m];
                        jerry_sum -= a[n-1-(l<m?l:m)] + a[n-2-(l<m?l:m)-(l>m?l:m)];
                    }
                }
                total++;
            }
        }
    }

    cout << fixed << setprecision(10) << (favorable / total) << endl;
}