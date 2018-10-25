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

#define N 100002
#define rep(n) for(int i =0;(i)<(int)(n);(i)++)
#define repij(n,m) for(int i =0;(i)<(int)(n);(i)++) for(int j =0;(j)<(int)(m);(j)++)

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
                  std::ostringstream() << std::dec << x ).str()

#define For(iterable) for(__typeof__((iterable).begin()) it = (iterable).begin(); it != (iterable).end(); ++it)



void solve() { 
    int n; cin>>n; 
    vector<int> v(2*n);
    stack<int> s;
    vector<int> cc(n+1,0);
    rep(2*n) { 
        cin>>v[i];
    }
    s.push(v[0]);
    for(int i=1;i<2*n;i++) {
        if(v[i]==s.top()) { 
            s.pop();
        } else {
            cc[s.top()]++;
            s.push(v[i]);
        }
    }
    rep(n) cout<<i+1<<" -> "<<cc[i+1]<<endl;
    
}



int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int t; cin>>t;
    rep(t) { 
        cout<<"Case "<<i+1<<":"<<endl;
        solve();
    }

    return 0;
}

