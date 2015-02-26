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

int prev[N],diff[N];

int main() 
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("D:\MyCode\Data\test.out", "w",stdout);
#endif
    rep(N) prev[i] = -1,diff[i]=-1;;
    cin>>n; 
    rep(n) { 
        int temp; 
        cin>>temp; 

        if(prev[temp]==-1) 
            prev[temp] = i,diff[temp]=0; 
        else if( diff[temp] == 0 ) 
            diff[temp] = i - prev[temp];
        else {
            if( diff[temp] == i - prev[temp] ) {
                prev[temp] = i;
                continue;
            }
            else 
                diff[temp] = -1; 
        }

        prev[temp] = i;
    }
    int sum = 0; 
    rep(N) if(diff[i]>=0) sum++; cout<<sum<<endl;
    rep(N) 
        if(diff[i]>=0) 
            cout<<i<<" "<<diff[i]<<endl;
    
    return 0;
}
