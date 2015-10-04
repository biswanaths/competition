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
#define N 503 
#define rep(n) for(int i =0;(i)<(int)(n);(i)++)
#define repij(n,m) for(int i =0;(i)<(int)(n);(i)++) for(int j =0;(j)<(int)(m);(j)++)

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
                  std::ostringstream() << std::dec << x ).str()

#define For(iterable) for(__typeof__((iterable).begin()) it = (iterable).begin(); it != (iterable).end(); ++it)

int n; 
lld a[N], g[N*N];
map<lld, int> ac;

void pp() { 
    For(ac) { 
        if(it->second) cout<<it->first<<" "<<it->second<<" : ";
    }
    PEL;
}


int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    cin>>n;
    rep(n*n) { 
        cin>>g[i];
        ac[g[i]]++;
    }
    sort(g,g+(n*n));
    int cur=0;
    for(int i=(n*n)-1;i>=0;i--) { 
        if(ac[g[i]]>0) { 
            a[cur]=g[i];
            ac[g[i]]--;
            for(int j=0;j<cur;j++) { 
                lld gd = __gcd(a[j],g[i]);
                ac[gd]-=2;
            }
            cur++;
        }
    }
    rep(n) cout<<a[i]<<" ";

    return 0;
}

