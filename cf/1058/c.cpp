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

int p[100];


int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int n; cin>>n;
    string s; cin>>s;
    
    int sum = s[0]-'0', csum=0;


    for(int i=1;i<n;i++) { 
        int j=i;
        csum = 0; 
        bool match  = false;
        while(j<n) { 
            match = false;
            csum += s[j++]-'0';
            if(s[j]=='0') continue;
            if(csum==sum) { match = true, csum =0;}
            if(csum>sum) { match = false;  break;}
        }

        //cout<<i<<" "<<j<<" "<<n<<" "<<sum<<" "<<csum<<endl;


        if(match  )  { 
            cout<<"YES"<<endl;
            return 0;
        }

        sum+=s[i]-'0';
    }




    cout<<"NO";


    return 0;
}

