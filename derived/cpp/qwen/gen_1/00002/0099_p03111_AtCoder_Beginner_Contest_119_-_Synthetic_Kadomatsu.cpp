#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, A, B, C;
    cin >> N >> A >> B >> C;
    vector<int> lengths(N);
    for(auto &x: lengths) cin >> x;
    
    int ans = 1e9;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){
                if(i != j && j != k && i != k){
                    int cost = 0;
                    int lenA = lengths[i];
                    int lenB = lengths[j];
                    int lenC = lengths[k];
                    
                    cost += abs(lenA - A);
                    cost += abs(lenB - B);
                    cost += abs(lenC - C);
                    
                    int remain = N - 3;
                    vector<int> temp;
                    for(int l=0; l<N; l++){
                        if(l != i && l != j && l != k){
                            temp.push_back(lengths[l]);
                        }
                    }
                    
                    sort(temp.begin(), temp.end(), greater<int>());
                    
                    for(int a=0; a<=temp.size(); a++){
                        for(int b=0; b<=temp.size()-a; b++){
                            int c = remain - a - b;
                            int sumA = lenA;
                            int sumB = lenB;
                            int sumC = lenC;
                            
                            for(int l=0; l<a; l++) sumA += temp[l];
                            for(int l=a; l<a+b; l++) sumB += temp[l];
                            for(int l=a+b; l<a+b+c; l++) sumC += temp[l];
                            
                            int currCost = cost;
                            currCost += 10 * (a + b + c - 1);
                            currCost += abs(sumA - A);
                            currCost += abs(sumB - B);
                            currCost += abs(sumC - C);
                            
                            ans = min(ans, currCost);
                        }
                    }
                }
            }
        }
    }
    cout << ans;
}