// you can write to stdout for debugging purposes, e.g.
// console.log('this is a debug message');


function removeKConsecutive(array, start, k) {
    let charactersToRemove = k;
    let currentStringIndex = start;
    while (charactersToRemove > 0 && currentStringIndex < array.length) {
        console.log(`array: ${array}, start: ${currentStringIndex}, charactersToRemove: ${charactersToRemove}`);
        if (array[currentStringIndex].length === charactersToRemove) {
            array.splice(currentStringIndex, 1);
            charactersToRemove = 0;
            currentStringIndex++;
        } else if (array[currentStringIndex].length < charactersToRemove) {
            charactersToRemove = charactersToRemove - array[currentStringIndex].length;
            array.splice(currentStringIndex, 1);
            currentStringIndex++;
        } else {
            array[currentStringIndex] = array[currentStringIndex].substring(charactersToRemove-1);
            charactersToRemove = 0;

        }
    }
}

function splitString(string, k) {
    let lastLetter = "";
    let lastLetterOccurs = 0;
    let longestConsecutive = 0;
    let indexAfterlongestConsecutive = -1;
    let resultIndexAfterlongestConsecutive = -1;
    let result = [];
    for (let i = 0; i < string.length; i++) {
        if (lastLetter === string[i]) {
            lastLetterOccurs++;
            result[result.length-1] = result[result.length-1] + string[i];
            if (lastLetterOccurs > longestConsecutive && i < string.length - 1) {
                longestConsecutive = lastLetterOccurs;
                indexAfterlongestConsecutive = i + 1;
                resultIndexAfterlongestConsecutive = result.length;

            }
        } else {
            result.push(string[i]);
            lastLetter = string[i];
            lastLetterOccurs = 1;
        }
    }

    console.log(`Index after: ${resultIndexAfterlongestConsecutive}`);
    console.log(result);
    removeKConsecutive(result, resultIndexAfterlongestConsecutive, k);
    console.log(result);
    return result;
}

function joinWithCompression(array) {
    return array.reduce((result, currentString) => {
        const length = currentString.length;
        return result + length > 1 ? length + currentString[0] : currentString
    }, "");
}


let example = "AAAAAAAAAAABXXAAAAAAAAAA";
// console.log(removeKConsecutive(example, ));
console.log();