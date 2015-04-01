#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define Max 102
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
vector< pii > adj[Max];
vector<int> w;
bool mark[Max];
int color,u;
long long ans;
bool dfs(int v)
{
    mark[v]=true;
    if(v==u)    {        ans++;     return true;    }
    bool succ= false;
    for(int j=0;j<adj[v].size();j++)
    {
        pii p=adj[v][j];
        if(p.second == color && !mark[p.first])
            if(dfs(p.first)) { succ= true; break;}
    }
    return succ;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int n,m,q;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        --a;--b;
        adj[a].pb(mp(b,c));
        adj[b].pb(mp(a,c));
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int a,b;
        ans=0;
        scanf("%d%d",&a,&b);
        u=--b;a--;
        bool done[102];
        for(int i=0;i<102;i++) done[i] = false;
        for(int j=0;j<adj[a].size();j++)
        {
            for(int mi=0;mi<102;mi++) mark[mi]=false;
            color=adj[a][j].second;
            if(done[color]) continue;
            mark[a]=true;
            if(dfs(adj[a][j].first)) done[color] = true;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
