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
#define rep(n) for(int i =0;(i)<(int)(n);(i)++)
#define repij(n,m) for(int i =0;(i)<(int)(n);(i)++) for(int j =0;(j)<(int)(m);(j)++)

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
                  std::ostringstream() << std::dec << x ).str()

#define For(iterable) for(__typeof__((iterable).begin()) it = (iterable).begin(); it != (iterable).end(); ++it)

#define PB push_back
#define ST first
#define ND second


int main() 
{
#ifndef ONLINE_JUDGE
	//freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif

    map<char,int> ss,tt;
    string s,t;cin>>s>>t;
    rep(26) ss['a'+i]=0, ss['A'+i]=0;
    rep(26) tt['a'+i]=0, tt['A'+i]=0;
    rep(s.size()) ss[s[i]]++;
    rep(t.size()) tt[t[i]]++;

    int y=0,w=0,c;

    rep(26) {
        c = min(ss['a'+i],tt['a'+i]);
        y+=c;ss['a'+i]-=c;tt['a'+i]-=c;
        c = min(ss['A'+i],tt['A'+i]);
        y+=c;ss['A'+i]-=c;tt['A'+i]-=c;
        w+= min(ss['a'+i],tt['A'+i]) + min(ss['A'+i],tt['a'+i]);
    }


    cout<<y<<" "<<w;

    return 0;
}

