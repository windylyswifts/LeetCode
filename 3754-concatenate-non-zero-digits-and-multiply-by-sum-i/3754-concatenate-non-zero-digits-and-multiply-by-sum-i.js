/**
 * @param {number} n
 * @return {number}
 */
var sumAndMultiply = function (n) {
    const arr = String(n).split('').map(Number);
    let tempArr = [];
    let x = 0; 
    
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] != 0) {
            x += arr[i];
            tempArr.push(arr[i]);
        }
    }
    tempArr = Number(tempArr.join('')); 

    return x * tempArr;
};