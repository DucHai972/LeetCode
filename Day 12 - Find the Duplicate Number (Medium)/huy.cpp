// Floyd's turtoise and hare in detecting cycle
// idea from https://youtu.be/pKO9UjSeLew
// Verticies are 0-indexed
// Think the number array as graph, a[i] = x means edge(i,x)
// Found a circle = There's a duplicate number i.e there's more than 1 edge 
// pointing to an vertex (more than one i that a[i] = x)
// The duplicated number will be the begining of the cycle
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        while(1) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast) break;
        }
        int i = 0;
        int j = slow;
        while(i!=j)
            i = nums[i],
            j = nums[j];
        return i;
    }
};