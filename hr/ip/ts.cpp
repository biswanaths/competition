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

map<int,set<int> > edges;
int id[1002];
queue<int> q;
int n,m;

void pushtoqueue() {
    rep(n) {
        if(id[i]==0) q.push(i);
    }
}
    

int solve(int n) {
    while(!q.empty()) { 
        int curr = q.front();
        q.pop(); 
        if(curr==-1 && (!q.empty())) q.push(-1);
    }
    return 0;
}

int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int t; cin>>t;
    for(int ti=1;ti<=t;ti++) {
        cin>>n>>m;
        map<int, set<int> > ed; queue<int> eq;
        swap(edges,ed); swap(q,eq);
        memset(id,0,sizeof(id));
        rep(m) {
            int a,b;cin>>a>>b;
            if(edges.find(a)==edges.end()) 
                edges[a]=set<int>();
            edges[a].insert(b);
            id[b]++;
        }
        pushtoqueue();
        q.push(-1);
        int s = solve(n);
        cout<<"Case "<<ti<<": ";
        if(s==-1) cout<<"Never Ends"<<endl;
        else cout<<s<<" semester(s)"<<endl;
    }

    return 0;
}

