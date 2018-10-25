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

set<LL > divs;
set<LL > ndivs;

LL gcd(LL a, LL b) { 
    if(a%b==0) return b; 
    return gcd(b,a%b);
}

void pdivs() {
    for(auto d:divs) 
        cout<<d<<" ";
    cout<<endl;
}



int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    LL n; cin>>n; 
    LL x,y;cin>>x>>y;
    divs.insert(x);
    divs.insert(y);

    rep(n-1) { 
        cin>>x>>y;
        ndivs.clear();
        for(auto d:divs) { 
            LL c = gcd(d,x);
            if(c>1) ndivs.insert(c);
            c = gcd(d,y);
            if(c>1) ndivs.insert(c);
        }
        divs = ndivs;
        if(divs.size()==0) break;
    }

    if(divs.size()) 
        for(auto d:divs) {
            cout<<d; 
            break;
        }
    else 
        cout<<-1;

    return 0;
}

