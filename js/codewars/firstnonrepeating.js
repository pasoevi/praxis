function firstNonRepeatingLetter(str) {
    let first, rest;
    
    if (str === undefined || str.length === 0 ) {
        return "";
    }
    
    if (str.length === 1) {
        return str.charAt(0);
    }
    
    first = str.charAt(0);
    rest = str.substring(1);
    console.log(rest);
    
    if (!(rest.toLowerCase().includes(first.toLowerCase()))) {
        console.log(`${rest} doesn't include ${first}`);
        return first;
    }
    
    return firstNonRepeatingLetter(rest.split("").filter(c => c !== first).join(""));
}

process.argv.forEach(function (val, index, array) {
    if (index > 1) {
        console.log(index + ': ' + firstNonRepeatingLetter(val));
    }
});


