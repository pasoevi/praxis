
/**
 * @param {string[]} strs
 * @return {string[][]}
 */


/* function isAnagram(a, b) {
    const aSorted = a.split("").sort().join("");
    const bSorted = b.split("").sort().join("");
    return aSorted === bSorted;
}
 */
function getAnagramKey(str) {
    return str.split("").sort().join("");
}

var groupAnagrams = function(strs) {
    if (strs.length === 1 ) {
        return [strs];
    }
    const groups = {};
    for (let item of strs) {
        const itemKey = getAnagramKey(item);
        if (groups[itemKey] === undefined) {
            groups[itemKey] = [item];
        } else {
            groups[itemKey].push(item);
        }
    }
    return Object.entries(groups).map((x) => x[1]);
};

console.log(groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"]));


/*
Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
*/