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

string s;

int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int n,m;cin>>n>>m;
    cin>>s; 
    s = "x" + s + "x";
    int p,inv=0; char c;
    for(int i=1;i<=n;i++) 
        if(s[i]=='.' && s[i-1]=='.') inv++;
    while(m--) { 
        cin>>p>>c;
        if((c=='.' && s[p]=='.') || (c!='.' && s[p]!='.')) {s[p]=c; cout<<inv<<endl;continue; }
        if(c=='.') { 
            if(s[p-1]=='.' && s[p+1]=='.') inv+=2; else
            if(s[p-1]=='.' || s[p+1]=='.') inv+=1; else 
                                           inv+=0;
        } else { 
            if(s[p-1]=='.' && s[p+1]=='.') inv-=2; else
            if(s[p-1]=='.' || s[p+1]=='.') inv-=1; else 
                                           inv-=0;
        }
        s[p]=c;
        cout<<inv<<endl;
    }


    return 0;
}

