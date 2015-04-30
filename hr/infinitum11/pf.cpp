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
#define N 2000002
#define rep(n) for(int i =0;(i)<(int)(n);(i)++)
#define repij(n,m) for(int i =0;(i)<(int)(n);(i)++) for(int j =0;(j)<(int)(m);(j)++)

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
                  std::ostringstream() << std::dec << x ).str()

#define For(iterable) for(__typeof__((iterable).begin()) it = (iterable).begin(); it != (iterable).end(); ++it)

#define PB push_back
#define ST first
#define ND second

vector<int> primes;

lld ans=0;

void init() {
    int limit = sqrt(N)+1;
    primes.push_back(2);
    primes.push_back(3);
    int test; bool prime;

    for(int t=6;t<limit;t+=6) {
        test = t-1;prime = true;
        rep(primes.size()) {
            if(test%primes[i]==0) {prime=false; break; }
        }
        if(prime) primes.push_back(t-1);
        
        test = t+1;prime = true;
        rep(primes.size()) {
            if(test%primes[i]==0) {prime=false; break; }
        }
        if(prime) primes.push_back(t+1);
    }
    //rep(10) cout<<primes[i]<<" ";
}

void solve(int n) {
    int limit = sqrt(n) +2;
    for(int i=0; i <primes.size() && primes[i] < limit ; i++) {
        while(n%primes[i]==0) ans+= primes[i], n/=primes[i];
    }
    if(n>1) ans+=n;
}


int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    init();
    int t;cin>>t;
    rep(t) {
        int n;cin>>n;solve(n);
    }
    cout<<ans<<endl;

    return 0;
}

