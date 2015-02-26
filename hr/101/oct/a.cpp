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

int m; int n ; int c;
int p[150],a[150];


int main() 
{
#ifndef ONLINE_JUDGE
	//freopen("test.in", "r",stdin);
	//freopen("D:\MyCode\Data\test.out", "w",stdout);
#endif
    int t;cin>>t;
    while(t--) {
        rep(100) p[i]=a[i]=0;
    	cin>>n>>c>>m;
        p[0] = m;a[0]=1;
        for(int i=1;p[i-1]<=n;p[i]=p[i-1]*m,a[i]=a[i-1]+p[i-1],i++);
        rep(12) cout<<p[i]<<" "<<a[i]<<endl;
        int total = n/c; 
        int temp = total; 

        while(temp>=m) { 
            int po =0; 
            while( p[po] < temp) po++; 
            if(p[po]>temp) po--;
            temp -= p[po]; 
            temp+=1;
            total += a[po];
        }
        
        cout<<total<<endl;
    }
    return 0;
}
