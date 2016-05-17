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
#define ulld unsigned long long int 
#define EOL '\0'
#define PEL cout<<endl;
#define N 100002
#define rep(n) for(int i =0;(i)<(int)(n);(i)++)
#define repij(n,m) for(int i =0;(i)<(int)(n);(i)++) for(int j =0;(j)<(int)(m);(j)++)

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
                  std::ostringstream() << std::dec << x ).str()

#define For(iterable) for(__typeof__((iterable).begin()) it = (iterable).begin(); it != (iterable).end(); ++it)



int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    ulld t,a,b; cin>>t>>a>>b;
    ulld g = __gcd(a,b);
    //cout<<g<<endl;

    double lt = log10(t) + log10(g)- log10(a) - log10(b);
    ulld times = pow(10,lt);

    ulld ans = times;
    ans += (times* (min(a,b)-1));
    if(times > 1 ) { 
        ulld left = ( t % (( a /g ) * (b/g)));
        left = min( left, min(a,b)-1);
        ans += left;
    }

    g = __gcd(ans,t);

    cout<<ans/g<<" "<<t/g;

    return 0;
}

