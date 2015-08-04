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

vector<PII > pa,na;
int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int n;cin>>n;
    rep(n) { 
        int a,b;cin>>a>>b;
        if(a>0) pa.push_back(make_pair(a,b));
        else na.push_back(make_pair(a,b));
    }
    sort(pa.begin(),pa.end());
    sort(na.begin(),na.end());
    reverse(na.begin(),na.end());
    int ms = min(pa.size(),na.size()), ans=0;
    rep(ms) {
        ans += pa[i].second + na[i].second;
    }

    if(pa.size()> ms) ans+= pa[ms].second;
    else if(na.size()>ms ) ans+= na[ms].second;
    cout<<ans;

    return 0;
}

