/**
 * Initialize your data structure here.
 */
var Trie = function (value, isCompleteWord) {
    this.value = value !== undefined ? value : null;
    this.isCompleteWord = isCompleteWord !== undefined ? isCompleteWord : false;
    this.children = {};
};

/**
 * Inserts a word into the trie.
 * @param {string} word
 * @return {void}
 */
Trie.prototype.insert = function (word) {
    if (word.length === 0) {
        this.isCompleteWord = true;
        return;
    }
    const first = word[0];
    const rest = word.substring(1);
    const isCompleteWord = rest.length === 0;

    if (this.children[first] === undefined) {
        this.children[first] = new Trie(first, isCompleteWord);
        if (rest.length > 0) {
            this.children[first].insert(rest);
        }
    } else {
        this.children[first].insert(rest);
    }

    /* for (let i = 0; i < word.length; i++) {
        const char = word[i];
        const isCompleteWord = i === word.length - 1;
        if (this.children[char] !== undefined) {
            this.children[char].insert(word.substring(i));
            if (isCompleteWord) {
                this.children[char].isCompleteWord = isCompleteWord;
            }
        } else {
            this.children[char] = new Trie(char, isCompleteWord)
        }
    } */
};

/**
 * Returns if the word is in the trie.
 * @param {string} word
 * @return {boolean}
 */
Trie.prototype.search = function (word) {
    let node = this;
    for (let i = 0; i < word.length; i++) {
        node = node.children[word[i]];
        if (node === undefined) {
            return false;
        }
        if (i === word.length - 1) {
            return node.isCompleteWord;
        }
    }
};

/**
 * Returns if there is any word in the trie that starts with the given prefix.
 * @param {string} prefix
 * @return {boolean}
 */
Trie.prototype.startsWith = function (prefix) {
    let node = this;
    for (let i = 0; i < prefix.length; i++) {
        node = node.children[prefix[i]];
        if (node === undefined) {
            return false;
        }
    }
    return true;
};

/**
 * Your Trie object will be instantiated and called as such:
 * var obj = new Trie()
 * obj.insert(word)
 * var param_2 = obj.search(word)
 * var param_3 = obj.startsWith(prefix)
 */

function program() {
    const words = [
        "car",
        "card",
        "mechanic",
        "merchandize",
        "merit",
        "case",
        "cast",
    ];
    const words2 = [
        "car",
        "cat",
        "card",
        "cardio",
        "melancholy",
        "merchandize",
        "merit",
        "case",
        "cast",
        "career",
    ];

    const prefixes = [
        "car",
        "me",
        "merchandize",
        "ar",
        "case",
    ];
    const trie = new Trie();
    for (let word of words) {
        trie.insert(word);
    }

    let existing = "";
    for (let word of words) {
        existing += `word: ${word}: ${trie.search(word)}\n`;
    }
    // console.log(existing);

    let mix = "";
    for (let word of words2) {
        mix += `word: ${word}: ${trie.search(word)}\n`;
    }
    // console.log(mix);

    let startsWith = "";
    for (let prefix of prefixes) {
        startsWith += `prefix: ${prefix}: ${trie.startsWith(prefix)}\n`;
    }

    console.log(startsWith);
}

program();
