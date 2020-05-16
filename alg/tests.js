
/*function solution(string) {
    let lastLetter = "";
    let lastLetterOccurs = 0;
    let longestConsecutive = 0;
    let indexAfterlongestConsecutive = -1;
    let result = [];
    for (let i = 0; i < string.length; i++) {
        if (lastLetter === string[i]) {
            lastLetterOccurs++;
            if (lastLetterOccurs > longestConsecutive) {
                longestConsecutive = lastLetterOccurs;
                indexAfterlongestConsecutive = i + 1;
            }
        } else {
            if (lastLetterOccurs > 1) {
                result.push(lastLetterOccurs + lastLetter);
            } else {
                result += lastLetter;
            }
            result.push(lastLetterOccurs + lastLetter);
            lastLetter = string[i];
            lastLetterOccurs = 1;
        }
    }
    if (lastLetterOccurs > 1) {
        result += lastLetterOccurs + lastLetter;
        if (lastLetterOccurs > longestConsecutive) {
            longestConsecutive = lastLetterOccurs;
            indexAfterlongestConsecutive = string.length - 1;
        }
    }
    return result;
}

*/


function encrypt(string) {
    let lastLetter = "";
    let lastLetterOccurs = 0;
    let longestConsecutive = 0;
    let indexAfterlongestConsecutive = -1;
    let result = [];
    for (let i = 0; i < string.length; i++) {
        if (lastLetter === string[i]) {
            lastLetterOccurs++;
            if (lastLetterOccurs > longestConsecutive) {
                longestConsecutive = lastLetterOccurs;
                indexAfterlongestConsecutive = i + 1;
            }
        } else {
            /* if (lastLetterOccurs > 1) {
                result.push(lastLetterOccurs + lastLetter);
            } else {
                result += lastLetter;
            } */
            result.push(lastLetterOccurs + lastLetter);
            lastLetter = string[i];
            lastLetterOccurs = 1;
        }
    }
    if (lastLetterOccurs > 1) {
        result += lastLetterOccurs + lastLetter;
        if (lastLetterOccurs > longestConsecutive) {
            longestConsecutive = lastLetterOccurs;
            indexAfterlongestConsecutive = string.length - 1;
        }
    }
    return result;
}



