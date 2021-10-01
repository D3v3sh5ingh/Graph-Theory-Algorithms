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
	#define pll pair< char,ll int>
	#define sz(a) a.size()
	#define inf (1000*1000*1000+5)
	#define all(a) a.begin(),a.end()
	#define tri pair<int,pii>
	#define vii vector<pii>
	#define vll vector<pll>
	#define viii vector<tri>
	#define mod (1000*1000*1000+7)
    #define N 4

int main()
	{
		std::ios::sync_with_stdio(false); cin.tie(NULL);
		ll int t;
		cin>>t;
		while(t--)
		{
            ll n,p;
    cin>>n>>p;

    vector<ll> arr(n);

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    } 


    vector<ll> temp(n,0);
    bool mil=false,done=true;;


    for(int i=0;i<n;i++)
    {
        if(p%arr[i]!=0)
        {

            mil=true;
            ll ans =p/arr[i] +1;
            temp[i]=ans;
            break;
        }
    }

    if(mil&&done)
    {

        cout<<"YES ";
        done=false;

        for(int i=0;i<n;i++)
        {
            cout<<temp[i]<<" ";
        }

        cout<<endl;
    }

    for(int i=0;i<n-1;i++)
    {
        if(arr[i+1]%arr[i]!=0)
        {
            mil=true;
            ll first=p/arr[i]-1;
            ll second =1;

            temp[i]=first;
            temp[i+1]=second;
            break;


        }
    }

    if(mil&&done)
    {

        cout<<"YES ";
        done=false;

        for(int i=0;i<n;i++)
        {
            cout<<temp[i]<<" ";
        }

        cout<<endl;
    }




    if(done)cout<<"NO"<<endl;
           
        }
		return 0;
	}
