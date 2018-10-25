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
    LL a,b; cin>>a>>b; 
    vector<LL > f,s;
    LL l = sqrtl(a+b)-1; 
    LL n = l;
    //cout<<n<<endl;
    for(; (n*(n+1))<= 2*(a+b);n++); 
    n--;
    //cout<<n<<endl;

    for(LL i=n;i > 0   ; i--) {
        //cout<<a<<" "<<b<<endl;
        if(a>b) f.push_back(i), a-=i; 
        else s.push_back(i), b-=i;
    }
    cout<<f.size()<<endl;
    rep(f.size()) cout<<f[i]<<" ";
    cout<<endl;
    cout<<s.size()<<endl;
    rep(s.size()) cout<<s[i]<<" ";

    return 0;
}

