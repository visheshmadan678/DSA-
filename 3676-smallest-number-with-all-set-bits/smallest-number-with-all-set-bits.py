class Solution:
    #code by vishu badmos
    def smallestNumber(self, n: int) -> int:
        temp =  1
        i = 1
        while(temp < n):
            temp += pow(2,i)
            i += 1
        return temp
        