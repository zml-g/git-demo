#include <iostream>
using namespace std;
 void su1(int n)
 {
 	int sum=1;
 	for(int i=1;i<=n;i++)
 	{
 		int j=2;
 		while(i%j!=0)
 		{
 			j++;
 			if(j>=i)
 			{
 				sum+=1;
 				break;
			 }
		 }
	 }
	 cout<<"��������Ϊ"<<sum<<"��"<<endl; 
 }
 
 void su2(int n)//ŷ��ɸѡ 
 {
 	int prime[100];//������
	 int no_prime[100]={0};
	 int sum=0;
	 int i,j;
	 for(i=2;i<n;i++)
	 {
	 	if(!no_prime[i])
	 	prime[sum++]=i;
		 for(j=0;j<sum&&i*prime[j]<n;j++)
		 {
		 	no_prime[i*prime[j]]=1;
		 	if(i%prime[j]==0)
		 	break;
		  } 
	 }
 	
 	cout<<"1��n����"<<sum<<"������"<<endl; 
 }
 
 
 int main()
 {
 	int n;
	cout<<"����nֵ:"<<endl; 
 	cin>>n;
 	su1(n); //���Ӷ� n(n+1)/2
	 su2(n); 
 }
