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
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)	
#define rep(n) for(int i =0;(i)<(int)(n);(i)++)
#define repi(n) for(int i =0;(i)<(int)(n);(i)++)
#define repj(n) for(int j =0;(j)<(int)(n);(j)++)
#define repij(n,m) for(int i =0;(i)<(int)(n);(i)++) for(int j =0;(j)<(int)(m);(j)++)
#define rep1n(n) for(int i=1;i<(int )(n);i++)

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
                  std::ostringstream() << std::dec << x ).str()

#define PB push_back
#define ST first
#define ND second
#define N 1000002
#define MOD 1000000007


LL n,r,avg;

int main() 
{
#ifndef ONLINE_JUDGE
	//freopen("test.in", "r",stdin);
	//freopen("D:\MyCode\Data\test.out", "w",stdout);
#endif

    cin>>n>>r>>avg;
    vector<pair<LL,LL> > ps(n);
    LL req= avg * n;
    LL avail = 0;
    for(int i=0;i<n;i++) {
        cin>>ps[i].second>>ps[i].first;
        avail += ps[i].second;
    }

    LL mi,temp;
    sort(ps.begin(),ps.end());
    LL noe = 0,ga;
    for(int i=0;i<n && avail < req ;i++ ) {
        ga = ( r - ps[i].second) < (req-avail) ? ( r- ps[i].second): ( req-avail);
        avail += ga;
        noe += ga * ps[i].first;
    }
    cout<<noe;

    return 0;
}   

