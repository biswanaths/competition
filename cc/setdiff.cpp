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
#define N 200002
#define rep(n) for(int i =0;(i)<(int)(n);(i)++)
#define repij(n,m) for(int i =0;(i)<(int)(n);(i)++) for(int j =0;(j)<(int)(m);(j)++)

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
                  std::ostringstream() << std::dec << x ).str()

#define For(iterable) for(__typeof__((iterable).begin()) it = (iterable).begin(); it != (iterable).end(); ++it)

lld rem = 1000000007;

lld c[100002];

void init() {
    c[0]=1;
    for(int i=1;i<100002;i++) {
        c[i] = ( (c[i-1]*2) % rem);
    }
}
lld solve(int n,vector<lld> v ) {
    lld ans= 0;
    sort(v.begin(),v.end());
    rep(n) { 
        ans += v[i] * (c[i] - c[n-i-1]);
        ans = ans % rem;
    }
    return ans;
}

int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int t; cin>>t;
    init();
    while(t--) { 
        int n; cin>>n;
        vector<lld> v;
        rep(n) {lld temp; cin>>temp; v.push_back(temp); }
        cout<<solve(n,v)<<endl;
    }

    return 0;
}

