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


int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int n,s;cin>>n>>s; 
    vector<int> v(n);
    rep(n) cin>> v[i];
    sort(v.begin(),v.end());
    int m = v[n/2];
    LL ans =0;
    if(m>s) {
        for(int i=n/2;i>=0;i--) {
            if(v[i]<=s) break;
            ans+=(( LL )(v[i]-s));
        }
    }
    if(m<s) {
        for(int i=n/2;i<n;i++) {
            if(v[i]>=s) break;
            ans+=((LL ) (s-v[i]));
        }
    }
    cout<<ans;

    return 0;
}

