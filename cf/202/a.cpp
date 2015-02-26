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

int a[100005],c[2];
int main() 
{
#ifndef ONLINE_JUDGE
	//freopen("D:\\MyCode\\Data\\test.in", "r",stdin);
	//freopen("D:\MyCode\Data\test.out", "w",stdout);
#endif
	cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) { 
        int temp = a[i];
        if(temp == 100 ) 
            if( c[1] > 0 && c[0] >0 ) 
                c[1]--, c[0]--;
            else if(c[0]>2) 
                c[0]-=3;
            else{ 
                cout<<"NO";return 0;}
        else if(temp == 50 ) 
            if(c[0] >0 ) 
                c[0]--,c[1]++;
            else{ 
                cout<<"NO";return 0;}
        else 
            c[0]++;
    }

    cout<<"YES";
    return 0;
}
