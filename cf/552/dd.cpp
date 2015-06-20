#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>


using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

#define lld long long int 
#define EOL '\0'
#define PEL cout<<endl;
#define N 100002
#define rep(n) for(int i =0;(i)<(int)(n);(i)++)
#define repij(n,m) for(int i =0;(i)<(int)(n);(i)++) for(int j =0;(j)<(int)(m);(j)++)

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
                  std::ostringstream() << std::dec << x ).str()

#define For(iterable) for(__typeof__((iterable).begin()) it = (iterable).begin(); it != (iterable).end(); ++it)

vector< PII > ps;

PII slope(PII a, PII b) {
    int y = b.second - a.second;
    int x = b.first - a.first;
    if(y==0) x=1;
    if(x==0) y=1;
    return make_pair(x,y);
}



int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int n,sz; cin>>n;sz=n;
    while(n--) { 
        int x,y; cin>>x>>y;
        ps.push_back(make_pair(x,y));
    }
    lld c=0;

    for(int i=0;i<sz;i++) {
        for(int j=i+1;j<sz;j++) {
            for(int k=j+1;k<sz;k++) {
                PII s1 = slope(ps[i],ps[j]);
                PII s2 = slope(ps[i],ps[k]);
                int ms1 ,ms2;
                if(s1.first!=0 && s2.first!=0) {
                    ms1 = s2.first,ms2=s1.first;
                } else { 
                    ms1 = s2.second,ms2 =s1.second;
                }
                s1.first*=ms1,s1.second*=ms1,s2.first*=ms2,s2.second*=ms2;
                if(s1.first == s2.first && s1.second == s2.second) ;
                else {
                    c++;
                }
            }
        }
    }
    cout<<c<<endl;

    return 0;
}

