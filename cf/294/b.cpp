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



int main() 
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    map<int,int> e,f;
    int n,t; cin>>n;
    rep(n) {
        cin>>t;  
        if(e.find(t) == e.end()) {
            e[t]=1;f[t]=1;
        }
        else e[t]++,f[t]++;
    }

    rep(n-1) (cin>>t), e[t]--;

    For(e) {
        if(it->second==1) {cout<<it->first<<endl;f[it->first]--;break; }
    }

    rep(n-2) (cin>>t), f[t]--;

    For(f) {
        if(it->second==1) { cout<<it->first<<endl;break;}
    }

    return 0;
}

