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

char flip(char c) {
    return c=='R'?'B':'R';
}

int runs[N];

int solve(string s) {
    rep(s.size()) runs[i]=0;
    char prev='a';
    string t="";
    rep(s.size()) {
        if(s[i]!=prev) t+=s[i];
        prev=s[i];
        runs[t.size()-1]++;
    }
    int res = t.size();
    for(int i=1;i<t.size()-1;i++) {
        if(runs[i]==1) { 
            if(t.size()>3)
                return res-2;
            else 
                return res-1;
        }
    }
    if(runs[0]==1 || runs[t.size()-1]==0) {
        if(t.size()==2) 
            return 2;
        else 
            return t.size()-1;
    }
    return res;
}



int main() 
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int t; cin>>t;
    while(t--) { 
        string s;cin>>s;
        cout<<solve(s)<<endl;
    }
    return 0;
}

