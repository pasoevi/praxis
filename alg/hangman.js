const secretNumber = 76768;

function verify(guess) {
    if (guess === secretNumber) {
        return 0;
    } else if (secretNumber < guess) {
        return -1;
    } else {
        return 1;
    }
}

function hangman(secretNumber, low, high) {
    let middle = Math.floor((high + low) / 2);
    let guess = verify(middle);

    if (guess === 0) {
        return secretNumber;
    } else if (guess === -1) {
        return hangman(secretNumber, low, middle);
    } else if (guess === 1) {
        return hangman(secretNumber, middle, high);
    }
}
console.log(hangman(76768, 1, 1000000));

function isInteger(value) {
    const valueWithNoSpaces = value.replace(/\s/g, "");
    if (isNaN(valueWithNoSpaces )) {
        return false;
    }

    const num = parseFloat(valueWithNoSpaces);
    return Number.isInteger(num);
}

function sumMixedList(mixedList) {
    return mixedList.reduce((sum, item) => isInteger(item) ? sum + parseFloat(item) : sum, 0);
}


const lst = [
    "1984",
    "1922",
    "4",
    "11/22/63",
    "2001: A Space Odyssey",
    "Rendezvous with Rama",
    "Childhood's End",
];
console.log(sumMixedList(lst));

function sumMixedList2(mixedList) {
    if (mixedList.length === 0) {
        return 0;
    }

    const [head, ...tail] = mixedList;
    if (isInteger(head)) {
        return parseFloat(head) + sumMixedList2(tail);
    } else {
        return sumMixedList2(tail);
    }
 }

 console.log(sumMixedList2(lst));


 function alphabet() {
    const characterArray = [];
    for (let i = 65; i <= 90; i++) {
        characterArray.push(String.fromCharCode(i));
    }
    return characterArray;
}
console.log(alphabet)