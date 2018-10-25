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

#define N 100002
#define rep(n) for(int i =0;(i)<(int)(n);(i)++)
#define repij(n,m) for(int i =0;(i)<(int)(n);(i)++) for(int j =0;(j)<(int)(m);(j)++)

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
                  std::ostringstream() << std::dec << x ).str()

#define For(iterable) for(__typeof__((iterable).begin()) it = (iterable).begin(); it != (iterable).end(); ++it)

bool lc(char c) { 
    return c>='a' && c <='z';
}

bool uc(char c) { 
    return c>='A' && c <='Z';
}

bool dc(char c) { 
    return !lc(c) && !uc(c);
}


string solve(string s) { 
    int l=0,u=0,d=0;
    rep(s.size()) {
        char c = s[i];
        l+=lc(c);
        u+=uc(c);
        d+=dc(c);
    }
    rep(s.size()) { 
        char c = s[i];
        if(lc(c) && l>1) {
            if(u==0) 
                s[i]='A', l--,u++;
            else if(d==0) 
                s[i]='1', l--,d++;
        }
        if(uc(c) && u>1) {
            if(l==0) 
                s[i]='a', u--,l++;
            else if(d==0) 
                s[i]='1', u--,d++;
        }
        if(dc(c) && d>1) {
            if(u==0) 
                s[i]='A', d--,u++;
            else if(l==0) 
                s[i]='a', d--,l++;
        }
    }

    return s;
}



int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int t; cin>>t;
    rep(t) { 
        string s; cin>>s; cout<<solve(s)<<endl;
    }

    return 0;
}

