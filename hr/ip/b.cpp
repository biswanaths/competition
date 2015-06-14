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
#include <climits>


using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

#define lld long long int 
#define EOL '\0'
#define PEL cout<<endl;
#define N 10002
#define rep(n) for(int i =0;(i)<(int)(n);(i)++)
#define repij(n,m) for(int i =0;(i)<(int)(n);(i)++) for(int j =0;(j)<(int)(m);(j)++)

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
                  std::ostringstream() << std::dec << x ).str()

#define For(iterable) for(__typeof__((iterable).begin()) it = (iterable).begin(); it != (iterable).end(); ++it)

int vd[N];
int n,e,k;
map<int,map<int,int> > g;
map<int,map<int,int> > s;
set<int> en;
int cost[N];

void traverse(int node,int c) {
    For(g[node]) {
        //cout<<"z: "<<node<<" "<<it->first<<" "<<it->second<<endl;
        if(cost[it->first] > (c + it->second)) {
            cost[it->first] = c + it->second;
            traverse(it->first,cost[it->first]);
        }
    }
}

int start;

int traverse_k(int node,int c, int u,int gc) {
    if(en.find(node)!=en.end()) {
    //    cout<<node<<" "<<c<<endl;
        return c;
    }
    int cc = gc;
    For(g[node]) {
        if( c + it->second < cc ) {
            cc = min(cc,traverse_k(it->first,c+it->second,u,cc));
        }
    }
    if(u<=0) return cc;
    if(s.find(node)==s.end()) return cc;
    For(s[node]) {
        //cout<<"s :" <<it->first<<" "<<it->second<<endl;
        if( c + it->second < cc ) {
            cc = min(cc,traverse_k(it->first,c+it->second,u-1,cc));
        }
    }
    return cc;
}

int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    cin>>n>>e>>k;
    rep(n-1) { 
        int a,b,w;cin>>a>>b>>w;
        if(g.find(a)==g.end()) g[a] =  map<int,int>();
        if(g.find(b)==g.end()) g[b] =  map<int,int>();
        vd[a]++,vd[b]++;
        g[a][b]=w;g[b][a]=w;
    }

    if(n==1) vd[1]++;
    rep(n+1) {
        if(vd[i]==1) cost[i]=0,en.insert(i);
    }
    rep(e) { 
        int a,b,w;cin>>a>>b>>w;
        if(s.find(a)==s.end()) s[a] =  map<int,int>();
        if(s.find(b)==s.end()) s[b] =  map<int,int>();
        if(g[a].find(b)==g[a].end()) s[a][b]=s[b][a]=w;
        if(g[a].find(b)!=g[a].end() && g[a][b]>w) s[a][b]=s[b][a]=w;
    }

    rep(n) cost[i+1]=INT_MAX;
    For(en)  
        cost[*it]=0, traverse(*it,0);

    //rep(n) cout<<cost[i+1]<<endl; PEL;

    rep(n) {
        cout<<traverse_k(i+1,0,k,cost[i+1])<<endl;
    }

    return 0;
}

