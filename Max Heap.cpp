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

//Note : using 1 based index (left-child : 2*i,right-child = 2*i + 1)

const int N = 1e5;

ll MAX_HEAP[N + 1];
ll size = 0;

ll in()
{
	ll x;
	cout << "Enter a number : "; cin >> x;
	return x;
}

void max_heapify_bottom_up(ll i)
{
	//O(log2(n))
	if (i < 2) return;
	if (MAX_HEAP[i] >  MAX_HEAP[i / 2])
	{
		swap(MAX_HEAP[i / 2] , MAX_HEAP[i]);
		max_heapify_bottom_up(i / 2);
	}
}

void max_heapify_top_down(ll i)
{
	//O(log2(n))
	if (2 * i >= size) return;
	if (2 * i + 1 < size)
	{
		ll mx =  max(MAX_HEAP[i], max(MAX_HEAP[2 * i], MAX_HEAP[2 * i + 1]));
		if (mx == MAX_HEAP[i]) return;
		if (mx == MAX_HEAP[2 * i])
		{
			swap(MAX_HEAP[i], MAX_HEAP[2 * i]);
			max_heapify_top_down(2 * i);
		}
		else
		{
			swap(MAX_HEAP[i], MAX_HEAP[2 * i + 1]);
			max_heapify_top_down(2 * i + 1);
		}
	}
	else
	{
		ll mx = max(MAX_HEAP[i], MAX_HEAP[2 * i]);
		if (mx == MAX_HEAP[i]) return;
		swap(MAX_HEAP[i], MAX_HEAP[2 * i]);
		max_heapify_top_down(2 * i);
	}
}

void insert(ll x)
{
	//O(log2(n))
	if (size > N) cout << "Overflow!!";
	else
	{
		MAX_HEAP[++size] = x;
		max_heapify_bottom_up(size);
		cout << "Inserted!";
	}
}

ll getMaximum()
{
	//O(1)
	if (size) return MAX_HEAP[1];
	cout << "Underflow!!"; return 0;
}

void deleteMaximum()
{
	//O(log2(n))
	if (!size) cout << "Underflow!!";
	else
	{
		swap(MAX_HEAP[1], MAX_HEAP[size]);
		size--;
		max_heapify_top_down(1);
		cout << "Deleted!";
	}
}

void Solve()
{
	cout << "MAX HEAP DATA STRUCTURE" << endl;
	cout << "<---------------------->" << endl;
	char ch = 'y';
	while (ch == 'y' || ch == 'Y')
	{
		cout << "1.Insert" << endl
		     << "2.Maximum" << endl
		     << "3.Abstract Maximum" << endl
		     << "4. deleteMaximum" << endl
		     << "Enter choice (0 for exit) :";

		ll choice; cin >> choice;

		switch (choice)
		{
		case 1 : insert(in()); break;
		case 2 : cout << getMaximum() << endl; break;
		case 3 : cout << getMaximum() << endl; deleteMaximum(); break;
		case 4 : deleteMaximum(); break;
		case 0 : exit(0);
		default : cout << "incorrect choice";
		}

		cout << endl << "continue (y/n) ? : "; cin >> ch; cout << endl;

	}

}

int main(int argc, char const *argv[])
{

	//FastIO;
	//FreOpen;
	int T = 1;
	//cin >> T;
	while (T--) Solve();
	return 0;
}