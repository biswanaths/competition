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
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)	
#define rep(n) for(int i =0;(i)<(int)(n);(i)++)
#define repi(n) for(int i =0;(i)<(int)(n);(i)++)
#define repj(n) for(int j =0;(j)<(int)(n);(j)++)
#define repij(n,m) for(int i =0;(i)<(int)(n);(i)++) for(int j =0;(j)<(int)(m);(j)++)
#define rep1n(n) for(int i=1;i<(int )(n);i++)

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
                  std::ostringstream() << std::dec << x ).str()

#define For(iterable) for(__typeof__((iterable).begin()) it = (iterable).begin(); it != (iterable).end(); ++it)

#define PB push_back
#define ST first
#define ND second

int gcd(int a,int b) { 
    if(a==0 || b==0) return (a+b);
    return gcd(b,a%b);
}


int main() 
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    set< PII > s;
    int n,x,y; cin>>n>>x>>y;
    rep(n) {
        int a,b; cin>>a>>b;
        int yy = b-y, xx = a-x;
        int g = gcd( abs(xx) , abs(yy));
        yy = yy/g; xx = xx/g; 
        if(xx == 0) yy = abs(yy);
        if(yy == 0) xx = abs(xx);
        if( xx < 0) xx *= -1, yy*= -1;
        PII ns(xx,yy);
        s.insert(ns);
    }
    cout<<s.size();

    return 0;
}

