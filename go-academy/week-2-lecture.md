# Functional Programming

The idea is stand on **lambda-functions**
The functions are represented only as their result

## Concepts

- Declarative
- Pure functions
- Immutability
- First order function and the highest order funcitons

### Declarative (programming paradigm)

Propetry of a good code, not only FP

Declarative: "Take me from point A to point B"
Imperative: "Start the car -> Push gas -> Turn left -> Stop on traffic lights -> Go into the yard -> Turn -> Stop"

### Immutability

Why mutate is bad?

- Data is inconsistent
- May be side effects
- It is harder to find the problem and to track object lifetime

Why immutable is good?

- Immutable data is thread-safe
- Such data is easier to test and debug since of its modularity

Since following function may change the order of elements - it's not immutable

```javascript
images = [
  {
    location: "X",
    created_at: 1725512345,
    awecomeness: 10,
  },
  {
    location: "Y",
    created_at: 1725504321,
    awesomeness: 7,
  },
];

function doSmth(images) {
  imagesCopy = copy(images); // for immutability
  imagesCopy.sort();
  //...
  images.sort();
  //...
}
```

**In FP immutability is implied by default**

### First and high-order functions

Elements of first-order functions

```javascript
function doSmth(fn) {
  return fn();
}
function doSmth() {
  return doLog;
}
action = function () {
  log("hello, fp");
};
actions = [
  function () {
    log("hello, fp");
  },
  function () {
    log("hello, fp");
  },
];
```

**The highest-order** function takes another function as parameter or returns one
