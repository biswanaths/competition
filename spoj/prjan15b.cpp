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

set<int> perfect;
int c[400];

void init() { 
    for(int i=2;i<7;i++) { 
        int b=i;
        for(int j=1;j<7;j++) {
            b*=i;
            vector<int> news;
            for(int k=1;k*b<40;k++) {
                news.push_back(k*b);
                For(perfect) news.push_back(*it + k*b);
            }
            For(news) {
                perfect.insert(*it);
                if(*it < 50) c[(*it)]=1;
            }
        }
    }
    rep(49) 
        c[i+1] += c[i];
}
            
void solve(lld a,lld b) {
    lld k =0;
    if(b<36) k = c[b]-c[a-1];
    else if(a> 36) k = b-a+1;
    else 
        k = c[35]+b-36+1-c[a-1];
    cout<<k<<endl;
}

int main() 
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int t;cin>>t;
    init();
    while(t--) {lld a,b; cin>>a>>b;solve(a,b);}
    return 0;
}

