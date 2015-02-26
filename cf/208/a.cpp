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
int a[1003];

int main() 
{
#ifndef ONLINE_JUDGE
	//freopen("test.in", "r",stdin);
	//freopen("D:\MyCode\Data\test.out", "w",stdout);
#endif
    cin>>n;
    rep(n) cin>>a[i];

    for(int i=1;i<n;i++) { 
        int y1 = min(a[i],a[i-1]);
        int y2 = max(a[i],a[i-1]);
        for(int j=1;j<i;j++) { 
            int x1 = min(a[j],a[j-1]);
            int x2 = max(a[j],a[j-1]);
            if(( y1<= x1 && x2 <= y2 ) || (x1 <=y1 && y2 <= x2 ) || (x2 <= y1) || (y2<=x1)) {
                continue;
            }
            else {
                cout<<"yes";
                return 0;
            }
        }
    }

    cout<<"no";
    return 0;
}
