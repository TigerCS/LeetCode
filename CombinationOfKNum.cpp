vector<vector<int> > curbine(int n, int k) 
{
    vector<vector<int> > res;
    vector<int> cur;
    curbineRe(n, k, 1, cur, res);
    return res;
}
 
void curbineRe(int n, int k, int start, vector<int> &cur, vector<vector<int> > &res)
{
    int m = cur.size();
    if (m == k) {
        res.push_back(cur);
        return;
    }
    for (int i = start; i <= n-(k-m)+1; ++i) {
        cur.push_back(i);
        curbineRe(n, k, i+1, cur, res);
        cur.pop_back();
    }
}
