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



float p[1002],cans[1002][1002];
bool cal[1002][1002];

float solve(int i, int n, int k) {
    if(cal[i][k]) return cans[i][k];
    cal[i][k] = 1;
    if(i==n) { 
        //cout<<i<<":"<<n<<":"<<k<<":"<<1<<endl;
        cans[i][k] = 1;
        return 1;
    }
    float ans = 0;
    if(n-i > k)
        ans += (1-p[i]) * solve(i+1, n, k);
    if(k>0) 
        ans += p[i] * solve(i+1, n, k-1);
    cans[i][k] = ans;
    //cout<<i<<":"<<n<<":"<<k<<":"<<ans<<endl;
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
        int n, k; 
        cin>>n>>k;
        rep(n) cin>>p[i];
        memset(cal,0,sizeof(bool) * 1002 * 1002);
        cout<<fixed<<setprecision(10)<<solve(0,n,k)<<endl;
    }

    return 0;
}

