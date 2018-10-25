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
    int n,a,b;cin>>n>>a>>b;
    int mmax = 0;
    for(int i=1;i<n;i++) {
        int ap = i, bp = n-i;
        int cmin = a + b + 2;

        int amin = a/ap;
        if(amin ==0) continue;
        cmin = cmin < amin ? cmin : amin;

        int bmin = b/bp;
        if(bmin == 0) continue;
        cmin = cmin < bmin ? cmin : bmin;

        mmax = mmax > cmin ? mmax : cmin;
    }
    cout<<mmax;

    return 0;
}

