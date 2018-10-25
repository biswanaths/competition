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
#define N 300002
#define rep(n) for(int i =0;(i)<(int)(n);(i)++)
#define repij(n,m) for(int i =0;(i)<(int)(n);(i)++) for(int j =0;(j)<(int)(m);(j)++)

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
                  std::ostringstream() << std::dec << x ).str()

#define For(iterable) for(__typeof__((iterable).begin()) it = (iterable).begin(); it != (iterable).end(); ++it)

LL a[N],b[N];
int n;

LL calculate(bool top, int pos,int run ) { 
    if(pos==n) return 0L;
    if(top) { 




int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    cin>>n;
    rep(n) cin>>a[i];
    rep(n) cin>>b[i];

    LL ans1 = 0, ans2 = 0;
    LL run1 = 0, run2=0;
    rep(n) 
        ans1 += run1++ * a[i];

    rep(n) { 
        ans1 += run1++ * b[n-i-1];

        if(i%2) { 
            ans2 += run2++ * b[i];
            ans2 += run2++ * a[i];
        } else {
            ans2 += run2++ * a[i];
            ans2 += run2++ * b[i];
        }

    }

    cout<<(ans1>ans2?ans1:ans2);

    return 0;
}

