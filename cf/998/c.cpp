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

int n,x,y;
string s,s1;

LL cost(int p) {
    return 0;
}
     



int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    cin>>n>>x>>y>>s1;
    s += s1[0];
    for(int i=1;i<n;i++) { 
        if(s1[i]==s1[i-1]) 
            continue;
        else 
            s += s1[i];
    }
    cout<<s<<endl;
    if(s[0]=='1') s = s.substr(1,s.size()-1);
    cout<<s<<endl;
    int n = s.size()/2;
    cout<<n<<endl;
    if(s.size()==0) { cout<<0; return 0;}
    cout<<(((n-1)*min(x,y))+y);

    return 0;
}

