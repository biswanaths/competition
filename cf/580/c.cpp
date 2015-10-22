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

int n,m,t; 
int c[N];
vector<int> e[N];
bool visited[N];

int dfs(int node, int cc) { 
    visited[node] = true;
    if(c[node]) 
        cc++;
    else 
        cc=0;
    if(cc>m) return 0;
    int ans=0;
    bool visitedany = false;
    For(e[node]) {
        if(!visited[*it])
            ans += dfs( *it, cc), visitedany = true;
    }
    if(!visitedany) return 1;
    return ans;
}

int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    cin>>n>>m;
    rep(n) (cin>>t),c[i+1]=t;
    rep(n+1) e[i] = vector<int>();
    rep(n-1) { 
        int u,v;cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    cout<<dfs(1,0)<<endl;
    return 0;
}

