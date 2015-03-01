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


void solve(string s) { 
    set<string> all;
    for(int i=1;i<4;i++) {
        for(int j=0;j+i<=s.size();j++) {
            all.insert(s.substr(j,i));
        }
    }
    for(int i=1;i<=576*26;i++) {
        string s ="";int t=i;
        while(t) {
            int c = (t-1)%26;
            s= ((char )('A'+c)) + s;
            t-= (c+1);
            t/=26;
        }
        if(all.find(s)==all.end()){
            cout<<s<<endl;
            return;
        }
    }
}


int main() 
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    string s; 
    while(cin>>s) {
        solve(s);
    }
    return 0;
}

