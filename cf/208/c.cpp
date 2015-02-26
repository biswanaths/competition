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
#define N 100002

int w[N];
int n,l,r,ql,qr;
int c[N][N][2];

PII eat(int left,int right) {
    if(left>right) 
        return PII(0,0);

    if(c[left][right][0]) 
        return PII(c[left][right][0],c[left][right][1]);

    PII li = eat(left,right-1);
    PII ri = eat(left+1,right);

    LL rmin = min( li.first + w[right] * r , li.second + w[right] * r + qr );
    LL lmin = min ( ri.first + w[left] * l + ql , ri.second + w[left] * l );

    c[left][right][0] = lmin; 
    c[left][right][1] = rmin;
    
    return PII(lmin,rmin);
}

int main() 
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("D:\MyCode\Data\test.out", "w",stdout);
#endif
    cin>>n>>l>>r>>ql>>qr;
    rep(n) (cin>>w[i]), c[i][i][0]=w[i]*l,c[i][i][1]=w[i]*r;
    PII f =eat(0,n-1);
    cout<<min(f.first,f.second);
    return 0; 
}
