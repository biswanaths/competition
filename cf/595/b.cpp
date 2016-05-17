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

int len(int aa) { 
    int k=1;
    while(aa>=10) k++,aa/=10;
    return k;
    //if(aa < 10) return 1; 
    //return 1 + len(aa/10);
}

int lt10(int aa,int k) { 
    if(len(aa)<k) return 0;
    while(aa>10) aa/=10;
    return aa;
}

int a[N],b[N];


int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int n,k;cin>>n>>k;
    int m = n/k;
    rep(m) cin>>a[i];
    rep(m) cin>>b[i];

    lld ans=1;

    rep(m) {
        int start=0 ;
        int cans=0;
        while( len(start) <= k) {
            //cout<<start<<" : "<<len(start)<<endl;
            if(b[i]!=lt10(start,k)) cans++;
            start += a[i];
        }
        //cout<<cans<<endl;
        ans *= (lld ) cans;
        ans = ans % 1000000007;
    }
    cout<<ans;

    return 0;
}

