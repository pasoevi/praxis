function encrypt(text, n) {
    if (typeof text === "undefined" || text === null) {
        return text;
    }
    
    if (n <= 0) {
        return text;
    }
    
    let encrypted = "";
    const len = text.length;
    
    for (let i = 1; i < len; i += 2) {
        encrypted += text.charAt(i);
    }
    
    for (i = 0; i < len; i += 2) {
        encrypted += text.charAt(i);
    }
    
    return encrypt(encrypted, n - 1);
}

function decrypt(encryptedText, n) {
    if (typeof encryptedText === "undefined" || encryptedText === null) {
        return encryptedText;
    }
    
    if (n <= 0) {
        return encryptedText;
    }
    
    let decrypted = "";
    const len = encryptedText.length;
    let numEverySecond = 0;
    
    
    for (let i = 1; i < len; i += 2) {
        numEverySecond += 1;
    }

    const rest = len - numEverySecond;
    // console.log(`Len = ${len}, numEverySecond = ${numEverySecond}, rest = ${rest}`);
    
    for (i = 0; i < Math.max(numEverySecond, rest); i += 1) {
        if (numEverySecond + i < len) {
            decrypted += encryptedText.charAt(numEverySecond + i);
        }

        if (i < numEverySecond) {
            decrypted += encryptedText.charAt(i);
        }
    }
    
    return decrypt(decrypted, n - 1);
}

console.log("hsi  etTi sats!" + " => " + decrypt("hsi  etTi sats!", 1));
console.log("s eT ashi tist!" + " => " + decrypt("s eT ashi tist!", 2));
console.log(" Tah itse sits!" + " => " + decrypt(" Tah itse sits!", 3));

