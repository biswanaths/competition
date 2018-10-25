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
#define N 1000002
#define rep(n) for(int i =0;(i)<(int)(n);(i)++)
#define repij(n,m) for(int i =0;(i)<(int)(n);(i)++) for(int j =0;(j)<(int)(m);(j)++)

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
                  std::ostringstream() << std::dec << x ).str()

#define For(iterable) for(__typeof__((iterable).begin()) it = (iterable).begin(); it != (iterable).end(); ++it)


int solve() { 
    int n; 
    map<int , int > s;
    int l;
    cin>>n;
    set<int> keys;
    rep(n) {
        cin>>l; s[l]++;
        if(s[l]>=2) keys.insert(l);
    }

    double  minimal = 999999999999;
    int prev = 0;
    int xi, yi;

    //for(int i=1;i<10002;i++) { 
    for(auto i:keys) { 
    //    cout<<i<<endl;
        if(s[i]>=4) {
            for(int j=0;j<4;j++) cout<<i<<" "; 
            return 0;
        }
        
        if(s[i]>=2) { 
            if(prev==0) { 
                prev = i; 
                continue;
            }
            double x = prev, y = i;
            double c = (x/y) + (y/x);
            if(c<minimal) { 
                minimal = c;
                xi = prev; yi = i;
            }
            prev = i;
        }
    }
    cout<<xi<<" "<<xi<<" "<<yi<<" "<<yi;
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
    rep(t) {
        solve();
        cout<<endl;
    }

    return 0;
}

