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

#define N 100002
#define rep(n) for(int i =0;(i)<(int)(n);(i)++)
#define repij(n,m) for(int i =0;(i)<(int)(n);(i)++) for(int j =0;(j)<(int)(m);(j)++)

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
                  std::ostringstream() << std::dec << x ).str()

#define For(iterable) for(__typeof__((iterable).begin()) it = (iterable).begin(); it != (iterable).end(); ++it)

char g[2002][2002];

int cost[2002][2002][2];
bool visited[2002][2002];

int n,m,r,c,X,Y;

void visit( int x, int y, int cl, int cr) { 
    
    cout<<x<<"-"<<y<<" cost "<<cl<<"-"<<cr<<endl;
    
    if(x<1 || x>n || y<1 || y>m) return;
    if(cl> X || cr > Y) return;

    if(!visited[x][y]) {
        cost[x][y][0] = cl, cost[x][y][1] = cr;
        visited[x][y] = true;
    }
    else { 
        if(cost[x][y][0] >= cl &&  cost[x][y][1] >= cr) 
            return;
        cost[x][y][0] = min(cost[x][y][0], cl);
        cost[x][y][1] = min(cost[x][y][1], cr);
    }


    if(g[x+1][y]=='.') visit(x+1,y,cl,cr);
    if(g[x-1][y]=='.') visit(x-1,y,cl,cr);
    if(g[x][y+1]=='.') visit(x,y+1,cl,cr+1);
    if(g[x][y-1]=='.') visit(x,y-1,cl+1,cr);
}



int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    cin>>n>>m>>r>>c>>X>>Y;
    int ans=0;
    rep(n) { 
        string s; cin>>s; 
        for(int j=0;j<m;j++) { 
            g[i+1][j+1] = s[j];

        }
    }
	freopen("test.in", "r",stdin);

    visit(r,c,0,0);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) { 
            cout<<visited[i][j]<<" ("<<cost[i][j][0]<<", "<<cost[i][j][1]<<") ";
            ans+=visited[i][j];
        }
        cout<<endl;
    }

    cout<<ans;

    return 0;
}

