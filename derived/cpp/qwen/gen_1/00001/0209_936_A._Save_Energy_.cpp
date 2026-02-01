#include <bits/stdc++.h>
using namespace std;

int main(){
    long long k, d, t;
    cin >> k >> d >> t;
    double total_time = 0;
    double on_time = 0;
    double off_time = 0;
    while(t > 0){
        if(t <= k){
            total_time += t;
            on_time += t;
            t = 0;
        }
        else{
            total_time += k;
            on_time += k;
            t -= k;
            if(t > 0){
                if(t <= d){
                    total_time += t * 2.0;
                    off_time += t;
                    t = 0;
                }
                else{
                    total_time += d * 2.0;
                    off_time += d;
                    t -= d;
                }
            }
        }
        if(t > 0){
            if(total_time + d <= total_time + k){
                total_time += d;
            }
            else{
                total_time += k;
                on_time += k;
                t -= k;
            }
        }
    }
    printf("%.10f\n", total_time);
}