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

#define M 1000000007

int temp;


struct BIT {
    lld a[N];
    lld read(int i) { 
        lld sum = 0; 
        while(i>0) 
            sum+= a[i], sum%=M, i -= ( i & -i);
        return sum;
    }
    void update(int i,lld v) {
        while(i<=N)  
            a[i]+=v, a[i]%=M, i += (i & -i);
    }
    void rupdate(int a, int b, lld v) {
        update(a,v);
        update(b+1, -v);
    }
            
} BIT;


int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int n,q;cin>>n>>q;
    rep(n) (cin>>temp), BIT.update(i+1,temp);
    rep(q) { int qq; cin>>qq;
        cout<<BIT.read(qq)<<endl;
    }
    BIT.rupdate(1,3,2);
    rep(5) cout<<BIT.read(i+1)<<endl;
    return 0;
}

