// Javascript: Demonstrate types, scopes, closures

class User {

  constructor(name) {
    this.name = name;
  }
  
}

// Constant, cannot reassign
const me = new User("Student");
console.log(`Me: ${me.name}`);

// Below will fail
// me = new User("Student2")

// Arrays, allowing mixed types
let mixedTypes = [1, "one", '1', me];
console.log(`Mixed types: ${mixedTypes}, length: ${mixedTypes.length}`);

// Dictionary
let myDict = {"one": 1, 4: 45};
console.log(`Dict: ${myDict}, values: one - ${myDict['one']}`);

function scopes() {

  if(true) {
    // var leaks scope
    var leakedVar = "Leaky!";
  }
  console.log(`Leaked var: ${leakedVar}`);

  if(true) {
    // let is safe
    let noLeak = "Leak Proof!";
  }

  // Following will fail
  // console.log(`Leaks?: ${noLeak}`);
}

scopes();

function getClosure(val) {
  return function nestedFn() {
    console.log(`Closure catpured: ${val}`);
  }
}

const myClosure = getClosure("Graduate!");
myClosure();

