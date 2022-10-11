class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        int n = arr.size();
        map<int, bool> visited;
        map<int, bool> inque; // to check whether node already in que
        map<int, int> distance;
        distance[0] = 0;
        map<int, vector<int>> map_values;
        for (int i = 0; i < n; i++)
        {
            map_values[arr[i]].push_back(i);
        }

        queue<int> que; // push indexes
        que.push(0);
        while (!que.empty())
        {
            int idx = que.front();
            que.pop();
            visited[idx] = true;

            if (idx == n - 1)
                return distance[idx];
            // idx + 1, idx - 1, map_values;
            //           only push valid indexes
            if (idx + 1 < n and visited[idx + 1] == false and inque[idx + 1] == false)
            {
                distance[idx + 1] = distance[idx] + 1;
                inque[idx + 1] = true;
                que.push(idx + 1);
            }

            if (idx - 1 >= 0 and visited[idx - 1] == false and inque[idx - 1] == false)
            {
                distance[idx - 1] = distance[idx] + 1;
                inque[idx - 1] = true;
                que.push(idx - 1);
            }

            //             map checking
            int map_size = map_values[arr[idx]].size();

            for (int i = map_size - 1; i >= 0; i--)
            {
                int check_idx = map_values[arr[idx]][i];
                if (visited[check_idx] == false and inque[check_idx] == false)
                {
                    distance[check_idx] = distance[idx] + 1;
                    inque[check_idx] = true;
                    que.push(check_idx);
                }
            }
            // once you have traversed the map then delete it otherwise it will check again and again although it won't add anything but it will check
            map_values.erase(arr[idx]);
        }
        return 0;
    }
};