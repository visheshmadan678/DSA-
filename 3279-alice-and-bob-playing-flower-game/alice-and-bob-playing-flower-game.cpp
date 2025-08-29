class Solution {
public:
    long long flowerGame(int n, int m) {
        long long ro1 = 0,ro2 = 0; //ro1 odd count
        long long re1 = 0,re2 = 0; //ro1 even count

        re1 += n/2; re2 += m/2;
        if(n%2==0){
            ro1 += n/2;
        }
        else{
            ro1 += (n/2 + 1);
        }

        if(m%2==0){
            ro2 += m/2;
        }
        else{
            ro2 += (m/2 + 1);
        }

        return (1LL*ro1 * re2) + (1LL * re1*ro2);

    }
};