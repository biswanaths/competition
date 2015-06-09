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

#define MOD 1000000007L

lld af[N+1];

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
    af[0]= af[1]=1;
    // inverse factorial modulo by Fermat's little thorm 
    for(lld i=0;i<N-1;i++) 
        af[i+2] = ( af[i+1] * ia(i+2,MOD-2) ) % MOD ;
    //rep(10) cout<<af[i]<<" "; PEL;
}

int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int t;cin>>t;
    lld ans=1;
    lld all=0;
    init();
    while(t--) { 
        int m; cin>>m;
        ans = (( ans * af[m]) % MOD); 
        all+=m;
        map<int,int> dups;
        for(int i=0;i<m;i++) {
            int temp;cin>>temp;
            if(dups.find(temp)!=dups.end()) 
                dups[temp]++;
            else 
                dups[temp]=1;
        }
        For(dups) {
            if(it->second>1) {
                lld tans = 1;
                for(int i=1;i<=it->second;i++) {
                    tans = (( tans * i ) % MOD);
                }
                ans = (( ans * tans) % MOD);
            }
        }
    }
    for(lld i=1;i<=all;i++) {
        ans= ( (ans *i)) % MOD;
    }
    cout<<ans;
    return 0;
}

