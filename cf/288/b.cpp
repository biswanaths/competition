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

string s;
int main() 
{
#ifndef ONLINE_JUDGE
	//freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    cin>>s;
    int z = s.size();
    for(int i=0;i<z-1;i++) { 
        if((s[i]-'0')%2==0 && (s[i]-'0') < (s[z-1]-'0')) {
            char c = s[z-1];s[z-1]=s[i];s[i]=c;
            cout<<s; return 0;
        }
    }
    for(int i=z-1;i>=0;i--) { 
        if((s[i]-'0')%2==0) {
            char c = s[z-1];s[z-1]=s[i];s[i]=c;
            cout<<s; return 0;
        }
    }

    cout<<"-1";

    return 0;
}

