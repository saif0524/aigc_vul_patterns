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
using namespace std;
int main()
{
    long long a,b,c,d,e,f,g,h,i,j,k,l,m,n,x,y,z,t;
    cin>>t;
    while(t--)
    {

        cin>>a>>b;
        pair<long long,long long>pp[a+1];
        map<long long,long long>mp[a+1];
        for(i=1; i<=a; i++)
        {
            cin>>c>>d;

            pp[i]=make_pair(c,d);
            long ct=0;
            if(i>1)
            {


                for(j=1; j<i; j++)
                {

                    if(abs(pp[i].first-pp[j].first)+abs(pp[i].second-pp[j].second)<=b)
                    {
                       // cout<<i<<" *** "<<j <<" "<<abs(pp[i].first-pp[j].first)+abs(pp[i].second-pp[j].second)<<endl;
                        mp[i][j]=1;
                        mp[j][i]=1;


                    }

                }
            }
        }
        f=0;
        for(i=1; i<=a; i++)
        {
            if(mp[i].size()==a-1)
            {


                cout<< "1"<<endl;
                f=1;
                break;




            }


        }
        if(f==0)
            cout<<"-1"<<endl;
    }
}