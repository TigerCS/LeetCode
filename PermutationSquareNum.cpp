bool isSquareNum(int n)
{
	int x = sqrt(n);
	return x*x==n;
}

string itos(int i)
{
	string res;
	while(i>0) {
		res.insert(res.begin(), i%10+'0');
		i /=10;
	}
	return res;
}

void PermutationSquareNumRe(int n, vector<bool> &used, int last, int num, string cur, vector<string> &res) 
{
	if(num==n) {
		res.push_back(cur);
		return;
	}
	num++;
	for(int i=1; i<=n; ++i) {
		if(used[i-1]) continue;
		if(last==-1 || !isSquareNum(last+i))
			continue;
		used[i-1]=true;
		PermutationSquareNumRe(n, used, i, num, cur+itos(i), res);
		used[i-1]=false;
	}
}

vector<string> PermutationSquareNum(int n) 
{
	vector<string> res;
	vector<bool> used(n, false);
	PermutationSquareNumRe(n, used, -1, 0, "", res);
	if(res.empty())
		res.push_back("");
	return res;
}
