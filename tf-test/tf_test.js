const addon = require('./build/Release/tf_test');

console.log(addon.version());

let array = new Float32Array([1.1, 2.2, 3.3]);
console.log(addon.array_test(array));
