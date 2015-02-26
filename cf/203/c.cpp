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
int a[100005],b[100005];

int main() 
{
#ifndef ONLINE_JUDGE
	//freopen("D:\\MyCode\\Data\\test.in", "r",stdin);
	//freopen("D:\MyCode\Data\test.out", "w",stdout);
#endif
    cin>>n;
    rep(n) cin>>a[i];
    rep(n) cin>>b[i];
    a[n]=2;
    b[n]= n+1;	
    int mlen = -1, mleni = -1;
    for(int i=0;i<n;i++) { 
        int len = 0,j ;
        if(a[i]==1) {
            for(j=i-1;j>=0;j--) {
                if(a[j]==0 && b[j+1]==j+1) 
                    len++;
                else 
                    break;
            }
        }
        if( len > mlen) {
            mlen = len; 
            mleni = j+1;
            cout<<mlen<<" "<<mleni<<endl;
        } 

    }
    for(int i=mleni;a[i]!=1;i++) cout<<i<<" ";
	return 0;
}
