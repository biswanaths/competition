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

vector<int> g[200002];
set<int> visited;
queue<int> current;
map<int, int> p;

int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int n; cin>>n; 

    rep(n-1) { 
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> v(n);
    rep(n) cin>>v[i];
    current.push(1);
    int l =0;
    p[1]=l;
    visited.insert(1);

    while(!current.empty()) {
        int c = current.front();current.pop();
        //cout<<c<<" ";
        for(auto&it :g[c]) {
            if(visited.find(it) == visited.end()) {
                current.push(it);
                visited.insert(it);
                p[it]=p[c]+1;
                //cout<<it<<" "<<p[it]<<endl;
            }
        }
    }
    rep(n) { 
        v[i] = p[v[i]];
        cout<<v[i]<<" ";
    }
    bool fine = true; 
    for(int i=1;i<n;i++)  
        fine = fine && ( (v[i] == v[i-1]) || (v[i]==v[i-1]+1));
    if(fine) cout<<"Yes";
    else cout<<"No";

    return 0;
}

