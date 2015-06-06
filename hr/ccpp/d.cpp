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

bool (* vs[20])(char c);
set<string> pins;

bool isd(char c) { 
    return '0' <=c && c<= '9';
}

bool isc(char c) { 
    return 'A' <=c && c<='Z';
}

bool iss(char c) {
    return c =='-';
}

void init() { 
    rep(20) 
        vs[i] = &isd;
    vs[3] = &iss;
    vs[6] = &iss;
    vs[9] = &iss;
    vs[18] = &iss;
    vs[19] = &isc;
}


void process(string s) {
    for(int k=0;k<s.size();k++) { 
        int j=0;bool yes = true;
        for(;j<20 && k+j<s.size();j++) {
            yes = yes && vs[j](s[k+j]);
        }
        if(j==20 && yes ) {
            pins.insert(s.substr(k,20));
        }
    }
}


int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int n;cin>>n;
    init();
    while(n--) { 
        string s; cin>>s;
        process(s);
    }
    if(pins.size() == 0) { 
        cout<<"JUNK";
        return 0;
    }
    For(pins) 
        cout<< *it <<endl;

    return 0;
}

