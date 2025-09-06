class Solution {
public:
    set<string>vec;
    //code by vishu badmos
    //badmosi nahi mitar
    void recursion(string &tiles,vector<int>&visited,string str){
        if(!str.empty()){
            vec.insert(str);
            if(str.size()==tiles.size())return;
        }
        for(int i=0;i<tiles.size();i++){
            if(!visited[i]){
                visited[i] = 1;
                recursion(tiles,visited,str+tiles[i]);
                visited[i] = 0;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        vector<int>visited(tiles.size(),0);
        recursion(tiles,visited,"");
        return vec.size();
    }
};