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
#include <cassert>


using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

#define lld long long int 
#define EOL '\0'
#define PEL cout<<endl;
#define rep(n) for(int i =0;(i)<(int)(n);(i)++)
#define repij(n,m) for(int i =0;(i)<(int)(n);(i)++) for(int j =0;(j)<(int)(m);(j)++)

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
                  std::ostringstream() << std::dec << x ).str()

#define For(iterable) for(__typeof__((iterable).begin()) it = (iterable).begin(); it != (iterable).end(); ++it)

#define PB push_back
#define ST first
#define ND second

#define MOD 1000003L
#define N (MOD + 3L)

lld nn[10],rr[10];

lld f[N],af[N];

lld ia(lld a,lld n) { 
    // use repeated squaring 
    if(n==1) return a;
    lld ans;
    ans = ia(a,n/2);
    ans = (ans * ans) % MOD;
    if(n%2)  ans = ( ans * a ) % MOD;
    return ans;
}


void init() { 
    // pre calculate factroial modulo and inverse factorial modulo
    f[0]=af[0]= af[1]=1;
    rep(MOD) f[i+1] = ((i+1) * f[i] ) % MOD;
    // inverse factorial modulo by Fermat's little thorm 
    rep(MOD-1)  af[i+2] = ( af[i+1] * ia(i+2,MOD-2) ) % MOD ;
}

lld ncr(lld n,lld r) { 
    if(r==0) return 1;
    if(r==1) return n;
    if(n==r) return 1;
    lld ans =1 ; 
    ans = ( ans * f[n]);
    ans = ( ans * af[r] ) % MOD;
    ans = ( ans * af[n-r]) % MOD;
    return ans;
}

lld lt(lld n,lld r) { 
    // Lucas Theorm 
    int len=0;
    rep(10) nn[i]=rr[i]=0;
    for(int i=0;n>0;nn[i]=n%MOD,n/=MOD,i++,len=max(i,len));
    for(int i=0;r>0;rr[i]=r%MOD,r/=MOD,i++,len=max(i,len));
    rep(len) if(nn[i]<rr[i]) return MOD - 1L;
    lld ans = 1; 
    rep(len) ans = ( ans * (ncr(nn[i],rr[i]) % MOD )) % MOD;
    assert(ans>=0);
    return (ans?ans-1:MOD-1);
}


int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    init();
    int t; cin>>t; 
    while(t--) { 
        lld n,l,r; cin>>n>>l>>r;
        // stars and bars 
        cout<<lt(r-l+1+n,min(n,r-l+1))<<endl;
    }
    return 0;
}

