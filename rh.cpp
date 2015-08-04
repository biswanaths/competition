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

set<string> tree;       // for representing the huffman tree
set<string> visited;    // for representing the already frequency assigned nodes 

lld ans;                // The final answer
const int tot = 100;    // The total frequency which needs to distributed across the nodes
string temp;


// if the node differs at position, the node having 1 is the right to the node having 0 
// as per convention
inline string rmost(string s,string t) {
    rep(s.size()) {
        if(s[i]>t[i]) return s;
        else if(s[i]<t[i]) return t;
    }
    return s;
}

// This function works as a, kind of, priority queue of 
// not assigned nodes
// It works as a reverse huffman as it will first work with 
// the node which has a maximum available frequency 
// if the weight is same, it will pick the less deeper node 
// if the heights are also same it will pick the right most node
// after picking the node it will distribute all possible values to its children
// if all nodes are distributed then it means there is a successulf distrubtion and
// we increase the count to one 
// cm  = current minimum, will constrain the future distribution 
// cdt = current distribution tree, at each node we augement this tree with possible childs 
void traverse(int cm, map<string,int>& cdt) { 
    string cnode="-1"; int mv = -1;
    For(cdt) { 
        string pnode = it->first;int pw = it->second;
        if( visited.find(pnode) == visited.end()) {
            if( pw > mv) { 
                mv = pw;
                cnode = pnode;
            }
            else if( cnode !="-1" && pw == mv) {
                if(cnode.size()==pnode.size()) {
                    cnode = rmost(cnode,pnode);
                } else { 
                    cnode = ( cnode.size()<pnode.size())?cnode:pnode;
                }
            }
        }
    }

    if(cdt.size()==tree.size()) { // all the nodes got frequency
        ans++;
        return;
    }

    visited.insert(cnode);

    int weight = cdt[cnode];

    if(tree.find(cnode+"0") == tree.end()) { // leaf node, nothing to distribute
        traverse(cm,cdt);
        visited.erase(cnode);
        return;
    }

    string left = cnode + "0", right = cnode + "1";
    
    map<string,int> ncdt(cdt);
    for(int i=1;i <= cm && i<<1 <= weight ;i++) {  // all the possible distribution 
        if(weight-i > cm) continue;
        ncdt[left] =i;ncdt[right]=weight-i;
        traverse(i,ncdt);
    }
    visited.erase(cnode);
}



int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    for(int test_case=1;;test_case++) {
        int n; cin>>n;
        if(n==0) break;
        ans = 0 ; visited.clear();tree.clear();
        rep(n) { 
            cin>>temp;
            for(int i=0;i<=temp.size();i++) {
                string n = temp.substr(0,i); // insert all the possible nodes
                tree.insert(n);
            }
        }
        map<string,int> cdt;
        cdt[""] = tot; // The root node gets all the frequency 
        traverse(tot,cdt);
        cout<<"Case "<<test_case<<": "<<ans<<endl;
    }
    return 0;
}

