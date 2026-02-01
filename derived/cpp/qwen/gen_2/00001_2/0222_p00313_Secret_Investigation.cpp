#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main(){
    int N, X, Y, Z;
    cin >> N >> X;
    vector<int> A(X);
    for(auto &a: A) cin >> a;
    cin >> Y;
    vector<int> B(Y);
    for(auto &b: B) cin >> b;
    cin >> Z;
    vector<int> C(Z);
    for(auto &c: C) cin >> c;
    
    unordered_set<int> setA(A.begin(), A.end());
    unordered_set<int> setB(B.begin(), B.end());
    unordered_set<int> setC(C.begin(), C.end());
    
    unordered_set<int> result;
    
    for(const auto &c: setC){
        if(setA.find(c) == setA.end()){
            result.insert(c);
        }
        if(setB.find(c) != setB.end()){
            result.insert(c);
        }
    }
    
    cout << result.size();
}