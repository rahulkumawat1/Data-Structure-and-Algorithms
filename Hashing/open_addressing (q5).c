#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void inserta(int A[],int i,int m)
{
	int j = 0;
	//int m = (int*)sizeof(A)/sizeof(A[0]);
	int index;
	while(j<m)
	{
		index = (i%m + j)%m;
		if(A[index]==-999)
		{
			A[index] = i;
			break;
		}
		j++;
	}
}

int searcha(int A[],int key,int m)
{
	int index;
	int i=0;
	//int m = (int*)sizeof(A)/sizeof(A[0]);
	while(i<m)
	{
		index = (key%m + i)%m;
		if(A[index]==key)
			return 1;
		i++;
	}
	return 0;
}

void deletea(int A[],int key,int m)
{
	//int m = (int*)sizeof(A)/sizeof(A[0]);
	int i = 0;
	int index;
	while(i<m)
	{
		index = (key%m + i)%m;
		if(A[index]==key)
			{A[index] = -999;
			break;}
		i++;
	}

}

void insertb(int A[],int i,int m,int c1,int c2)
{
	int j = 0;
	//int m = (int*)sizeof(A)/sizeof(A[0]);
	int index;
	while(j<m)
	{
		index = (i%m + c1*j + c2*j*j)%m;
		if(A[index]==-999)
		{
			A[index] = i;
			break;
		}
		j++;
	}
}

int searchb(int A[],int key,int m,int c1,int c2)
{
	int index;
	int i=0;
	//int m = (int*)sizeof(A)/sizeof(A[0]);
	while(i<m)
	{
		index = (key%m + c1*i + c2*i*i)%m;
		if(A[index]==key)
			return 1;
		i++;
	}
	return 0;
}

void deleteb(int A[],int key,int m,int c1,int c2)
{
	//int m = (int*)sizeof(A)/sizeof(A[0]);
	int i = 0;
	int index;
	while(i<m)
	{
		index = (key%m + c1*i + c2*i*i)%m;
		if(A[index]==key)
			{A[index] = -999;
			break;}
		i++;
	}

}

void insertc(int A[],int i,int m,int R)
{
	int j = 0;
	//int m = (int*)sizeof(A)/sizeof(A[0]);
	int index;
	while(j<m)
	{
		index = (i%m + j*(R - i%R))%m;
		if(A[index]==-999)
		{
			A[index] = i;
			break;
		}
		j++;
	}
}

int searchc(int A[],int key,int m,int R)
{
	int index;
	int i=0;
	//int m = (int*)sizeof(A)/sizeof(A[0]);
	while(i<m)
	{
		index = (key%m + i*(R - key%R))%m;
		if(A[index]==key)
			return 1;
		i++;
	}
	return 0;
}

void deletec(int A[],int key,int m,int R)
{
	//int m = (int*)sizeof(A)/sizeof(A[0]);
	int i = 0;
	int index;
	while(i<m)
	{
		index = (key%m + i*(R - key%R))%m;
		if(A[index]==key)
			{A[index] = -999;
			break;}
		i++;
	}

}

void print(int A[],int m)
{
	//int m = (int*)sizeof(A)/sizeof(A[0]);
	int i = 0;
	while(i<m)
	{
		if(A[i]==-999)
			printf("%d ()\n",i);
		else
			printf("%d (%d)\n",i,A[i]);
		i++;
	}
}

int isprime(int n)
{
	int i;
	int k = sqrt(n);
	for(i=2;i<=k;i++)
	{
		if(n%i==0)
			return 0;
	}
	return 1;
}

int prime(int n)
{
	while(n--)
	{
		if(n==0)
		{
			printf("-999\n");
			exit(0);
		}
		if(n%2==0)
			continue;
		else
		{
			if(isprime(n))
				return n;
		}
	
	}
}

int main()
{
	char c,ch;
	int c1,c2,R;
	scanf("%c",&c);
	int n,i;
	scanf("%d",&n);
	int A[n];
	R = prime(n);
	for(i=0;i<n;i++)
		A[i] = -999;
	if(c=='a')
	{
		while(1)
		{
			scanf("%c",&ch);
			switch(ch)
			{
				case 'i': scanf("%d",&i); inserta(A,i,n);break;
				case 'p': print(A,n);break;
				case 's': scanf("%d",&i) ;
					  if(searcha(A,i,n))
						  printf("1\n");
					  else printf("-1\n"); break;
				case 'd': scanf("%d",&i); deletea(A,i,n);break;
				case 'T': return 0;
			}
		}	
	}
	else if(c=='b')
	{
		scanf("%d %d",&c1,&c2);
		while(1)
		{
			scanf("%c",&ch);
			switch(ch)
			{
				case 'i': scanf("%d",&i); insertb(A,i,n,c1,c2);break;
				case 'p': print(A,n);break;
				case 's': scanf("%d",&i) ;
					  if(searchb(A,i,n,c1,c2))
						  printf("1\n");
					  else printf("-1\n"); break;
				case 'd': scanf("%d",&i); deleteb(A,i,n,c1,c2);break;
				case 'T': return 0;
			}
		}	

	}
	else if(c=='c')
	{
		while(1)
		{
			scanf("%c",&ch);
			switch(ch)
			{
				case 'i': scanf("%d",&i); insertc(A,i,n,R);break;
				case 'p': print(A,n);break;
				case 's': scanf("%d",&i) ;
					  if(searchc(A,i,n,R))
						  printf("1\n");
					  else printf("-1\n"); break;
				case 'd': scanf("%d",&i); deletec(A,i,n,R);break;
				case 'T': return 0;
			}
		}	

	}
}
