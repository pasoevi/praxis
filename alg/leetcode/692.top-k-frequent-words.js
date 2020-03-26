/*
 * @lc app=leetcode id=692 lang=javascript
 *
 * [692] Top K Frequent Words
 *
 * https://leetcode.com/problems/top-k-frequent-words/description/
 *
 * algorithms
 * Medium (49.55%)
 * Likes:    1367
 * Dislikes: 116
 * Total Accepted:    128.5K
 * Total Submissions: 259.2K
 * Testcase Example:  '["i", "love", "leetcode", "i", "love", "coding"]\n2'
 *
 * Given a non-empty list of words, return the k most frequent elements.
 * Your answer should be sorted by frequency from highest to lowest. If two
 * words have the same frequency, then the word with the lower alphabetical
 * order comes first.
 * 
 * Example 1:
 * 
 * Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
 * Output: ["i", "love"]
 * Explanation: "i" and "love" are the two most frequent words.
 * ⁠   Note that "i" comes before "love" due to a lower alphabetical order.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is",
 * "is"], k = 4
 * Output: ["the", "is", "sunny", "day"]
 * Explanation: "the", "is", "sunny" and "day" are the four most frequent
 * words,
 * ⁠   with the number of occurrence being 4, 3, 2 and 1 respectively.
 * 
 * 
 * 
 * Note:
 * 
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Input words contain only lowercase letters.
 * 
 * 
 * 
 * Follow up:
 * 
 * Try to solve it in O(n log k) time and O(n) extra space.
 * 
 * 
 */

// @lc code=start
/**
 * @param {string[]} words
 * @param {number} k
 * @return {string[]}
 */
var topKFrequent = function(words, k) {
    const hist = {};
    for (let word of words) {
        if (hist[word]) {
            hist[word] += 1;
        } else {
            hist[word] = 1;
        }
    }
        
    // Create items array
    var items = Object.keys(hist).map(function(key) {
        return [key, hist[key]];
    });
  
    // Sort the array based on the second element
    items.sort(function(first, second) {
        if (first[1] === second[1]) {
            if(first[0] < second[0]) { return -1; }
            if(first[0] > second[0]) { return 1; }
        }
        return second[1] - first[1];
    });

    const result = [];
    for (let i = 0; i < k; i++) {
        result.push(items[i][0]);
    }
    return result;

};
// @lc code=end

