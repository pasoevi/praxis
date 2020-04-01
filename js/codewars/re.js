function order(words){
    let result = [];
    words.split(" ").forEach(word => result[word.match(/\d+/)] = word);
    
    return result.join(" ").trim();
}

console.log(order("is2 Thi1s T4est 3a"));
console.log(order("4of Fo1r pe6ople g3ood th5e the2"));
console.log(order(''));

