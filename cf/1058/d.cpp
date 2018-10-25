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

LL gcd(LL a, LL b) { 
    if(b==0) return a; 
    return gcd(b,a%b);
}


int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    LL n,m,k; cin>>n>>m>>k;
    LL g = gcd(n*m, k); 
    LL p = (n*m)/g, q = k/g;

    if(q!=1 && q!=2) {
        cout<<"NO";
        return 0;
    }

    cout<<"YES"<<endl;

    LL ans; 
    if(q==1) ans = p* 2L; 
    else ans = p;

    cout<<0<<" "<<0<<endl;

    for(LL i=1; (i*i)<=ans;i++) { 
        if(ans%i==0) 
            if(i<=n && (ans/i) <=m) { 
                cout<<i<<" "<<0<<endl;
                cout<<0<<" "<<ans/i<<endl;
                return 0;
            }
            if(i<=m && (ans/i) <=n) { 
                cout<<ans/i<<" "<<0<<endl;
                cout<<0<<" "<<i<<endl;
                return 0;
            }
    }

    return 0;
}

