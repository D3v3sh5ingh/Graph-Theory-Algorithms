#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli za=100001;


vector <lli> sequ(za+1,0);

void seqfunc(lli N) {
	vector<lli> a(za+1,0);
	lli i,t,j,k,n,r=1,s=1,c=0;
	for(i=0;i<za+1;i++)
	    a[i]=i;
	for(j=2;j<=za;j++)
	{   if(a[j]==j)
	   {
		for(k=j*j;k<=za;k+=j)
		 {  if(a[k]==k)
			a[k]=j;
		 }
	   }
	}
    for(i=1;i<=N;i++)
        {   r=1,s=1;
            c=0;
            n=i;
            while(n>0)
            {
                if(r==a[n])
                {
                    c++;
                    if(n==1)
                    break;

                }
                else
                {
                    if(c%2==1)
                    s=s*r;
                    c=1;
                    r=a[n];
                    if(n==1)
                    break;
                }
                n=n/a[n];

            }
            sequ[i]=s;
        }

}

int main()
{   
    double z;
	lli t,i,n,za,j,c,d,h,v,maxx,maxy,co,k;
	cin>>t;
    for(i=0;i<t;i++)
	{   c=d=h=v=co=maxx=maxy=0;
	    vector <lli> w(4,0), g(4,0);
		cin>>n>>za;
		vector <lli> X(n,0),Y(za,0);
		for(j=0;j<n;j++)
		{
			scanf("%lld",&X[j]);
			if(X[j]>0)
			{
				c++;
				if(X[j]>maxx)
				maxx=X[j];
			}
			else if(X[j]<0)
			{
				d++;
				if((X[j]*-1)>maxy)
				maxy=(X[j]*-1);
			}
			else
			{
				co=co+(n-1)*za;
			}
		}
		w[0]=maxx;		w[1]=maxy;		g[0]=maxx;		g[1]=maxy;
		vector <lli> xp(c,0),xp1(maxx+1,0),xn(d,0),xn1(maxy+1,0);
		for(j=0;j<n;j++)
		{
			if(X[j]>0)
			{
				xp1[X[j]]=1;
				xp[h]=X[j];
				h++;
			}
			if(X[j]<0)
			{
				xn1[(X[j]*-1)]=1;
				xn[v]=X[j]*-1;
				v++;
			}
		}
		c=0,d=0,h=0,v=0,maxx=0,maxy=0;
		for(j=0;j<za;j++)
		{
			scanf("%lld",&Y[j]);
			if(Y[j]>0)
			{
				c++;
				if(Y[j]>maxx)
				maxx=Y[j];
			}
		    else if(Y[j]<0)
			{
				d++;
				if((Y[j]*-1)>maxy)
				maxy=(Y[j]*-1);
			}
			else
			co=co+(za-1)*n;
		}
		w[2]=maxx;		w[3]=maxy;		g[2]=maxx;		g[3]=maxy;
		sort(w.begin(),w.end());
		seqfunc(w[3]);
		vector<lli> yp1(maxx+1,0),yn1(maxy+1),yp(c,0),yn(d,0);
		for(j=0;j<za;j++)
		{
			if(Y[j]>0)
			{
				yp1[Y[j]]=1;
				yp[h]=Y[j];
				h++;
			}
			else if(Y[j]<0)
			{
				yn1[(Y[j]*-1)]=1;
				yn[v]=Y[j]*-1;
				v++;
			}
		}
		for(j=0;j<xn.size();j++)
		{   
			for(k=sequ[xn[j]];k<=g[0];k+=sequ[xn[j]])
			{   if(xp1[k]==1)
				{
					z=sqrt(k*xn[j]);
					if(z==floor(z))
					{       if(z<=yp1.size())
						{
						if(yp1[z]==1 )
		 				co++;
		 			    }
		 			    if(z<=yn1.size())
						{
						if(yn1[z]==1 )
						co++;
					    }
					}
				}
			}

	}
		for(j=0;j<yn.size();j++)
		{  
					for(k=sequ[yn[j]];k<=g[2];k+=sequ[yn[j]])
			{
				if(yp1[k]==1)
				{
					z=sqrt(k*yn[j]);
					if(z==floor(z))
						if(z<=xp1.size())
						{
						if(xp1[z]==1)
						co++;
					    }
					    if(z<=xn1.size())
					    {
						if(xn1[z]==1 )
						co++;
					    }
					}
				}
			}

	
		cout<<co<<endl;
	}
	return 0;
}

