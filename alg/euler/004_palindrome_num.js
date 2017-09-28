/*
 * Это простой редактор JavaScript.
 *
 * Введите JavaScript, затем щёлкните правой кнопкой или выберите из меню Выполнить:
 * 1. Запустить, чтобы исполнить выделенный текст (Ctrl+R),
 * 2. Исследовать, чтобы вызвать для результата Инспектор Объектов (Ctrl+I), или,
 * 3. Отобразить, чтобы вставить результат в комментарий после выделения. (Ctrl+L)
 */

function reverseString(str) {
    return str.split("").reverse().join("");
}

function isPalindrome(num) {
  const numStr = num.toString();
  const numLen = numStr.length;
  
  if (numLen < 2) {
    return true;
  }
  
  if (numLen % 2 === 0) {
    if (numStr.slice(0, numLen / 2) === reverseString(numStr.slice(numLen / 2))) {
      return true;
    }
  } else {
    if (numStr.slice(0, numLen / 2) === reverseString(numStr.slice((numLen / 2) + 1))) {
      return true;
    }
  }
  
  return false;
}

function* palindromes() {
  while (true) {
    let num1 = 100;
    
    while (num1 <= 999) {
      let num2 = 100;
      
      while (num2 <= 999) {
        const product = num1 * num2;        
        
        if (isPalindrome(product)) {
          // console.log(`${num1} * ${num2} = ${product} ${isPalindrome(product)}`);     
          yield product;
        }
        num2++;
      }
      num1++;
    }
  }
}

function largestPalindrome() {
  let gen = palindromes();

  const largestNum = 999 * 999;

  let largestPalindrome = 1;

  while (largestPalindrome <= largestNum) {
    const newPalindrome = gen.next().value;
    if (newPalindrome > largestPalindrome) {
      largestPalindrome = newPalindrome;
      console.log(largestPalindrome);
     } 
  }
  
  return largestPalindrome;
}

console.log(largestPalindrome());

/*
false
*/
/*
true
*/