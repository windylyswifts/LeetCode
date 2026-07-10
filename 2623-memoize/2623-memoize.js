/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    // We use a blank object to store our previous questions and answers.
    // Because of closures, the inner function will remember this notebook forever.
    const cache = {};

    return function(...args) {
        // We need a way to write down the exact inputs. 
        // JSON.stringify turns the arguments array into a strict string.
        // If args is [2, 3], key becomes "[2,3]". 
        // If args is [3, 2], key becomes "[3,2]". (Perfect for the 'sum' rule!)
        const key = JSON.stringify(args);

        // 'key in cache' asks JavaScript: "Does this exact string exist as a label in our object?"
        if (key in cache) {
            // CACHE HIT! We already know the answer. 
            // Return it immediately without running the heavy math.
            // Notice that we have brackets but its supposed to be just a object not an object of array
            // because the key is a variable and inorder to read it, we use brackets
            return cache[key];
        }

        // We didn't have the answer. We must turn the machine 'fn' on 
        // and feed it the raw materials '...args' to get the result.
        const result = fn(...args);

        // Save the result in the notebook under our specific label.
        cache[key] = result;

        // 6. Hand the final answer to the user
        return result;
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */