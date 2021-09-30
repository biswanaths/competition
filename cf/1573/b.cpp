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

#define N 100002
#define rep(n) for(int i =0;(i)<(int)(n);(i)++)
#define repij(n,m) for(int i =0;(i)<(int)(n);(i)++) for(int j =0;(j)<(int)(m);(j)++)

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
                  std::ostringstream() << std::dec << x ).str()

#define For(iterable) for(__typeof__((iterable).begin()) it = (iterable).begin(); it != (iterable).end(); ++it)

int a[2*N];

int solve(int n) { 
    int t, ans = 3*n, rmin = 3*n;

    rep(n) {
        cin>>t; a[t]=i;
    }
    rep(n) {
        cin>>t; a[t]=i;
    }

    for(int i=2*n;i>0;i-=2) { 
        rmin = min(rmin, a[i]); 
        ans  = min(ans , rmin + a[i-1]);
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
    while(t--) {
        int n; cin>>n;
        cout<<solve(n)<<endl;
    }
    return 0;
}

