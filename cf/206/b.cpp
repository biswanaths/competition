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

#define PB push_back
#define ST first
#define ND second

int c1,c2,c3,c4;
int bn,tn;
int b[1003],t[1003];

int minbus() {
    int cost = 0 , c= 0;
    for(int i=0;i<bn;i++) { 
        cost += min ( b[i] * c1, c2);
    }
    return cost;
}

int mint() { 
    int cost =0,c=0;
    for(int i=0;i<tn;i++) { 
        cost += min ( t[i] * c1, c2);
    }
    return cost;
}
            

int main() 
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("D:\MyCode\Data\test.out", "w",stdout);
#endif
    cin>>c1>>c2>>c3>>c4;
    cin>>bn>>tn;
    rep(bn) cin>>b[i];
    rep(tn) cin>>t[i];
    cout<<min(c4,min(2*c3,min(c3,minbus())+min(c3,mint())));
    return 0;
}
