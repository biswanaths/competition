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
#define N 10000002
#define rep(n) for(int i =0;(i)<(int)(n);(i)++)
#define repij(n,m) for(int i =0;(i)<(int)(n);(i)++) for(int j =0;(j)<(int)(m);(j)++)

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
                  std::ostringstream() << std::dec << x ).str()

#define For(iterable) for(__typeof__((iterable).begin()) it = (iterable).begin(); it != (iterable).end(); ++it)

#define PB push_back
#define ST first
#define ND second

int n,k,q;
int  a, b, c, d, e, f, r, s, t, m;
int L1, La, Lc, Lm, D1, Da, Dc, Dm;
int pr[10],su[10];

void init() {
    int pre,cur;
    cin>>n>>k>>q;
    cin>>a>>b>>c>>d>>e>>f>>r>>s>>t>>m;
    cin>>pre;
    cin>> L1>> La>> Lc>> Lm>> D1>> Da>> Dc>> Dm;
    su[1] = pr[1] = pre;
    int pt = (t *t ) % s;
    cout<<pre;
    for(int i=2;i<=n;i++) {
        if( pt <= r ) 
            cur = ( a * (pre * pre) + b * pre + c) % m;
        else 
            cur = ( d * (pre * pre) + e * pre + f) % m;
        pr[i] = pr[i-1] * cur;
        su[i] = su[i-1] + cur; 
        pre = cur;
        pt = ( pt * t ) % s;
        cout<<"-"<<pre;
    }
    cout<<endl;
    rep(n) cout<<su[i+1]<<"-";cout<<endl;
    rep(n) cout<<pr[i+1]<<"-";cout<<endl;

}

int pquery(int a, int b) { 
    return pr[b]/pr[a-1]; 
}

int squery(int a, int b) {
    return su[b]-su[a-1]; 
}

int solve() {
    for(int i = 1;i<=q;i++) {
        int L1 = (La * L1 + Lc) % Lm;
        int D1 = (Da * D1 + Dc) % Dm; 
        int L = L1 + 1;
        int R = min(L + k - 1 + D1, n);
        cout<<"(L,R) = ("<<L<<","<<R<<")"<<endl;
        cout<<squery(L-1,R-1)<<" "<<pquery(L-1,R-1)<<endl;
    }

    return 0;
}

int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    init();
    solve();
    return 0;
}

