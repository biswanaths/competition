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

int n, ans=0;;
map<LL,int> v;
vector<LL> p;
LL t=1;


int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    rep(50) p.push_back(t), t*=2;
    cin>>n; rep(n) cin>>t, v[t]++;
    LL k =0;
    for(auto it = v.begin(); it != v.end(); ++it) { 
        bool exist = false;
        LL f = it->first , s = it->second;
        for(int i=0;i<50;i++) { 
            LL other = p[i] - f;
            k++;
            int co = 0 ; 
            if(v.count(other)>0) co = v[other];
            if( (other != f  && co>0 ) || (other == f  && co>1)) {
                exist = true;
                break;
            }
        };
        if(!exist) ans += s;
    }
    cout<<ans;

    return 0;
}

