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

#define For(iterable) for(__typeof__((iterable).begin()) it = (iterable).begin(); it != (iterable).end(); ++it)

#define PB push_back
#define ST first
#define ND second

int b[101],g[101];
int n,m;
int main() 
{
#ifndef ONLINE_JUDGE
	//freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    cin>>n>>m;
    int hb,hg;
    int temp;
    cin>>hb;rep(hb) { cin>>temp; b[temp]=1; }
    cin>>hg;rep(hg) { cin>>temp; g[temp]=1; }
    int prev = hb + hg; 
    int a = min(n,m);int aa=0 ;
    for(aa=a;!((aa%n==0) && (aa%m==0)); aa+=a);
    a=aa;
    int curr=0;

    while(1) { 
        curr = 0 ;
        for(int i=0;i<a;i++) { 
            b[i%n]=g[i%m]=(b[i%n] || g[i%m]);
        }
        rep(n) curr+= b[i];
        rep(m) curr+= g[i];
        if(curr == prev) break;
        prev = curr;
    }
    cout<<(curr==n+m?"Yes":"No");

    return 0;
}

