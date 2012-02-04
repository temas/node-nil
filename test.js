var nil = require("./build/Release/nil.node").Nil();
console.log(nil);
console.log(nil.what);
console.log(nil.what.huh);
for (x in nil) {
    console.log(x);
}

nil.x = 123
console.log(nil.x);

console.log(Object.keys(nil));

delete nil.key;

function testIt(value) {
    this.prop = value;
    return this;
}
var x = new testIt("test!");
x.__proto__ = nil;
console.log(x.prop);
console.log(x.what.test);

for (val in x) {
    console.log(val + ":" + x[val]);
}

console.log(Object.keys(x));

x.test = "Another test";
console.log(Object.keys(x));
console.log(x.test);

console.log(x.unknown);

y = {};
y.__proto__ = nil;
y.what = "Test";
console.log(y.what);
console.log(y.huh);
