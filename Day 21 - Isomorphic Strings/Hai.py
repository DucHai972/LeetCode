class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        dict_ = {}
        for i in range (len(s)):
            if s[i] in dict_:
                if t[i] != dict_[s[i]]:
                    return False
            else:
                if t[i] in dict_.values():
                    return False
                dict_[s[i]] = t[i]

        return True
