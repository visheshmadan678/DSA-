/**
 * @param {string} num
 * @return {string}
 */
var largestGoodInteger = function(num) {
    //so i have a string function 
    let str = new String(num); // take the string in other 
    let size = str.length // this will store the size our string
    let ans = "";
    for(let i=0;i<=size-3;i++){
        let temp = str.substr(i,3);
        console.log(temp); // store the three characters in the temp 
        if(temp[0]==temp[1] && temp[0]==temp[2]){
            if(temp>ans){
                ans = temp;
            }
        }
    }
    return ans;
};