#include<bits/stdc++.h>
using namespace std;

const int MAX_CHAR = 256;

class SuffixTrieNode{
private:
    SuffixTrieNode *children[MAX_CHAR];
    list<int> *indexes;
public:
    SuffixTrieNode()
    {
        for(int i=0;i<MAX_CHAR;i++)
            children[i] = NULL;
            indexes = new list<int>;
    }
    void insert(string,int);
    list<int> *search(string);
};

void SuffixTrieNode::insert(string s,int index)
{
    if(s.length()==0)
    {
        return;
    }
    if(children[s[0]]==NULL)
    {
        children[s[0]] = new SuffixTrieNode();
    }
    children[s[0]]->indexes->push_back(index);
    children[s[0]]->insert(s.substr(1),index+1);
}

list<int>* SuffixTrieNode::search(string s)
{
    if(s.length()==0)
    {
        return indexes;
    }
    if(children[s[0]]==NULL)
    {
        return NULL;
    }
    return children[s[0]]->search(s.substr(1));
}

class SuffixTrie{
private:
    SuffixTrieNode root;
public:
    SuffixTrie(string key){
        int n = key.length();
        for(int i=0;i<n;i++)
        {
            root.insert(key.substr(i,n-i),i+1);
        }
    }
    void search(string s)
    {
        list<int>*res = root.search(s);
        if(res==NULL)
        {
            cout<<"Not Found\n";
        }
        else{
            cout<<"Find at ";
            int n = s.length();
            for(list<int>::iterator i=res->begin();i!=res->end();i++)
            {
                cout<<*i-n<<" ";
            }
            cout<<"\n";
        }
    }
};

int main()
{
    string s;
    cin>>s;
    SuffixTrie S(s);
    cin>>s;
    S.search(s);
}
