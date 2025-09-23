class Solution {
public:
    pair<vector<string>,vector<string>> compare(string &str1, string &str2){
        vector<string>nums1;vector<string>nums2;
        stringstream obj1(str1); stringstream obj2(str2);
        string temp1,temp2;
        while(getline(obj1,temp1,'.')){
            if(temp1.size()==1){nums1.push_back(temp1);continue;}
            int k = 0;
            while(k<temp1.size()){
                if(temp1[k]=='0')k++;
                else break;
            }
            if(k!=temp1.size())nums1.push_back(temp1.substr(k,temp1.size()-k));
            else nums1.push_back("0");

        }
        while(getline(obj2,temp2,'.')){
            if(temp2.size()==1){nums2.push_back(temp2);continue;}
            int k = 0;
            while(k<temp2.size()){
                if(temp2[k]=='0')k++;
                else break;
            }
            if(k!=temp2.size())nums2.push_back(temp2.substr(k,temp2.size()-k));
            else nums2.push_back("0");
        }        
        if(nums1.size()>nums2.size()){
            while(nums1.size()!=nums2.size())nums2.push_back("0");
        }
        else if(nums2.size()>nums1.size()){
            while(nums1.size()!=nums2.size())nums1.push_back("0");
        }
        return {nums1,nums2};
    }
    int compareVersion(string version1, string version2) {
        int cnt1 = 0;
        int cnt2 = 0;
        for(auto &it:version1)if(it=='.')cnt1++; // increase the versions in string one 
        for(auto &it:version2)if(it=='.')cnt2++; // increase the count of versions in string two 

        pair<vector<string>,vector<string>>p = compare(version1,version2);
        vector<string>a = p.first;
        vector<string>b = p.second;
        //so all i care about is the smaller vector size 

        int size = a.size();

        for(int i=0;i<size;i++){
            string str1 = a[i];
            string str2 = b[i];
            if(str1 == str2)continue;
            // if(str1.length()!=str2.length()){
            //     cout<<"i m";
            //     if(str1.length()<str2.length()){
            //         while(str1.length()!=str2.length()){
            //             str1.push_back('0');
            //         }
            //         cout<<str1<<" "<<str2<<endl;
            //         if(str1 == str2)continue;
            //         return stoi(str1)<stoi(str2)?-1:1;
            //     }
            //     else{
            //         while(str1.length()!=str2.length()){
            //             str2.push_back('0');
            //         }
            //         if(str1 == str2)continue;
            //         return stoi(str1)<stoi(str2)?-1:1;                    
            //     }
            // }
            
            else return stoi(str1)<stoi(str2)?-1:1;

            
        }

        return 0;
    }
};