/*
http://oj.leetcode.com/problems/candy/

 There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

    Each child must have at least one candy.
    Children with a higher rating get more candies than their neighbors.

What is the minimum candies you must give? 

Solution: O(n) & O(1)
*/

class Solution {
public:
    int candy(vector<int> &ratings) {
        if(ratings.size()<=0) return 0;
        
        int maxValue = 1;
        int maxIndex = 0;
        int candy = 1;
        int res = 1;
        for(int i=1; i<ratings.size(); i++) {
            if(ratings[i]>=ratings[i-1]) {
                candy = (ratings[i]==ratings[i-1])?1:candy+1;
                maxValue = candy;
                maxIndex = i;
            }
            else {
                if(candy==1) {
                    if(maxValue>i-maxIndex)
                        res += i-maxIndex-1;
                    else {
                        res += i-maxIndex;
                        maxValue++;
                    }
                }
                candy = 1;
            }
            res += candy;
        }
        return res;
    }    
};
