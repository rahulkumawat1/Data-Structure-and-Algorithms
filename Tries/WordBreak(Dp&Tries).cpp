#include<bits/stdc++.h>
using namespace std;

const int Alphabet_size = 26;

typedef struct trie
{
    struct trie *children[26];
    bool EndOfWord;
}trie;

trie *getnode()
{
    trie* node = new trie;
    node->EndOfWord = false;
    for(int i=0;i<Alphabet_size;i++)
        node->children[i] = NULL;
    return node;
}

void insert(trie *root,string s)
{
    trie* temp = root;
    int n = s.length();
    for(int i=0;i<n;i++)
    {
        int index = s[i]-'a';
        if(!temp->children[index])
        {
            temp->children[index] = getnode();
        }
        temp = temp->children[index];
    }
    temp->EndOfWord = true;
}

bool search(trie* root,string s)
{
    int n = s.length();
    trie *temp = root;
    for(int i=0;i<n;i++)
    {
        int index = s[i]-'a';
        if(!temp->children[index])
            return false;
        temp = temp->children[index];
    }
    return temp->EndOfWord;
}

bool wordBreak(string s,trie *root)
{
    int n = s.length();
    bool dp[n+1];
    for(int i=0;i<=n;i++) dp[i]=false;
    dp[0] = true;
    for(int len=1;len<=n;len++)
    {
        for(int i=0;i<len;i++)
        {
            if(dp[i]&&search(root,s.substr(i,len-i)))
               {
                   dp[len]=true;
                   break;
               }
        }
    }
    return dp[n];
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        trie *root = getnode();
        string s;
        while(n--)
        {
            cin>>s;
            insert(root,s);
        }
        cin>>s;
        cout<<wordBreak(s,root)<<endl;
    }
}
