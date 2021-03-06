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

using namespace std;

#define fori(n) for(int i=0;i<(n);i++) 

class Highscore {
public:
	int getRank(vector <int> scores, int newscore, int places) {
		int pos = 1;
		fori(scores.size()) {
			if(scores[i]>newscore) pos++;
			if(scores[i]==newscore) continue;
			if(scores[i]>newscore) break; 
		}
		return pos;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, int p1, int p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << p1 << "," << p2;
	cout << "]" << endl;
	Highscore *obj;
	int answer;
	obj = new Highscore();
	clock_t startTime = clock();
	answer = obj->getRank(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p3 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p3;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	vector <int> p0;
	int p1;
	int p2;
	int p3;
	
	{
	// ----- test 0 -----
	int t0[] = {100,90,80};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 90;
	p2 = 10;
	p3 = 2;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0.clear() /*{}*/;
	p1 = 0;
	p2 = 50;
	p3 = 1;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {10,9,8,7,6,5,4,3,2,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	p2 = 10;
	p3 = -1;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {10,9,8,7,6,5,4,3,3,0};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	p2 = 10;
	p3 = 10;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {2000000000,19539,19466,19146,17441,17002,16348,16343,15981,15346,14748,14594,13752,13684,13336,13290,12939,12208,12163,12133,11621,11119,10872,10710,10390,9934,9296,8844,8662,8653,8168,7914,7529,7354,6016,5428,5302,5158,4853,4538,4328,3443,3222,2107,2107,1337,951,586,424,31};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1337;
	p2 = 50;
	p3 = 46;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
