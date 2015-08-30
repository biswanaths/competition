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

#define BIG 999999999

int u,v;
int d[4001];
map<int, set<int> > edges;
vector< PII > el;
bool visited[4001];

int dfs(int a) { 
    if(visited[a]) return 0;
    int ans=edges[a].size();
    For(edges[a]) {
        ans+=dfs( *it );
    }
    return ans;
}

int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int n,m;cin>>n>>m;
    rep(n+2) edges[i] = set<int>();
    rep(m) { 
        cin>>u>>v;
        el.push_back(make_pair(u,v));
        d[u]++,d[v]++;
        edges[u].insert(v);
        edges[v].insert(u);
    }

    int mans = BIG;

    for(int i=0;i<el.size();i++) { 
        For(edges[el[i].first]) { 
            if(edges[el[i].second].find(*it) != edges[el[i].second].end()) {
                int ans = edges[*it].size();
                ans += edges[el[i].first].size();
                ans += edges[el[i].second].size();
                ans -= 6;
                mans = min(mans,ans);
            }
        }
    }

    cout<<(mans==BIG?-1:mans);

    return 0;
}

