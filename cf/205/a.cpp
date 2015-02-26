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

int m; int n ; 


int main() 
{
#ifndef ONLINE_JUDGE
	//freopen("D:\\MyCode\\Data\\test.in", "r",stdin);
	//freopen("D:\MyCode\Data\test.out", "w",stdout);
#endif
    cin>>n; 
    bool ee= false, oo=false,eo=false,oe=false;

    int sumx=0,sumy=0,x,y;

    rep(n) {
        cin>>x>>y;
        sumx+=x,sumy+=y;
        ee = ee || (!(x&1) && !(y&1)); 
        oo = oo || (x&1 && y&1); 
        oe = oe || (x&1 && !(y&1)); 
        eo = eo || (!(x&1) && y&1); 
    }

    if( !(sumx&1) && !(sumy&1) ) {cout<<0; return 0;}
    if( sumx & 1 && sumy & 1 && ( oe ||eo)) {cout<<1; return 0;}
//#    if( sumx & 1 && !(sumy&1) && oo) {cout<<1; return 0;}
    //if( !(sumx&1) && sumy&1 && oo) {cout<<1; return 0;}

    cout<<-1;
    return 0;
}
