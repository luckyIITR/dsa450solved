class Solution
{
public:
	bool solve(vector<int> &arr, int start, map<int, bool> &visited)
	{
		if (arr[start] == 0)
			return true;
		visited[start] = true;
		bool ans1 = false, ans2 = false;
		if (arr[start] + start < arr.size() and visited[arr[start] + start] != true)
		{
			ans1 = solve(arr, arr[start] + start, visited);
		}
		if (start - arr[start] >= 0 and visited[start - arr[start]] != true)
		{
			ans2 = solve(arr, start - arr[start], visited);
		}
		return ans1 or ans2;
	}
	bool canReach(vector<int> &arr, int start)
	{
		map<int, bool> visited;
		return solve(arr, start, visited);
	}
};