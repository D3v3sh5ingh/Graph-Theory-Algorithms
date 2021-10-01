	#include <bits/stdc++.h>

	using namespace std;

	#define f(i,a,b) for(int i=a;i<b;i++)
	#define rep(i,n) f(i,0,n)
	#define fd(i,a,b) for(int i=a;i>=b;i--)
	#define pb push_back
	#define mp make_pair
	#define vi vector< int >
	#define vl vector< ll >
	#define ss second
	#define ff first
	#define ll long long
	#define pii pair< int,int >
	#define pll pair< ll,ll >
	#define sz(a) a.size()
	#define inf (1000*1000*1000+5)
	#define all(a) a.begin(),a.end()
	#define tri pair<int,pii>
	#define vii vector<pii>
	#define vll vector<pll>
	#define viii vector<tri>
	#define mod (1000*1000*1000+7)

    
	int main()
	{
		std::ios::sync_with_stdio(false); cin.tie(NULL);
		ll int t;
		cin>>t;
		while(t--)
		{
            ll int n;
            cin>>n;
            vector<int> a,b;
            for(ll int i=0;i<n;i++){
                ll int q;
                cin>>q;
                a.push_back(q);
            }
            for(ll int i=0;i<n;i++){
                ll int w;
                cin>>w;
                b.push_back(w);
            }
            sort(a.begin(),a.end());
            sort(b.begin(),b.end());
            ll int res=0;
            for(ll int i=0;i<n;i++){
                res+=min(a[i],b[i]);
            }
            cout<<res<<endl;
        }
		return 0;
	}
