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



int main() 
{
#ifndef ONLINE_JUDGE
	//freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int n;
    int a[6000];
    int b[2000][3];int count=0;
    cin>>n;rep(n) cin>>a[i];
    int ai=0,bi=0,ci=0;
    while(1) { 
        while(ai<n && a[ai++]!=1);
        while(bi<n && a[bi++]!=2);
        while(ci<n && a[ci++]!=3);
        if(a[ai-1] == 1 && a[bi-1]==2 && a[ci-1]==3 ) 
            b[count][0] = ai, b[count][1] = bi, b[count][2] = ci, count++;
        else 
            break;
    }
    cout<<count<<endl;
    rep(count) 
        cout<<b[i][0]<<" "<<b[i][1]<<" "<<b[i][2]<<endl;

    return 0;
}

