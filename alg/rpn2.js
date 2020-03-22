function isBinaryOperator(token) {
    const operators = [
        "+",
        "-",
        "*",
        "sqrt",
    ]
    return operators.includes(token);
}

function isUnaryOperator(token) {
    return token === "sqrt";
}

function evaluate(operator, operand1, operand2) {
    if (operator === "+") {
        return operand1 + operand2;
    } else if (operator === "-") {
        return operand2 - operand1;
    } else if (operator === "*") {
        return operand1 * operand2;
    } else if (operator === "sqrt") {
        return Math.sqrt(operand1);
    }
}

function rpnCalculator(expression) {
    const results = [];
    for (let token of expression.split(" ")) {
        if (isUnaryOperator(token)) {
            const operand = parseFloat(results.pop());
            results.push(evaluate(token, operand, undefined))
        } else if (isBinaryOperator(token)) {
            const operand1 = parseFloat(results.pop());
            const operand2 = parseFloat(results.pop());

            results.push(evaluate(token, operand1, operand2));
        } else {
            results.push(parseFloat(token));
        }
    }
    return results[0];
}

const ex1 = "6 8 4 + 3 2 + - *";
const ex2 = "3 4 2 + *";
const ex3 = "5 4 2 * 3 + + sqrt";
const ex4 = "3.12 4 + 2 *";
console.log(rpnCalculator(ex1));
console.log(rpnCalculator(ex2));
console.log(rpnCalculator(ex3));
console.log(rpnCalculator(ex4));