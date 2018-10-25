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
typedef pair<LL, LL> PLL; 

#define F first
#define S second

#define lld long long int 
#define EOL '\0'
#define PEL cout<<endl;
#define N 100002
#define rep(n) for(int i =0;(i)<(int)(n);(i)++)
#define repij(n,m) for(int i =0;(i)<(int)(n);(i)++) for(int j =0;(j)<(int)(m);(j)++)

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
                  std::ostringstream() << std::dec << x ).str()

#define For(iterable) for(__typeof__((iterable).begin()) it = (iterable).begin(); it != (iterable).end(); ++it)

int n,k;

void pt(LL a[]) { 
    rep(n) cout<<a[i]<<" "; cout<<endl;
}

pair< PLL, LL> p[N];
std::priority_queue<LL, std::vector<LL>, std::greater<LL> > pq;

LL ans[N];


int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    cin>>n>>k;

    rep(n) cin>>p[i].F.F;
    rep(n) cin>>p[i].F.S, p[i].S = i;

    sort(p,p+n);

    LL rs = 0;

    rep(n) {
        ans[p[i].S] = p[i].F.S + rs;
        if(k==0) continue;
        if( pq.size() < k) { 
            pq.push(p[i].F.S);
            rs += p[i].F.S;
        } else { 
            if(pq.top()<p[i].F.S) { 
                LL t = pq.top();
                pq.pop();
                pq.push(p[i].F.S);
                rs -= t;
                rs += p[i].F.S;
            }
        }
    }

    pt(ans);

    return 0;
}

