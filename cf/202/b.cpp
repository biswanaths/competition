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

int a[100003];
int ans[9];

int main() 
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("D:\MyCode\Data\test.out", "w",stdout);
#endif
    cin>>n;
    for(int i=0;i<9;i++) cin>>a[i];
    int me = * min_element(a,a+9);
    int mei = -1;
    for(int i=0;i<9;i++) {
        if(a[i]==me) mei=i;
    }
    ans[mei] = n/me; 
    int leftover = n % a[mei];
    int posi = 0;

    while(ans[mei] && leftover > 0 && posi >= 0) { 
        posi = -1;
        //cout<<leftover<<" "<<ans[mei]<<endl;
        for(int i=0;i<9;i++) { 
            if(i > mei && a[i] <= a[mei] + leftover ) {
                posi = i;
            }
        }
        if( posi != -1) { 
            ans[mei]--;
            ans[posi]++;
            leftover = leftover + a[mei] - a[posi];
        }

    }
    for(int i=8;i+1;i--) 
        for(int j=0;j<ans[i];j++)
            cout<<i+1;
    int sum=0;for(int i=0;i<9;i++) sum+=ans[i];
    if(sum==0) cout<<-1;

	return 0;
}
