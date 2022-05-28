/**
 * Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.
 * Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie 
 * j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize 
 * the number of your content children and output the maximum number.
 * @param {number[]} g
 * @param {number[]} s
 * @return {number}
 */

 var findContentChildren = function(g, s) {
    let content = 0;
    g.sort((a,b) => a - b);
    s.sort((a,b) => a - b);

    child = g.length - 1;
    cookie = s.length - 1;


    while (child >= 0 && cookie >=0) {
        if (s[cookie] >= g[child]) {
            content ++;
            cookie--;
        }
        child--;
    }
    
    return content;
};

// test 1
console.log(findContentChildren([10,9,8,7], [5,6,7,8]));

// test 2
console.log(findContentChildren([1, 2, 3], [3]));