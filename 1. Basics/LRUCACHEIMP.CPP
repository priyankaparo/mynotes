

int N;
list<int> q;
map<int,int> mp;
LRUCache::LRUCache(int n)
{
    N=n;
    mp.clear();
    q.clear();
}

void LRUCache::set(int x, int y)
{
    if(mp.find(x)==mp.end())
    {
        if(mp.size()==N)
        {
            int last=q.back();
            q.pop_back();
            mp.erase(last);
            q.push_front(x);
            mp[x]=y;
            
        }
        else
        {
            q.push_front(x);
            mp[x]=y;
        }
    }
    else
    {
        q.remove(x);
        q.push_front(x);
        mp.find(x)->second=y;
    }
    

}

int LRUCache::get(int x)
{
    if(mp.find(x)==mp.end())
    return -1;
    else
    {
        q.remove(x);
        q.push_front(x);
        return mp[x];
        
    }

    

}



