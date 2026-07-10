/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function (functions) {

    return function (x) {
        // Start the snowball at 'x', and apply each function from right to left
        return functions.reduceRight((val, fn) => fn(val), x);
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */