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




int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int n; cin>>n; 
    vector<int> l(n),r(n),rank(n);
    rep(n) cin>>l[i];
    rep(n) cin>>r[i];
    rep(n) { 
        rank[i] = l[i]+r[i];
        if(l[i]>i || r[i] >= (n-i)) { 
            //cout<<i<<" "<<l[i]<<" "<<r[i]<<endl;
            cout<<"NO"; 
            return 0;
        }
    }
    vector<int> ver(rank);
    sort(ver.begin(), ver.end());
    rep(n) { 
        if(ver[i]==i || (i>0 && ver[i]==ver[i-1])) { }
        else { 
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES"<<endl;
    rep(n) cout<<n-rank[i]<<" ";

    return 0;
}

