/**
 * @param {number} N
 * @param {number[][]} trust
 * @return {number}
 */
var findJudge = function (N, trust) {
    let possibleJudge = N < 2 && trust.length > 0 ? -1 : 1;
    const trustMap = {};
    for (let person of trust) {
        if (trustMap[person[0]] !== undefined) {
            trustMap[person[0]].push(person[1]);
        } else {
            trustMap[person[0]] = [person[1]];
            lastPerson = person[0];
        }
    }

    for (let i = 1; i <= N; i++) {
        if (trustMap[i] === undefined) {
            possibleJudge = i;
        }
    }

    for (let person in trustMap) {
        if (!trustMap[person].includes(possibleJudge)) {
            return -1;
        }
    }

    return possibleJudge;
};
