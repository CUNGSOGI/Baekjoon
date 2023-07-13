#include <stdio.h>

int main()
{
	int i,j,n,p1[100]={},p2,c=0;
	scanf("%d",&n);
	while(1)
	{
		p1[c]=n;
		p2=(n%10)*10+(((n/10)+(n%10)))%10;
		n=p2;
		c++;
		for(j=0;j<=i;j++)
		{
			if(p1[j]==n)
				break;
		}
			if(p1[j]==n)
				break;
	}
	printf("%d",c);
}