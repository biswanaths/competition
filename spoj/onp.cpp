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

bool op(char c) {
    return 
        c == '+' ||
        c == '-' ||
        c == '/' ||
        c == '^' ||
        c == '(' ||
        c == '*' ;
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
        stack<char> ops;
        //cout<<s<<endl;
        rep(s.size()) {
            if(op(s[i])) { ops.push(s[i]); }
            else if(s[i]==')') { 
                char c;
                do { 
                    c = ops.top();ops.pop();
                    if(c!='(')
                    cout<<c;
                }while(c!='(');
            }
            else cout<<s[i];
        }
        cout<<endl;
    }
    return 0;
}


