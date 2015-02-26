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

#define For(iterable) for(__typeof__((iterable).begin()) it = (iterable).begin(); it != (iterable).end(); ++it)

#define PB push_back
#define ST first
#define ND second

int a[10];

int main() 
{
#ifndef ONLINE_JUDGE
	//freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    string s;int n; cin>>n;cin>>s;
    for(int i=0;i<s.size();i++) { 
        switch(s[i]) {
            case '0':
            case '1':break;
            case '2':
            case '3':
            case '5':
            case '7': a[s[i]-'0']++;   break;
            case '4': a[2]+=2,a[3]++;  break;
            case '6': a[3]++,a[5]++;   break;
            case '8': a[2]+=3,a[7]++;  break;
            case '9': a[7]++,a[2]++,a[3]+=2; break;
        }
    }
    for(int i=9;i>1;i--) { 
        for(int j=0;j<a[i];j++) {
            cout<<i;
        }
    }

    return 0;
}

