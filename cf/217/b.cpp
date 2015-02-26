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
int a[101][101];

int main() 
{
#ifndef ONLINE_JUDGE
    //freopen("test.in", "r",stdin);
	//freopen("D:\MyCode\Data\test.out", "w",stdout);
#endif
    cin>>n;
    for(int i=1;i<=n;i++) {
        int k;cin>>k;
        for(int j=1;j<=k;j++) {
            int temp;cin>>temp;a[i][temp]=1;
        }
    }
    
    for(int i=1;i<=n;i++) {
        bool anytrue = false;
        for(int j=1;j<=n;j++) {
            if(i==j) continue;
            bool alltrue = true;
            for(int k=0;k<=100;k++) {
                if(a[j][k]==0) continue;
                else {
                    alltrue = alltrue && a[i][k]; 
                }
            }
            if(alltrue) {
                anytrue = true;
                break;
            }
        }
        if(anytrue) 
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}
