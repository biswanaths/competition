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
set< PII > slopes;

PII slope(PII a, PII b) {
    int y = b.second - a.second;
    int x = b.first - a.first;
    if(y==0) { return make_pair(1,0);}
    if(x==0) { return make_pair(0,1);}
    int g = __gcd(x,y);
    cout<<g<<" "<<x<<" "<<y<<endl;
    return make_pair(x/g,y/g);
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

    for(int i=0;i<sz;i++) {
        for(int j=i+1;j<sz;j++) {
            slopes.insert(slope(ps[i],ps[j]));
        }
    }
    lld s = slopes.size();
    cout<<s<<endl;
    s = (s*(s-1))/2;
    cout<<s<<endl;

    return 0;
}

