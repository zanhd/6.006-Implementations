#include<bits/stdc++.h>
#define FastIO  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
#define FreOpen freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define bigint int64_t
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define MAX INT_MAX
#define MIN INT_MIN
#define INF 1e18
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define vect vector<int>
#define pair_int pair<int,int>
#define paircout(x) cout<<"{"<<(x).first<<" "<<(x).second<<"}";
#define maxheap(T) priority_queue<T>
#define minheap(T) priority_queue<T,vector<T>,greater<T>>
#define mapofvector map<int,vector<int>>
#define mapofset map<int,set<int>>
#define Matrix(type) vector<vector<type>>
#define loop(i,a,b) for(ll i = a; i <= b; i++)
#define rloop(i,a,b) for(ll i = a; i >= b; i--)
#define loopSTL(itr,STL) for (auto itr = STL.begin(); itr != STL.end(); ++itr)
#define sq(a) (a)*(a)
#define NextPermutationSTL(STL) next_permutation(STL.begin(), STL.end())
#define NextPermutation(a,size) next_permutation(a,a+size)
//string tranform
#define lower(str) transform(str.begin(),str.end(),str.begin(),::tolower);
#define upper(str) transform(str.begin(),str.end(),str.begin(),::toupper);
#define lexcompare(str1,size1,str2,size2) lexicographical_compare(str1, str1+size1, str2, str2+size2)
//Modular Arthematics
#define MOD ((ll) 1e9 + 7)
#define MOD2 ((ll) 1e9 + 9)
#define ModAdd(a,b,N) 		((a)%(N) + (b)%(N))%(N);
#define ModSub(a,b,N) 		((a)%(N) - (b)%(N))%(N);
#define ModMultiply(a,b,N)	((a)%(N) * (b)%(N))%(N);
//extra
#define ceil_div(a,b) (a+b-1)/(b)
#define gcd(a,b) __gcd((long long int) a,(long long int) b)
using namespace std;

const ll N = 1e5;

vector<pair<ll, ll>> adj[N + 1]; // adj[u] = vector of {v,w};

bool vis[N + 1] = {0};

bool compare(pair<ll, ll> a, pair<ll, ll> b)
{
	return a.second > b.second; //for min heap
}

vector<ll> dikstra(ll src, ll n)
{
	vector<ll> dis(n, INF);

	priority_queue < pair<ll, ll>, vector < pair<ll, ll>>, function < bool(pair<ll, ll>, pair<ll, ll>) >> Q (compare);

	Q.push({src, 0});

	while (!Q.empty())
	{
		pair<ll, ll> now = Q.top(); Q.pop();

		ll u = now.first;

		if (vis[u]) continue;
		vis[u] = 1;
		dis[u] = now.second;

		for (auto x : adj[u])
		{
			ll v = x.first, w = x.second;
			if (vis[v]) continue;
			Q.push({v, dis[u] + w});
		}
	}

	return dis;
}

void Solve()
{
	ll v, e; cin >> v >> e;

	loop(i, 1, e)
	{
		ll u, v, w; cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	ll src; cin >> src;

	for (auto x : dikstra(src, v)) cout << x << " ";
}

int main(int argc, char const * argv[])
{

	FastIO;
	//FreOpen;
	int T = 1;
	//cin >> T;
	while (T--) Solve();
	return 0;
}