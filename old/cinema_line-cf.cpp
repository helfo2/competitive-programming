#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <list>
using namespace std;
#define sz(a) (int)((a).size()) 
#define pb push_back 
#define mp make_pair
#define p push
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d%d", &a, &b)
#define sc3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define scs(a) scanf("%s", a)
#define pri(x) printf("%d\n", x)
#define prie(x) printf("%d ", x)
#define buff ios::sync_with_stdio(false)
#define db(x) cerr << #x << " == " << x << endl
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ii> vii;
typedef vector< vii> vvii;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ld pi = acos(-1);

int main(void) { 
	int n, troco; sc(n);
	map<int, int> notas;

	bool falta = false;
	
	int v; sc(v); notas[v]++; n--;
	
	if(v != 25) falta = true;
	else while(n--) {
		sc(v);
		
		if(v == 50) {
			if(notas[25] >= 1) {
				notas[25]--;
			} else {
				falta = true;
				break;
			}
		}
		else if(v == 100) {
			if(notas[50] >= 1 && notas[25] >= 1) {
				notas[50]--;
				notas[25]--;
			}
			else if(notas[25] >= 3) {
				notas[25] -= 3;
			}
			else {
				falta = true;
				break;
			}
		}
		
		notas[v]++;
	}

	printf(!falta ? "YES\n" : "NO\n");
	
	return 0;
}
