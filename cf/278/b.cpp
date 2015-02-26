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


void pl(int a[] ) {
    if(a[0]!=66) return;
    for(int i=0;i<4;i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}


int main() 
{
#ifndef ONLINE_JUDGE
    //freopen("test.in", "r",stdin);
	//freopen("D:\MyCode\Data\test.out", "w",stdout);
#endif

    int n;cin>>n;
    int b[4];rep(n) cin>>b[i];

    int a[4];
    if(n==4) {
        sort(b,b+4);
        if( b[3] == 3*b[0] && b[3] + b[0] == b[1] + b[2])
            cout<<"YES";
        else 
            cout<<"NO";
        return 0;
    }

    for(int k=2;k<1601;k+=2) { 
        a[0]=k/2;a[1]=3*a[0];
        for(int j=a[0];j<=a[1];j++) {
            a[2]=j;a[3]=2*k-j;
            int c = 0;
            for(int i=0;i<n;i++) {
                for(int jj=0;jj<4;jj++) {
                    if(a[jj]==b[i]) {a[jj]=-a[jj];c++;break;}
                }
            }
            if(c==n) {
                cout<<"YES"<<endl;
                for(int i=0;i<4;i++) 
                    if(a[i]>0) cout<<a[i]<<endl;
                return 0;
            }
            rep(4) a[i]=abs(a[i]);
       }
    }

    cout<<"NO";

    return 0;
}
