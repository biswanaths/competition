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

LL gcd(LL u, LL v) {
    while ( v != 0) {
        LL r = u % v;
        u = v;
        v = r;
    }
    return u;
}

vector <LL> v;
    
LL l,r,x,y,ans=0;

void f2(LL a, LL b, int i) { 
    if(i==v.size()) { 
        if( l<=x*a && x*a<=r && 
             l<=x*b && x*b<=r )  {
     //       cout<<a<<" "<<b<<endl;
            ans++;
        }
        return;
    }
    f2(a*v[i],b,i+1);
    f2(a,b*v[i],i+1);
    return;
}
    


void nf(LL a) { 
    LL ans = 1;
    LL srt = sqrt(2*a);
    int yes = 0;
    while(a%2==0) { 
        yes = 1;
        a/=2;
        ans*=2;
    }

    if(yes) v.push_back(ans);

    for(LL i=3;i<=srt;i+=2) { 
        ans = 1, yes=0;
        while(a%i==0) { 
            yes = 1;
            a/=i;
            //cout<<a<<" "<<endl;
            ans*=i;
        }
        if(yes) v.push_back(ans);
    }
}



int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    cin>>l>>r>>x>>y;
    nf(y/x);
    //For(v) cout<< *it<<endl;
    f2(1,1,0);
    cout<<ans;

    return 0;
}

