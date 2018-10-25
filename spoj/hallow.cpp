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

void solve(int c,int n) { 
    vector<int> p(n);
    map<int,int> rm;

    int s = 0;
    rep(n) cin>>p[i];
    rm[0]=0;

    rep(n) { 
        s=(s+p[i])%c;
        //cout<<s<<" ";
        if(rm.count(s)) { 
            for(int j=rm[s];j<=i;j++)
                cout<<j+1<<" ";
            return;
        }
        rm[s]=i+1;
    }
    return;
}


int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    while(true) { 
        int c,n;
        cin>>c>>n; 
        if(c==0 && n== 0) break; 
        solve(c,n);
        cout<<endl;
    }

    return 0;
}

