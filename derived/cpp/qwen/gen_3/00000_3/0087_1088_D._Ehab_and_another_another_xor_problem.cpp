#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a=0, b=0;
    for(int i=29;i>=0;--i){
        long long c=(1LL<<i), d=0;
        cout<<"? "<<c<<" "<<d<<endl;
        fflush(stdout);
        int x;
        cin>>x;
        if(x==-2) return 0;
        if(x==1) a|=c;
        c=0, d=(1LL<<i);
        cout<<"? "<<c<<" "<<d<<endl;
        fflush(stdout);
        cin>>x;
        if(x==-2) return 0;
        if(x==-1) b|=c;
    }
    cout<<"! "<<a<<" "<<b<<endl;
    fflush(stdout);
    return 0;
}