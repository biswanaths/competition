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

int denoms[5];

int change1(int n,int prev) { 
    int ans=0;
    rep(5) { 
        int denom = denoms[i];
        if( denom < prev) return ans;
        if( n > denom ) 
            ans+= change1(n-denom,denom);
        else if( n== denom) 
            ans+=1;
        else 
            ans+=0;
    }
    return ans;
}

int change(int n,int prev) { 
    int ans=0;
    rep(5) { 
        int denom = denoms[i];
        if( denom < prev) continue;
        if( n > denom ) 
            ans+= change(n-denom,denom);
        else if( n== denom) 
            ans+=1;
        else 
            ans+=0;
    }
    return ans;
}


int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
    rep(5) cin>>denoms[i];
#endif
    rep(25)
        cout<<i<<" "<<change(i,-1)<<" "<<change1(i,-1)<<endl;

    return 0;
}

