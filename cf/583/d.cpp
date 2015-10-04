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

int n,t;
int a[103],o[103],r[103];

map<int, int> c;


int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    cin>>n>>t;
    rep(n) (cin>>a[i]),c[a[i]]++;

    for(int i=0;i<n;i++) { 
        o[i]=1;
        for(int j=0;j<i;j++) { 
            if(a[i]>=a[j] && o[i]<=o[j]) {
                o[i]=o[j]+1;
            }
        }
    }

    //rep(n) cout<<o[i]<<" "; PEL;

    for(int i=n-1;i>=0;i--) { 
        r[i]=1;
        for(int j=n-1;j>i;j--) { 
            if(a[i]<=a[j] && r[i]<=r[j]) {
                r[i]=r[j]+1;
            }
        }
    }

    //rep(n) cout<<r[i]<<" "; PEL;

    int ans, mans =0;

    for(int i=0;i<n;i++) { 
        ans = o[i];
        ans+= ((t>2)?((t-2)*c[a[i]]):0);
        if(ans > mans) mans = ans;
        if(t==1) continue;
        for(int j=0;j<n;j++) { 
            if(a[i]<=a[j]) {
                if( ans + r[j] > mans) {
                    mans = ans + r[j];
                }
            }
        }
    }

    cout<<mans;

    return 0;
}

