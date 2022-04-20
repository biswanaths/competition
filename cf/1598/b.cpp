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


int s[N];
int g[10], c[10];

string solve() {
    int n,t; cin>>n;
    
    for(int i=0,k=0;i<5;i++) {
        int a = 1<<i;
        for(int j=i+1;j<5;j++) {
            int b = 1<<j;
            g[k++]=a|b;
        }
    }

    rep(10) c[i]=0;

    rep(n) {
        s[i]=0;
        for(int k=0;k<5;k++) {
            cin>>t;
            s[i] = s[i] * 2 + t;
        }
        for(int k=0;k<10;k++)  {
            if(g[i]&s[i])
                c[k]++;

        }
    }
    
    rep(10)kK
    
    return "NO";
}



int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int t; cin>>t; t=1;
    while(t--) 
        cout<<solve()<<endl;


    return 0;
}

