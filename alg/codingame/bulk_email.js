const N = parseInt(readline());
let j = 0;
let str = "";
for (let i = 0; i < N; i++) {
    str += readline() + "\n";
}

const reg = /\([\s\S]*?\)/g;
const matches = str.matchAll(reg);
for (let mtc of [...matches]) {
    let choice = mtc[0];
    let chosen = choice.replace("(", "");
    chosen = chosen.replace(")", "");
    choices = chosen.split("|");
    chosen = choices[j % choices.length];
    str = str.replace(choice, chosen);
    j++;
}
console.log(str);
