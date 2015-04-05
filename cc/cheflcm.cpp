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
#define N 1000000002
#define rep(n) for(int i =0;(i)<(int)(n);(i)++)
#define repij(n,m) for(int i =0;(i)<(int)(n);(i)++) for(int j =0;(j)<(int)(m);(j)++)

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
                  std::ostringstream() << std::dec << x ).str()

#define For(iterable) for(__typeof__((iterable).begin()) it = (iterable).begin(); it != (iterable).end(); ++it)

#define PB push_back
#define ST first
#define ND second

vector<int> primes;
int L;

void init() { 
    primes.push_back(2);
    primes.push_back(3);
    primes.push_back(5);
    primes.push_back(7);
    L = sqrt(N)+1;
    bool found = false;
    int testing; 
    for(int i=12;i<=L;i+=6) { 
        found = true; testing = i - 1;
        for(int j=0;j<primes.size();j++) {
            if(testing%primes[j]==0) {found = false ; break;}
        }
        if(found) primes.push_back(testing);
        found = true; testing = i + 1;
        for(int j=0;j<primes.size();j++) {
            if(testing%primes[j]==0) {found = false ; break;}
        }
        if(found) primes.push_back(testing);
    }
}

lld solve(lld n) {
    lld ans = 1;
    for(int i=0;i<primes.size() && n > 1;i++) {
        int count =1 ;
        lld fsum = 1;
        while(n%primes[i]==0) { 
            count *= primes[i];
            fsum += (lld )count;
            n/=primes[i];
        }
        ans *= fsum;
    }
    if(n!=1) ans*=++n;
    return ans;
}

int bf(int n) {
    lld s=0;
    for(int i=1;i<=n;i++) {
        s+= (n%i?0:i);
    }
    return s;
}

int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    clock_t start = clock();
    init();
    double duration = (clock() - start ) / (double ) CLOCKS_PER_SEC;
    //cout<<fixed<<setprecision(9)<<duration<<endl;
    int n,t; cin>>t;
    while(t--) {
        //cin>>n;
        n=50000000+t;
        if(solve(n)!=bf(n)) cout<<n<<" "<<solve(n)<<" "<<bf(n)<<endl;
        if(t%100==0) cout<<t<<endl;
        //cout<<solve(n)<<endl;
    }
    cout<<"done"<<endl;
    return 0;
}

