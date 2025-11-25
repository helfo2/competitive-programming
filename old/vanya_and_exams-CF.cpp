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
#define sz(a) int((a).size()) 
#define pb push_back 
#define mp make_pair
#define p push
#define f first
#define s second
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
#define BUFF ios::sync_with_stdio(false);
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
const int MOD = 1e9 + 9;

bool comp(pair<ll, ll>& a, pair<ll, ll>& b) {
	return (a.s < b.s);
}

int main(void) { BUFF
	ll n, max_grade, avg;

	cin >> n >> max_grade >> avg;

	ll a, b;
	vector<pair<ll, ll> > grades(n);

	ll sum = 0;
	for(int i = 0; i < n; i++) {
		cin >> a >> b;
		grades[i] = mp(a, b);
		sum += a;
	}

	avg *= n;
	sort(all(grades), comp);

	ll essays = 0, needed = avg - sum;

	int i = 0;
	while(needed > 0 && i < n) {
		if(grades[i].f < max_grade) {
			if(needed >= (max_grade - grades[i].f)) {
				essays += grades[i].s * (max_grade - grades[i].f);
				needed -= (max_grade - grades[i].f);
			} else {
				essays += grades[i].s * needed;
				needed = 0;
			}
		}
		
		i++;
	}
	
	cout << essays << endl;

	return 0;
}
