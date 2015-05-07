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

#define PB push_back
#define ST first
#define ND second
#define __debug(x) cout<<#x<<" : "<<x<<endl;

int rev(int a) { 
    int r =0;
    while(a>0) { 
        r= r *10 + (a%10);
        a/=10;
    }
    return r;
}


int solve(int n) { 
    if(n < 10) return n;
    int ans =0,start = 10;
    int steps[] = {9,9,99,99,999,999,9999,9999,99999,99999,999999,999999,9999999,9999999};
    int is = 1 ,prev=0;
    ans = 10;
    int l =0;
    while(start <= n) {
        prev = steps[is] + steps[is-1];
        ans += prev;
        is += 1;
        start *= 10;
        l = l * 10 + 9;
    }
    ans -= prev;
    start/=10;
    int i;
    cout<<start<<" "<<ans<<endl;
    for(i=start;i<=start+l;i++) {
        if(i==n) return ans +(n-i);
        if(rev(i)>n) break;
    }
    if(rev(i) >n) i--;
    ans += i - start +1;
    int r = rev(i);
    if(r==i) ans--;
    ans += n-r;
    return ans;
}


int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	freopen("test.out", "w",stdout);
#endif
    int t;cin>>t;
    rep(t) { 
        int sm; cin>>sm;
        cout<<"Case #"<<i+1<<": "<<solve(sm)<<endl;
    }

    return 0;
}

