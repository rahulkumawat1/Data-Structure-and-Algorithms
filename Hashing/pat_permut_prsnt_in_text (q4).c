#include<stdio.h>
#include<string.h>

int ch(int a[],int b[])
{
	for(int i=0;i<26;i++)
	{
		if(a[i]!=b[i])
			return 0;
	}
	return 1;
}

int check(char pat[],char text[])
{
	int i;
	int m = strlen(pat);
	int n = strlen(text);
	int pattern[26] = {0};
	int tex[26] = {0};
	if(m>n)
		return 0;
	for(i=0;i<m;i++)  
	{
		pattern[pat[i]-'a']++;
		tex[text[i]-'a']++;	
	}
	for(i=0;i<=n-m;i++)
	{
		if(ch(pattern,tex))
			return 1;	
		tex[text[i]-'a']--;
		tex[text[i+m]-'a']++;
	}
	return 0;
}

int main()
{
	char pattern[1000];
	char text[100000];
	int n;
	scanf("%d",&n);
	while(n--)
	{
	scanf("%s",pattern);
        scanf("%s",text);
	int x = check(pattern,text);
	if(x)
		printf("YES\n");
	else
		printf("NO\n");
	}
}
