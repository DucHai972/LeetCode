class Solution {
public:
    long long countSubarrays(vector<int>& a, int minK, int maxK) {
        int n = a.size();
        int lastSub=-1,lastMax=-1,lastMin=-1;
        long long res = 0;
        for(int i=0;i<n;i++) {
            if(a[i] < minK || a[i] > maxK) lastSub = i;
            if(a[i]==minK) lastMin=i;
            if(a[i]==maxK) lastMax=i;
            res+=max(0,min(lastMax,lastMin) - lastSub);
        }
        return res;
    }
    // old, plain thinking, original way
    // long long countSubarrays(vector<int>& a, int minK, int maxK) {
    //     // nrMin[i] = nearest index of minK, reset when pass through a outbound value
    //     vector<int> nrMin;
    //     int n=a.size(),pre=-1;
    //     for(int i=0;i<a.size();i++)
    //         if(a[i] < minK || a[i] > maxK) {
    //             nrMin.push_back(-1);
    //             pre=-1;
    //         } else 
    //             if(a[i]==minK) {
    //                 nrMin.push_back(i);
    //                 pre=i;
    //             } else nrMin.push_back(pre);

    //     int lastSub=-1,lastMax=-1;
    //     long long res = 0;
    //     for(int i=0;i<n;i++) {
    //         if(a[i] < minK || a[i] > maxK) {
    //             lastSub=i;
    //             lastMax=-1;
    //             continue;
    //         }
    //         if(a[i]==maxK) 
    //             lastMax=i;
    //         if(lastMax!=-1 && min(nrMin[i],lastMax) > lastSub) 
    //             res+=min(nrMin[i],lastMax)-lastSub;
    //     }   
    //     return res;
    // }
};