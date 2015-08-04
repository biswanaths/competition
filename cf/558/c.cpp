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
map< PII ,int > fc;
int find(int a,int b) { 
    if(a==b) return a;
    if(min(a,b)==1) return 1;
    int ans;
    PII p = make_pair(a,b);
    if(fc.find(p)!= fc.end()) return fc[p];
    if(a>b) ans = find(a/2,b);
    else ans = find(a,b/2);
    fc[p]=ans;
    return ans;
}

map< PII ,int > mc;

int moves(int a,int b) { 
    if(a==b) return 0;
    int ans;
    PII p = make_pair(a,b);
    if(mc.find(p)!= mc.end()) return mc[p];
    if(a>b) ans = 1+moves(a/2,b);
    else ans = 1+moves(a,b/2);
    mc[p] = ans;
    return ans;
}

int c[N];

int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int n;cin>>n;
    rep(n) cin>>c[i];
    int seed = c[0];
    rep(n) seed = find(seed,c[i]);

    lld ans = 9999999999999;
    while(seed<N) { 
        lld tans =0;
        rep(n) {
            tans+= moves(seed,c[i]);
        }
        ans= min(ans,tans);
        seed *=2;
    }
    cout<<ans;

    return 0;
}

