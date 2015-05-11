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

int a[26];
int as =0;

int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int b; cin>>b;
    string s; cin>>s;
    set<char> done;
    string ans = "";
    for(int i=0;i<s.size();i++) {
        if(b) {
        if(done.find(s[i])==done.end()) {
            ans += "\n"; ans += s[i];
            b--;
            done.insert(s[i]);
        }
        else 
            ans += s[i];
        } else 
            ans += s[i];
    }
    if(b==0) {
        cout<<"YES"<<ans;
    }
    else cout<<"NO";

    return 0;
}
