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




int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int t; cin>>t;
    while(t--) { 
        int c[26],mc=0;memset(c,0,sizeof(c));
        string s; cin>>s;
        rep(s.size()) { 
            c[s[i]-'a']++;
        }
        rep(26) mc=max(mc,c[i]);
        int l = s.size()/2;
        if(s.size()%2) l++;
        if(mc>l) {cout<<-1<<endl; continue;}
        string ss; rep(s.size()) ss+="*";
        int k=0;
        int mi = 0;
        mc = c[0]; 
        for(int i=1;i<26;i++) { 
            if( mc < c[i]) { 
                mc = c[i],mi = i;
            }
        }
        for(int i=0;i<c[mi];i++) 
            ss[k] = 'a'+mi, k+=2;
        c[mi]=0;

        for(int i=0;i<26;i++) { 
            while(c[i]>0 && k<ss.size()) ss[k]='a'+i,k+=2,c[i]--;
        }
        k=1;
        for(int i=0;i<26;i++) { 
            while(c[i]>0 && k<ss.size()) ss[k]='a'+i,k+=2,c[i]--;
        }
        cout<<ss<<endl;
    }

    return 0;
}

