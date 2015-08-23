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


lld invalidWithA(lld a,lld b,lld c,lld l) { 
    if(a<b+c) return 0;
    lld d = min(l,a-b-c);
    return ((d+1)*(d+2))/2;
}

int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    lld a,b,c,l;cin>>a>>b>>c>>l;
    lld ans= ((l+3)*(l+2)*(l+1))/6;
    for(lld i=0;i<=l;i++) { 
        ans-= invalidWithA(a+i,b,c,l-i);
        ans-= invalidWithA(b+i,a,c,l-i);
        ans-= invalidWithA(c+i,b,a,l-i);
    }
    cout<<ans;
    return 0;
}

