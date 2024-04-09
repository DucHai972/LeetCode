class Solution:
    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        count = 0
        for i in range (k):
            if  tickets[i] > tickets[k]:
                count += tickets[k]
            else:
                count += tickets[i]
        
        for i in range(k+1, len(tickets)):
            if tickets[i] >= tickets[k]:
                count += tickets[k] - 1
            else:
                count += tickets[i]
        
        return count + tickets[k]
