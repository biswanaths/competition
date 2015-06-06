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
#define N 5000002 
#define rep(n) for(int i =0;(i)<(int)(n);(i)++)
#define repij(n,m) for(int i =0;(i)<(int)(n);(i)++) for(int j =0;(j)<(int)(m);(j)++)

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
                  std::ostringstream() << std::dec << x ).str()

#define For(iterable) for(__typeof__((iterable).begin()) it = (iterable).begin(); it != (iterable).end(); ++it)

#define PB push_back
#define ST first
#define ND second

vector<int> primes;
int n;

void init() { 
    n = sqrt(N)+1;
    primes.push_back(2);
    primes.push_back(3);
    bool isp = false;
    int cur ;
    for(int i=6;i<n+1;i+=6) { 
        cur = i-1;
        isp = true;
        rep(primes.size()) { 
            isp = isp && (cur % primes[i]);
            if(!isp) break;
        }
        if(isp) primes.push_back(cur);
        
        cur = i+1;
        isp = true;
        rep(primes.size()) { 
            isp = isp && (cur % primes[i]);
            if(!isp) break;
        }
        if(isp) primes.push_back(cur);
    }
}

map<int,int> cnt;

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
        int b,a; cin>>b>>a;
        lld ans =0;
        for(int i=a+1;i<=b;i++) { 
            if(cnt.find(i)!=cnt.end()) ans+=cnt[i];
            else { 
                int val =0;
                int p = i;
                for(int i=0;i<primes.size() && p > 1;i++) { 
                    while(p%primes[i]==0) val++, p/=primes[i];
                }
                cnt[i] = val;
                ans += cnt[i];
            }
        }
        cout<<ans<<endl;
    }


    return 0;
}

