class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        int maxSum = 0;
        int n = piles.size();

        for(int i = 0; i < n; i++){
            pq.push(piles[i]);
            maxSum += piles[i];
        }

        for(int i = 0; i < k; i++){
            int maxEle = pq.top();
            pq.pop();
            int remove = maxEle / 2;
            maxEle -= remove;
            pq.push(maxEle);
            maxSum -= remove;
        }

        return maxSum;
    }
};