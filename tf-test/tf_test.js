const addon = require('./build/Release/tf_test');

console.log(addon.version());

let array1 = new Float32Array([1.1, 2.2, 3.3]);
let array2 = new Float32Array([4.4, 5.5, 6.6]);
console.log(addon.array_test(array1, array2));
