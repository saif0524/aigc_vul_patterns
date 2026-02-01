#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main(){
    int n, k;
    cin >> n >> k;
    vector<pii> a, b, ab;
    for(int i=0;i<n;i++){
        int t, ai, bi;
        cin >> t >> ai >> bi;
        if(ai && bi) ab.push_back({t, i});
        else if(ai) a.push_back({t, i});
        else if(bi) b.push_back({t, i});
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(ab.begin(), ab.end());
    if(ab.size() >= k){
        long long sum = 0;
        for(int i=0;i<k;i++) sum += ab[i].first;
        long long best = sum;
        int aa=0, bb=0;
        int i = 0, j = 0;
        while(i<a.size()&&j<b.size()&&aa+(int)ab.size()<k&&(bb+(int)ab.size()<k)){
            if(a[i].first + b[j].first < ab[aa+(int)ab.size()].first){
                sum += a[i].first + b[j].first - ab[aa+(int)ab.size()].first;
                aa++, bb++;
                i++, j++;
            }
            else{
                long long mn = min(aa, bb);
                sum += (i+j-mn-mn)*(ab[aa+mn].first - ab[aa+mn-1].first);
                aa = bb = mn + k;
            }
            best = min(best, sum);
        }
        cout << best;
        return 0;
    }
    else if(a.size()+b.size()+(int)ab.size() < 2*k){
        cout << -1;
        return 0;
    }
    else{
        long long sum = 0;
        for(int i=0;i<k-(int)ab.size();i++) sum += a[i].first + b[i].first;
        for(int i=0;i<ab.size();i++) sum += ab[i].first;
        cout << sum;
    }
}