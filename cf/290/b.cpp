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

string v[52];
int k[52][52];
int r,c;

bool dfs(int x,int y,int n,char prev) { 
    //cout<<x<<" "<<y<<" "<<n<<" "<<prev<<endl;
    if(x<0 || x>=r) return false;
    if(y<0 || y>=c) return false;
    if(v[x][y]!=prev) return false;
    if(k[x][y]==0) {
        k[x][y]=n;
        bool ret = false;
        ret = dfs(x+1,y,n+1,v[x][y]); if(ret) return ret;
        ret = dfs(x,y+1,n+1,v[x][y]); if(ret) return ret; 
        ret = dfs(x-1,y,n+1,v[x][y]); if(ret) return ret;
        ret = dfs(x,y-1,n+1,v[x][y]); if(ret) return ret;

    } else {
        if(n - k[x][y] >= 4) return true;
    }
    return false;
}

int main() 
{
#ifndef ONLINE_JUDGE
	//freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    cin>>r>>c;
    for(int i=0;i<r;i++) 
        cin>>v[i];
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) { 
            if(k[i][j]==0) {
                if(dfs(i,j,0,v[i][j])) {
                    cout<<"Yes";
                    return 0;
                }
            }
        }
    }
    cout<<"No";

    return 0;
}

