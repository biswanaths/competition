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

string s,t;
int n;


int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    cin>>n; 
    cin>>s>>t;
    int ans=0;
    rep((n/2)) { 
        char si = s[i], ti = t[i], sj = s[n-i-1], tj = t[n-i-1];
        if( si == ti && sj == tj) ans+=0; 
        else if( si == ti && sj != tj) ans++;
        else if( si != ti && sj == tj) ans++;
        else if( si == tj && sj == ti) ans+=0;
        else if( si == tj && sj != ti) ans++;
        else if( si != tj && sj == ti) ans++;
        else if( si == sj && ti == tj) ans+=0;
        else if( si == sj && ti != tj) ans++;
        else if( si != sj && ti == tj) ans++;
        else ans+=2;
        cout<<ans<<" "<<si<<" "<<ti<<" "<<sj<<" "<<tj<<endl;
    }

    cout<<ans;

    return 0;
}

