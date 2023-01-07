class Solution {
public:
    bool isHappy(int n) {
        map<long long int,long long int> m;
        while(1)
        {
            long long int temp=n;
            long long int sum=0;
            while(n!=0)
            {
                int z=n%10;
                sum=sum+(z*z);
                n=n/10;
            }
            if(sum==1) return true;
            if(m.find(sum)!=m.end()) return false;
            if(m.find(sum)==m.end()) m[sum]=temp;
            n=sum;
        }
        return false;
        
    }
};
