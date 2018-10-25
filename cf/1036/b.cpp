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
    LL t; cin>>t; 
    rep(t) { 
        LL x,y,k;
        cin>>x>>y>>k;
        if(max(x,y)>k) { cout<<-1<<endl; continue; }
        LL ans = min(x,y); 
        LL ra =max(x,y)- min(x,y);
        if(ra%2==0) { 
            ans+=ra;
        }
        else { 
            ans+=ra; k--;
        }
        if((k-ans)%2==0) ans+=(k-ans); 
        else ans+=(k-ans-1);

        cout<<ans<<endl;
    }

    return 0;
}

