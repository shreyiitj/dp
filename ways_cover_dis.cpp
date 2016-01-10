//
#include<iostream>
using namespace std;

int ways(int n);
int waysUtil(int n,int *dis);

int main()
{
int n;
cin>>n;
int w=ways(n);
cout<<w;
}

int ways(int n)
{
 int *dis=new int[n];
 dis[0]=1;
 dis[1]=1;
 dis[2]=2;
 for(int i=3;i<=n;i++)
 {
   dis[i]=0;
 }
 int w=waysUtil(n,dis);
 return w;
}

int waysUtil(int n,int *dis)
{
  if(dis[n]!=0) return dis[n];
  else
  {
   dis[n]=waysUtil(n-1,dis)+waysUtil(n-2,dis)+waysUtil(n-3,dis);
   return dis[n];
  }
}
