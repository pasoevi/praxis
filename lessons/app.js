/*
Possible improvements:

- Possibility to add new words
- Possibility to add new labels
- Limit the number of labels you can apply to a word
- Make the x icon nicer
- Make it possible to drag words to labels to apply labels to a word
*/

window.onload = function () {
    const words = ["Dog", " Cat", "Good", "Bright", "Green", "Warm"];
    const labels = ["Animals", "Colors", "Food", "Adjectives", "Science"];

    const wordLabels = {};

    const addLabelToWord = function (word, label) {
        if (wordLabels[word] !== undefined) {
            if (!wordLabels[word].find((x) => x === label)) {
                wordLabels[word].push(label);
            }
        } else {
            wordLabels[word] = [label];
        }
        render();
    };

    const renderLabels = function () {
        const labelList = document.querySelector(".label-list");
        labelList.innerHTML = "";
        for (let label of labels) {
            const text = document.createTextNode(label);
            const li = document.createElement("LI");
            li.draggable = true;
            li.addEventListener("dragstart", function (event) {
                event.dataTransfer.setData("text/plain", label);
            });
            li.appendChild(text);
            labelList.appendChild(li);
        }
    };

    const renderWords = function () {
        const wordList = document.querySelector(".word-list");
        wordList.innerHTML = "";
        for (let word of words) {
            const wordElement = document.createElement("div");
            const labelsDiv = document.createElement("div");
            const wordText = document.createTextNode(word);
            wordElement.appendChild(wordText);
            const li = document.createElement("LI");
            const labels = wordLabels[word];
            if (labels !== undefined) {
                for (let label of labels) {
                    const labelText = document.createTextNode(label);
                    const labelElement = document.createElement("span");
                    const labelX = document.createElement("span");
                    labelX.innerHTML = "×";
                    labelX.addEventListener("click", function() {
                        const indexToRemove = wordLabels[word].findIndex(function(l) {
                            return l === label;
                        });
                        wordLabels[word].splice(indexToRemove, 1);
                        render();

                    });
                    labelElement.appendChild(labelText);
                    labelElement.appendChild(labelX);
                    labelsDiv.appendChild(labelElement);
                }
            }
            li.addEventListener("drop", function (event) {
                event.preventDefault();
                const label = event.dataTransfer.getData("text/plain");
                addLabelToWord(word, label);
            });
            li.ondragover = function (event) {
                event.preventDefault();
                event.dataTransfer.dropEffect = "move";
            };
            li.appendChild(wordElement);
            li.appendChild(labelsDiv);
            wordList.appendChild(li);
        }
    };

    const render = function () {
        renderWords();
        renderLabels();
    };
    render();
};
