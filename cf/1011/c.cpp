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

int n, m; 
int a[1002],b[1002];

double takeoff(double w, int i) { 
    double c = w/( (double)(a[i]-1));
    return c ;
}

double touchdown(double w, int i) { 
    double c = w/( (double)(b[i]-1));
    return c ;
}

double ans = 0 ;

int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    cin>>n>>m;
    bool can = true;
    rep(n) cin>>a[i],can=can&&(!(a[i]==1));
    rep(n) cin>>b[i],can=can&&(!(b[i]==1));
    double cw = m ,fw =0;

    if(!can) {cout<<-1; return 0;}

    fw = touchdown(cw,0);
    cw+= fw; 
    ans+= fw;

    for(int i=n-1;i>=0;i--) {

        fw  = takeoff(cw,i);
        cw += fw;
        ans+= fw;

        if(i!=0) {
            fw  = touchdown(cw,i);
            cw += fw;
            ans+= fw;
        }

    }

    cout<< fixed << setprecision(8) << ans ;

    return 0;
}

