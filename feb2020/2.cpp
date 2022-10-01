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
            ll int n,k;
            cin>>n>>k;
            ll int sum=0;
            // vector<int> a;
            for(ll int i=0;i<n;i++){
                ll int q;
                cin>>q;
                sum+=q;
            }
            cout<<sum%k<<endl;
            
        }
		return 0;
	}

	// int main()
	// {
	// 	std::ios::sync_with_stdio(false); cin.tie(NULL);
	// 	ll int t;
	// 	cin>>t;
	// 	while(t--)
	// 	{
    //         ll int n,k;
    //         cin>>n>>k;
            
    //         vector<int> a;
    //         for(ll int i=0;i<n;i++){
    //             ll int q;
    //             cin>>q;
    //             a.push_back(q);
    //         }
    //         ll int r,l;
    //         r=n-1;
    //         l=0;
    //         ll int lsum,rsum;
    //         lsum=rsum=0; 
    //         while(l<=r)
    //         {
    //             if(lsum<=rsum){
    //                 lsum+=a[l]%k;
    //                 l++;
    //             }
    //             else{
    //                 rsum+=(k-a[r]%k);
    //                 r--;
    //             }
    //             // cout<<"L "<<l<<" R "<<r<<endl;
    //             // cout<<"LSum "<<lsum<<" Rsum "<<rsum<<endl;
    //         }
    //         while(lsum<rsum){
    //                 lsum+=a[l]%k;
    //                 l++;
    //                 rsum-=(k-a[r]%k);
    //                 r--;
    //         }
    //     cout<<lsum-rsum<<endl;

    //     }
	// 	return 0;
	// }
