vector<vector<int> > combine(int n, int k) 
{
    vector<vector<int> > res;
    vector<int> cur;
    combineHelper(n, k, 1, cur, res);
    return res;
}
 
void combineHelper(int n, int k, int start, vector<int> &cur, vector<vector<int> > &res)
{
    int m = cur.size();
    if (m == k) {
        res.push_back(cur);
        return;
    }
    for (int i = start; i <= n-(k-m)+1; ++i) {
        cur.push_back(i);
        combineHelper(n, k, i+1, cur, res);
        cur.pop_back();
    }
}
