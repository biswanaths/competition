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

int c[101][2];
int a[202];

int main() 
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("D:\MyCode\Data\test.out", "w",stdout);
#endif
    cin>>n;

    rep(2*n)  {
        int temp;
        cin>>temp;
        c[temp][0]++;
        a[i] = temp;
    }

    int total = 0 ;
    int diff = 0;

    for(int i=0;i<101;i++) {
        if(c[i][0]) 
            if(c[i][0]==1) 
                diff++;
            else 
                diff+=2;
    }

    total = ( diff - diff/2) * (diff/2);

    cout<<total<<endl;

    int start = 0;

    for(int i=0;i<101;i++) {
        if(c[i][0]>1)
            c[i][1] = start,start = ( c[i][0] & 1 ) ?start ^= 1 :start;
    }

    for(int i=0;i<101;i++) { 
        if(c[i][0]==1) 
            c[i][1] = start, start ^=1;
    }

    for(int i=0;i<2*n;i++) { 
        cout<< c[a[i]][1] + 1<<" ";
        c[a[i]][1] ^= 1;
    }

    return 0;
}
