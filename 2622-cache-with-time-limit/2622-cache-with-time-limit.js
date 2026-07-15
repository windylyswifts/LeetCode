var TimeLimitedCache = function() {
    
};

/** 
 * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
var TimeLimitedCache = function() {
    map = new Map();
    var timer;
};

TimeLimitedCache.prototype.set = function(key, value, duration) {
    let res = map.has(key);
    if(res) {
        clearTimeout(map.get(key).timer);
    }
    timer = setTimeout(()=>map.delete(key), duration);
    map.set(key, {value: value, timer: timer} );
    return res;
};

TimeLimitedCache.prototype.get = function(key) {
    if(map.has(key)) return map.get(key).value;
    return -1;
};

TimeLimitedCache.prototype.count = function() {
    return map.size;
};

/**
 * const timeLimitedCache = new TimeLimitedCache()
 * timeLimitedCache.set(1, 42, 1000); // false
 * timeLimitedCache.get(1) // 42
 * timeLimitedCache.count() // 1
 */