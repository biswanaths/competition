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


int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int n,m; cin>>n>>m;
    vector< PII > s;
    vector<int> p;
    rep(n) {
        int l,r;
        cin>>l>>r; s.push_back(make_pair(l,r));
    }
    for(int i=1;i<=m;i++) { 
        bool in = false;
        for(auto it= s.begin(); it != s.end(); ++it) { 
            if( it->first <= i && i <= it->second) { 
                in = true; 
                break;
            }
        }
        if(!in) p.push_back(i);
    }
    cout<<p.size()<<endl;
    for(int i=0;i<p.size();i++) 
        cout<<p[i]<<" ";

    return 0;
}

