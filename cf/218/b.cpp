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

int n; 
map< pair< int,int >, int > c;

int f(int a,int b) {
//    cout<<a<<" "<<b<<endl;
    if(a==b) return 0;
    int moves = 99999999;
    PII p(a,b);
    if(c.find(p) != c.end()) {
 //       cout<<"found really"<<endl;
        moves = c[p];
        return moves;
    }
    if(a>b) {
        if(a%2==0) 
            moves = min(moves,f(a/2,b));
        if(a%3==0) 
            moves = min(moves,f(a/3,b));
        if(a%5==0) 
            moves = min(moves,f(a/5,b));
    }
    else {
        if(b%2==0) 
            moves = min(moves,f(a,b/2));
        if(b%3==0) 
            moves = min(moves,f(a,b/3));
        if(b%5==0) 
            moves = min(moves,f(a,b/5));
    }
    if(moves== 99999999)
        c[p]=moves;
    else 
        c[p] = moves+1;
  //  cout<<"moves "<<c[p]<<endl;
    return c[p];
}


int main() 
{
#ifndef ONLINE_JUDGE
    //freopen("test.in", "r",stdin);
	//freopen("D:\MyCode\Data\test.out", "w",stdout);
#endif
    int a,b;cin>>a>>b;
    int ans = f(a,b);
    if(ans == 99999999) 
        cout<<-1;
    else 
        cout<<ans;
    return 0;
}
