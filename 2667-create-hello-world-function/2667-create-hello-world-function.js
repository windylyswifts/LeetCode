/**
 * @return {Function}
 */
var createHelloWorld = function() {
    //this problem shows how much we understand hgiher-order functions
    //basically being able to return functions and set functions as parameter
    return function(...args) {
        return "Hello World";
    }
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */