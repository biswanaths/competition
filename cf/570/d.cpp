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

map<int, vector<int> > tree;
string s;

map<int, map<int, string> > all;

map<int,string>  dfs(int node,int d) { 
    rep(d) cout<<" ";
    cout<<node;
    cout<<s[node-1]<<endl;
    all[node] = map<int, string>();
    all[node][d]=s[node-1];
    if(tree.find(node)==tree.end()) {
        return all[node];
    } 
    for(int i=0;i<tree[node].size();i++) { 
        map<int, string> cur = dfs(tree[node][i],d+1);
        For(cur) { 
            int cd = it->first; string cs=it->second;
            string s = all[node][cd];
            all[node][cd] = all[node][cd]+cs;
        }
    }
    return all[node];
}

int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int n,q,p;cin>>n>>q;
    rep((n-1)) { 
        cin>>p;
        if(tree.find(p)==tree.end())  
            tree[p] = vector<int>(1,i+2);
        else 
            tree[p].push_back(i+2);
    }

    cin>>s;
    dfs(1,1);

    for(int i=1;i<7;i++) { 
        cout<<i<<"---->"<<endl;
        For(all[i]) { 
            cout<<it->first<<" "<<it->second<<endl;
        }
        cout<<endl;
    }


    return 0;
}

