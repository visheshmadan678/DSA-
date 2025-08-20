/**
 * @param {string} s1
 * @param {string} s2
 * @param {string} s3
 * @return {boolean}
 */
//code by vishu badmos
let s11, s22, s33;
let dp;

function recursion(idx1, idx2) {
    if (idx1 >= s11.length && idx2 >= s22.length && idx1 + idx2 >= s33.length) {
        return true;
    }

    if (dp[idx1][idx2] !== -1) return dp[idx1][idx2];

    let result = false;

    if (idx1 < s11.length && s11[idx1] === s33[idx1 + idx2]) {
        result = recursion(idx1 + 1, idx2);
    }

    if (!result && idx2 < s22.length && s22[idx2] === s33[idx1 + idx2]) {
        result = recursion(idx1, idx2 + 1);
    }

    return dp[idx1][idx2] = result;
}

var isInterleave = function(s1, s2, s3) {
    if (s1.length + s2.length !== s3.length) return false;

    s11 = s1;
    s22 = s2;
    s33 = s3;

    // initialize dp with -1
    dp = Array.from({ length: s1.length + 1 }, () => Array(s2.length + 1).fill(-1));

    return recursion(0, 0);
};
