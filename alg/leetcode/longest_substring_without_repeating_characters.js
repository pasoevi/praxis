function lengthOfLongestSubstring(s) {
    const lengths = [];
    const currentSubstrs = [];
    let longestSubstr = "";
    let lastSubstr = "";
    for (let c of s) {
        if (lastSubstr.includes(c)) {
            lastSubstr = c;
        } else {
            lastSubstr += c;
            if (lastSubstr.length > longestSubstr.length) {
                longestSubstr = lastSubstr;
            }
        }
    }
    return longestSubstr.length;
}
/*
console.log(lengthOfLongestSubstring("abcabcbb") === 3);
console.log(lengthOfLongestSubstring("bbbbb") === 1);
console.log(lengthOfLongestSubstring("pwwkew") === 3);
*/
console.log(lengthOfLongestSubstring("dvdf") === 3);
