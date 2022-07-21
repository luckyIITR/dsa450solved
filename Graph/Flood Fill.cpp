class Solution
{
public:
    void dfs(vector<vector<int>> &image, int sr, int sc, int color, int source)
    {
        if (sr < 0 or sr >= image.size() or sc < 0 or sc >= image[0].size() or image[sr][sc] != source)
            return;
        image[sr][sc] = color;
        dfs(image, sr - 1, sc, color, source);
        dfs(image, sr, sc + 1, color, source);
        dfs(image, sr + 1, sc, color, source);
        dfs(image, sr, sc - 1, color, source);
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        if (image[sr][sc] == color)
            return image;
        int source = image[sr][sc];
        dfs(image, sr, sc, color, source);
        return image;
    }
};