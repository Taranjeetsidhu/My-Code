#include <iostream>
using namespace std;

main()
{
int j;
cout<<"Enter Any Number: \n";
cin>>j;
for (int i=1;i<=j;i++)
{
for (int k=1;k<=j;k++)
{
cout<<" ";
}
for (int x=1;x<=i;x++)
{
cout<<"*";
cout<<" ";

}
cout<<"\n";
j--;
}
return 0;
}

