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

string grid[8];

PII start() { 
    repij(8,8) 
        if(grid[i][j]=='M') return make_pair(i,j);
    return make_pair(0,0);
}

bool isfree(int x,int y,int moves) {
    if(x-moves>=0 && grid[x-moves][y]=='S') return false;
    return true;
}

bool dfs(int x,int y,int moves) { 
    if(moves > 30) return false;
    bool reached = false;
    if(grid[x][y]=='A') return true;
    if(        isfree(x  ,y,moves) && isfree(x  ,y,moves+1)) 
        reached = reached || dfs(x  ,y,moves+1);
    if(x!=0 && isfree(x-1,y,moves) && isfree(x-1,y,moves+1)) 
        reached = reached || dfs(x-1,y,moves+1);
    if(x!=7 && isfree(x+1,y,moves) && isfree(x+1,y,moves+1)) 
        reached = reached || dfs(x+1,y,moves+1);
    if(y!=0 && isfree(x,y-1,moves) && isfree(x,y-1,moves+1)) 
        reached = reached || dfs(x,y-1,moves+1);
    if(y!=7 && isfree(x,y+1,moves) && isfree(x,y+1,moves+1)) 
        reached = reached || dfs(x,y+1,moves+1);
    if(x!=0 && y!=0 && isfree(x-1,y-1,moves) && isfree(x-1,y-1,moves+1))
        reached = reached || dfs(x-1,y-1,moves+1);
    if(x!=0 && y!=7 && isfree(x-1,y+1,moves) && isfree(x-1,y+1,moves+1))
        reached = reached || dfs(x-1,y+1,moves+1);
    if(x!=7 && y!=0 && isfree(x+1,y-1,moves) && isfree(x+1,y-1,moves+1))
        reached = reached || dfs(x+1,y-1,moves+1);
    if(x!=7 && y!=7 && isfree(x+1,y+1,moves) && isfree(x+1,y+1,moves+1))
        reached = reached || dfs(x+1,y+1,moves+1);
    return reached;
}


int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    rep(8) cin>>grid[i];
    PII s = start();
    cout<<(dfs(s.first,s.second,0)?"WIN":"LOSE")<<endl;
    return 0;
}

