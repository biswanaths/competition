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

bool eq(lld a,lld b) { 
    lld gcd = __gcd(a,b);
    int pa = b/gcd;
    while(pa%2==0) pa/=2;
    while(pa%3==0) pa/=3;
    if(pa>1) return false;
    int pb = a/gcd;
    while(pb%2==0) pb/=2;
    while(pb%3==0) pb/=3;
    if(pb>1) return false;
    return true;
}

int a[N];

int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int n;cin>>n;
    rep(n) cin>>a[i];
    rep(n) {
        if(!eq(a[0],a[i])) {
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";

    return 0;
}

