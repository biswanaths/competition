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
#define N 1002
#define rep(n) for(int i =0;(i)<(int)(n);(i)++)
#define repij(n,m) for(int i =0;(i)<(int)(n);(i)++) for(int j =0;(j)<(int)(m);(j)++)

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
                  std::ostringstream() << std::dec << x ).str()

#define For(iterable) for(__typeof__((iterable).begin()) it = (iterable).begin(); it != (iterable).end(); ++it)

int g[N][N];
int n;
set<string> words;
map<string,int> al;
map<int, string > ral;
set<string> visited;

int diff(string s, string t) { 
    int cc=0;
    rep(s.size()) {
        cc+= (s[i]!=t[i]);
    }
    return cc;
}

int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    cin>>n;
    rep(n) {
        string temp; cin>>temp;
        words.insert(temp);
        al[temp] = i;
        ral[i]= temp;
    }
    For(al) { 
        string word = it->first;
        for(int i=0;i<word.size();i++) { 
            int cc = 0 ;
            for(int j=0;j<26;j++) { 
                if(word[i]!=j+'a') { 
                    string pos = word;
                    pos[i]=j+'a';
                    if(words.find(pos)!=words.end()) {
                        int pi = al[pos];
                        g[al[word]][pi]=1;
                        g[pi][al[word]]=1;
                    }
                }
            }
        }
    }

    for(int i=0;i<10;i++) { 
        for(int j=0;j<10;j++) { 
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }

    string src="cat", des="tat";

    queue<string> q;
    q.push(src);
    while(!q.empty()) {
        string rword = q.front();
        q.pop();
        visited.insert(rword);
        cout<<rword<<endl;
        if(des==rword) {
            cout<<"Found the destination "<<endl;
            return 0;
        }
        int r = al[rword];
        for(int i=0;i<N;i++) { 
            if(g[r][i]==1) { 
                string next = ral[i];
                if(visited.find(next)==visited.end())
                    q.push(ral[i]);
            }
        }
    }

    cout<<"Could not find the path "<<endl;

    return 0;
}

