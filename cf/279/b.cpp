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


int fa[N], ba[N];
int f[N], b[N];
int n;

int main() 
{
#ifndef ONLINE_JUDGE
    //freopen("test.in", "r",stdin);
	//freopen("D:\MyCode\Data\test.out", "w",stdout);
#endif
    cin>>n; 
    rep(N) fa[i]=ba[i]=-1;
    rep(n) { 
        int ta,tb;cin>>ta>>tb;
        fa[ta]=tb;
        ba[tb]=ta;
        f[i] = ta; b[i] = tb;
    }

    int zs = 0;
    int nzs = -1;
    rep(n) { 
        if(f[i]!=0 && ba[f[i]]==-1) {
            nzs = f[i];
            break;
        }
    }

    cout<<nzs<<" ";
    while(1) {
        int no = 0;
        if(fa[zs]!=0 && fa[zs]!=-1) {
            cout<<fa[zs]<<" "; zs =fa[zs];no=1;
        }
        if(fa[nzs]!=0 && fa[nzs]!=-1) {
            cout<<fa[nzs]<<" "; nzs = fa[nzs];no=1;
        }
        if(no==0) break;
    }

    return 0;
}
