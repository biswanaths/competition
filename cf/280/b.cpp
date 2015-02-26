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
#define N 2000002
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

int n;
LL l;
LL a[1002];

int main() 
{
#ifndef ONLINE_JUDGE
    freopen("test.in", "r",stdin);
	//freopen("D:\MyCode\Data\test.out", "w",stdout);
#endif
    cin>>n>>l;
    repi(n) { 
        cin>>a[i];
    }
    sort(a,a+n);
    long long ml = -1;
    for(int i=1;i<n;i++) { 
        ml = ( ml > ( a[i]-a[i-1]) ) ? ml: (a[i]-a[i-1]);
    }


    long double max = ((double ) ml) / 2.0;
    if(a[0]!=0) max = max > (double)a[0] ? max : a[0];
    if(a[n-1]!=l) max = max > ((double)(l-a[n-1])) ? max : (l-a[n-1]);

    cout.precision(15);
    cout<<max;
    return 0;
}
