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
vector<PII> moves;

PII start() { 
    repij(8,8) 
        if(grid[i][j]=='M') return make_pair(i,j);
    return make_pair(0,0);
}

bool isfree(int x,int y,int steps) {
    if(x-steps>=0 && grid[x-steps][y]=='S') return false;
    return true;
}

bool isin(int x,int y) {
    return (x >=0 && x <=7 && y>=0 && y<=7);
}

bool dfs(int x,int y,int steps) { 
    if(steps > 30) return false;
    if(!isin(x,y)) return false;
    if(!isfree(x,y,steps)) return false;
    if(steps> 0 && !isfree(x,y,steps-1)) return false;
    if(grid[x][y]=='A') return true;
    bool reached = false;
    For(moves) 
        reached = reached || dfs(x+it->first,y+it->second,steps+1);
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
    int m[] = { -1,0,1};
    repij(3,3) moves.push_back(make_pair(m[i],m[j]));
    cout<<(dfs(s.first,s.second,0)?"WIN":"LOSE")<<endl;
    return 0;
}

