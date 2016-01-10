//
#include<iostream>
using namespace std;

int count;
int call(int (*m)[3],int i,int j,int (*l)[3]);

int main()
{
int i,j;
int m[3][3]={{1,2,3},{4,5,6},{7,8,9}};
int l[3][3];

for(i=0;i<3;i++)
{
  for(j=0;j<3;j++)
  {
    l[i][j]=0;
  }
}

for(i=0;i<3;i++)
{
  for(j=0;j<3;j++)
  {
    count=1;
    l[i][j]=call(m,i,j,l);
  }
}
int maxim=-1;
for(i=0;i<3;i++)
{
  for(j=0;j<3;j++)
  {
    if(l[i][j]>maxim) maxim=l[i][j];
  }
}
cout<<maxim;

}

int call(int (*m)[3],int i,int j,int (*l)[3])
{
  if(l[i][j]!=0) return l[i][j];
  else
  {
    if(m[i-1][j]==m[i][j]+1)
    {
      count=1+call(m,i-1,j,l);
    }
    else if(m[i+1][j]==m[i][j]+1)
    {
      count=1+call(m,i+1,j,l);
    }
    else if(m[i][j-1]==m[i][j]+1)
    {
      count=1+call(m,i,j-1,l);
    }
    else if(m[i][j+1]==m[i][j]+1)
    {
      count=1+call(m,i,j+1,l);
    }
    else return count;
  }
  return count;
}
