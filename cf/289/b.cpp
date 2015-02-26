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

int ava[102];
int cur[102];
int peb[102][102];
int n,k;

int main() 
{
#ifndef ONLINE_JUDGE
	//freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    cin>>n>>k;
    int mc = 999999;
    for(int i=1;i<=n;i++) {
        cin>>ava[i];
        mc = min(mc,ava[i]);
    }

    for(int i=1;i<=n;i++) {
        if(ava[i] > mc + k) {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES"<<endl;

    for(int i=1;i<=n;i++) {
        int c =1;
        for(int j=1;j<=ava[i];j++) {
            cout<<c<<" ";
            if(j>mc) c++;
        }
        cout<<endl;
    }

    return 0;
}

