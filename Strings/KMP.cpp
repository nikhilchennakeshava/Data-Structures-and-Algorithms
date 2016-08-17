#include <bits/stdc++.h>

using namespace std;
int lps[100];  // longest prefix suffix array

void findLPS(string pattern)
{
	int j = 0;
	int i = 1;
	int n = pattern.length();

	for(int k=0;k<n;k++)
        lps[k]=0;

	while(i<n)
	{
		if(pattern[j] == pattern[i])
		{
			lps[i] = j+1;
			j++;
			i++;
		}
		else
		{
			if(j!=0)
			{
				j = lps[j-1];
			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

int KMP(string text,string pattern)
{
	int i = 0;
	int j = 0;
	int n = text.length();
	int m = pattern.length();

	while(i<n && j<m)
	{
		if(text[i] == pattern[j])
		{
			i++;
			j++;
		}
		else
		{
			if(j!=0)
				j = lps[j-1];
			else
				i++;
		}
		if(j==m)
			return (i-m);

	}
	return -1;
}
int main()
{
	string text,pattern;
	//cin>>text>>pattern;
	fflush(stdin);
	getline(cin,text);
	fflush(stdin);
	getline(cin,pattern);

    findLPS(pattern);

    int pos = KMP(text,pattern);

    if(pos!=-1)
        cout<<"\nPattern found at :"<<pos+1<<endl;
    else
        cout<<"\nPattern not found\n";
        
    return 0;
}

