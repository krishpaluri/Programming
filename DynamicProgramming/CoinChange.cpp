// Question :
// Total number of ways to form change for particular number with coins available
// coins : {1,2,3} n = 4  number of ways = 4 (3,1) (2,1,1) {2,2} {1,1,1,1}
//



//Solution Description :
//Simple recurion with solution that has coin i and doesnt have coin i
// Ex : getWays(sum,coins-1) + getWays(sum-c[i],coins);


struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

long getWaysHelper(int n,vector<long> &c,int m,unordered_map<pair<long,long>, long,hash_pair> &umap)
{
    pair<int,int> p;
    p.first = n;
    p.second = m;
    if(umap[p] != 0)
    {
        return umap[p];
    }
    if(m < 0)
      return -1;
    if(n < 0)
      return -1;
    if(n == 0)
      return 1;
    pair<int,int> p1,p2;
    p1 = make_pair(n-c[m],m);
    p2 = make_pair(n,m-1);
    umap[p1] = getWaysHelper(n-c[m],c,m,umap);
    umap[p2] = getWaysHelper(n,c,m-1,umap);
    if(umap[p1] >= 0 && umap[p2] >= 0)
       return (umap[p1] + umap[p2]);
    if(umap[p1] >= 0 && umap[p2] < 0)
       return umap[p1];
    if(umap[p1] < 0 && umap[p2] >= 0)
    {
        return umap[p2];
    }
    return 0;
}

long getWays(int n, vector<long> c) {
    unordered_map<pair<long,long>, long,hash_pair> umap;
    return getWaysHelper(n,c,c.size()-1,umap);
}
