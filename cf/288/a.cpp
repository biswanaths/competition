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

int a[1002][1002];

int main() 
{
#ifndef ONLINE_JUDGE
	//freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int n,m,k;cin>>n>>m>>k;
    bool done = false;
    int km = 0;
    for(int i=1;i<=k;i++) { 
        int r,c;cin>>r>>c;
        if(done) continue;
        a[r][c]=1;
        if( a[r][c]==1 && a[r+1][c]==1 && a[r][c+1] ==1 && a[r+1][c+1]==1) {
            done = true; } else
        if( a[r][c]==1 && a[r][c-1]==1 && a[r+1][c] ==1 && a[r+1][c-1]==1) {
            done = true; } else
        if( a[r][c]==1 && a[r-1][c]==1 && a[r][c+1] ==1 && a[r-1][c+1]==1) {
            done = true; } 
        if( a[r][c]==1 && a[r][c-1]==1 && a[r-1][c] ==1 && a[r-1][c-1]==1) {
            done = true; }
        if(done) km = i;
    }
    cout<<km;
    return 0;
}

