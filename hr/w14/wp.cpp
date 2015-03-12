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

#define PB push_back
#define ST first
#define ND second

int a[N],b[N];
int n,k,temp;

void pl() {
    rep(n) cout<<a[i]<<" "; PEL;
    rep(n) cout<<b[i]<<" "; PEL;
}

int main() 
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    cin>>n>>k;
    rep(n) cin>>a[i],b[a[i]-1]=i;
    rep(n) {
        int xp = b[n-i-1];
        int yp = b[a[i]-1];
        int bxp = a[xp]-1;
        int byp = a[i]-1;
        if(xp==yp) continue;
        temp = a[xp];a[xp]=a[yp];a[yp]=temp;
        temp = b[bxp];b[bxp]=b[byp];b[byp]=temp;
        k--;
        if(k==0) break;
    }
    rep(n) cout<<a[i]<<" ";
    return 0;
}

