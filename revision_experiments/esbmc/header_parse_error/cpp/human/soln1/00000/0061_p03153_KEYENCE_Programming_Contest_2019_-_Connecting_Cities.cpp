// [esbmc] replaced #include <bits/stdc++.h> with ESBMC-compatible headers
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cinttypes>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <istream>
#include <ostream>
#include <ios>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <streambuf>
#include <string>
#include <string_view>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include <iterator>
#include <memory>
#include <tuple>
#include <limits>
#include <random>
#include <complex>
#include <valarray>
#include <stdexcept>
#include <exception>
#include <typeinfo>
#include <type_traits>
#include <initializer_list>
#include <numbers>
#include <any>
#define ll long long
using namespace std;
struct node
{
    int u,v;
    ll w;
    bool operator<(const node &o)const{return w<o.w;}
}e[6000005];
int n,cot=0,a[200005],fail[200005];
ll d;
void add(int l,int r)
{
    if(l>=r) return;
    int m=l+r>>1;
    ll mi=1e18,pos;
    for(int i=l;i<=m;i++)
    {
        ll f=a[i]-d*i;
        if(f<mi) mi=f,pos=i;
    }
    for(int i=m+1;i<=r;i++)
        e[cot].u=pos,e[cot].v=i,e[cot++].w=a[i]+a[pos]+d*(i-pos);
    mi=1e18;
    for(int i=m+1;i<=r;i++)
    {
        ll f=a[i]+d*i;
        if(f<mi) mi=f,pos=i;
    }
    for(int i=l;i<=m;i++)
        e[cot].u=i,e[cot].v=pos,e[cot++].w=a[i]+a[pos]+d*(pos-i);
    add(l,m);add(m+1,r);
}
int get_fa(int x)
{
    return fail[x]==x?x:fail[x]=get_fa(fail[x]);
}
ll kruskal()
{
    sort(e,e+cot);
    for(int i=1;i<=200000;i++) fail[i]=i;
    ll ans=0;
    for(int i=0;i<cot;i++)
    {
        int fu=get_fa(e[i].u),fv=get_fa(e[i].v);
        if(fu==fv) continue;
        fail[fu]=fv;
        ans+=e[i].w;
    }
    return ans;
}
int main()
{
    scanf("%d%lld",&n,&d);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    add(1,n);
    printf("%lld\n",kruskal());
}