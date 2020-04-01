/* Problem 1 */
/*
Write a program that outputs sequentially the integers from 1 to 99,
but on some conditions prints a string instead:
- When the integer is a multiple of 3, print "Open" instead of the number
- When the integer is a multiple of 7, print "Source" instead of the number
- When it is a multiple of both, print "OpenSource"
*/

function openSource() {
    for (let i = 1; i < 99; i++) {
        if (i % 3 === 0 && i % 7 === 0) {
            console.log("OpenSource");
        } else if (i % 3 === 0) {
            console.log("Open");
        } else if (i % 7 === 0) {
            console.log("Source");
        } else {
            console.log(i)
        }
    }
}

console.log(openSource());

/*
Problem 2 - Guess a number
Find a number between 1 and 1 000 000 in less than 50 guesses.
Write a function that solves the game without user input and
returns the solution by using the function verify() which is
defined with the following spec:

function verify(guess: number) -> integer
Argument:
    guess - the number to verify
Returns:
    0 if guess is the solution, your program won
    -1 if the solution is smaller than the guess parameter
    1 if the solution is smaller than the guess parameter
*/
/*

*/
function hangmanIter(secretNumber, lowest, largest) {
    let numberOfTries = 0;
    let low = lowest;
    let high = largest;
    let guess = verify((low + high) / 2);
    while (guess !== 0) {
        if (guess === -1) {
            guess =1;
        }
        numberOfTries++;
    }

    console.log(`Found ${secretNumber} to be the secret number in ${numberOfTries} tries!`);
    return secretNumber;

    function verify(guess) {
        if (secretNumber === guess) {
            return 0;
        } else if (secretNumber < guess) {
            return -1;
        } else {
            return 1;
        }
    }
}

const secretNumber = 2;

function verify(guess) {
    console.log(`Checking ${guess} agains ${secretNumber}`);
    if (secretNumber === guess) {
        return 0;
    } else if (secretNumber < guess) {
        return -1;
    } else {
        return 1;
    }
}

function hangman(secretNumber, low, high, numberOfTries) {
    numberOfTries += 1;
    let middle = Math.floor((low + high) / 2);
    let guess = verify(middle);
    if (guess === 0) {
        console.log(`Found ${secretNumber} to be the secret number in ${numberOfTries} tries!`);
        return secretNumber;
    } else if (guess === -1) {
        return hangman(secretNumber, low, middle, numberOfTries);
    } else {
        return hangman(secretNumber, middle, high, numberOfTries);
    }
}

console.log(hangman(secretNumber, 1, 10, 0));

/* Problem 3 */
/*
Return the sum of list items that are integers.
Note: I will be assuming strings that contain digits interspersed/surrounded
with spaces will count as integers.
I.e. "1 000 000" will be counted as an integer,
Also, strings conta
 will not be counted as an integer.
*/
function isInteger(value) {
    if (isNaN(value)) {
        return false;
    }
    const num = parseFloat(value.replace(/\s/g, ''));
    return Number.isInteger(num);
}

function sumInts(wildList) {
    return wildList.reduce((sum, item) => sum + isInteger(item) ? item : 0, 0);
}

/* Problem 4 */
function sumIntsRecursive(mixedList) {
    if (mixedList.length === 0) {
        return 0;
    }

    const [head, ...tail] = mixedList;
    if (isInteger(head)) {
        return parseFloat(head) + sumIntsRecursive(tail);
    } else {
        return sumIntsRecursive(tail);
    }
}
const list = [
    "1984",
    "1922",
    "11/22/63",
    "2001: A Space Odyssey",
    "Rendezvous with Rama",
    "Childhood's End",
];
console.log(sumIntsRecursive(list));

/* Problem 5 */
/*
1. Write pseudo-SQL statements to create database tables to store products of a webshop.
Each product has a name, price, a creation date, and may belong to several categories.
Categories have a name and a flag to indicate whether the category is private or public.
2. Write a SQL query to find the list of products that belong to more than 5 public categories.
*/
CREATE TABLE product (id INT PRIMARY KEY AUTO_INCREMENT, name VARCHAR(20), price DECIMAL,
       create_date DATE);

CREATE TABLE category (id INT PRIMARY KEY AUTO_INCREMENT, name VARCHAR(20), public BOOLEAN);
CREATE TABLE product_category (id INT PRIMARY KEY AUTO_INCREMENT, name VARCHAR(20), public BOOLEAN);

PRIMARY KEY product_id,
FOREIGN KEY product_id REFERENCES product(id)
PRIMARY KEY category_id,
FOREIGN KEY category_id REFERENCES product(id)

left_tbl JOIN product_category ON product.id = product_category.product_id WHERE COUNT(*) >= 3

/* Problem 6 */
# open-webpage.py

import urllib.request, urllib.error, urllib.parse

url = 'https://www.sap.com/belgique/index.html'

response = urllib.request.urlopen(url)
webContent = response.read()

print(webContent[0:300])
