#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main(){
    long long l, r;
    cin >> l >> r;
    
    unordered_map<long long, long long> count;
    for(long long i = 2; i * i <= r; ++i){
        long long start = max(i * i, (l + i - 1) / i * i);
        for(long long j = start; j <= r; j += i){
            if(j >= l){
                count[i]++;
            }
        }
    }
    
    long long max_count = 0, result = 0;
    for(const auto& [key, value] : count){
        if(value > max_count || (value == max_count && key < result)){
            max_count = value;
            result = key;
        }
    }
    
    cout << result;
}