class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);

        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return tasks[a][0] < tasks[b][0] || 
                   (tasks[a][0] == tasks[b][0] && a < b);
        });
        
        auto comp = [&](int a, int b) {
            return tasks[a][1] > tasks[b][1] || 
                   (tasks[a][1] == tasks[b][1] && a > b);
        };
        priority_queue<int, vector<int>, decltype(comp)> minHeap(comp);
        
        vector<int> result;
        long long time = 0;
        int i = 0;
        
        while (!minHeap.empty() || i < n) {
            while (i < n && tasks[indices[i]][0] <= time) {
                minHeap.push(indices[i]);
                i++;
            }
            
            if (minHeap.empty()) {
                time = tasks[indices[i]][0];
            } else {
                int nextIndex = minHeap.top();
                minHeap.pop();
                time += tasks[nextIndex][1];
                result.push_back(nextIndex);
            }
        }
        
        return result;
    }
};