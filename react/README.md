# Notes on react.js

## What is React?

React is a JavaScript library created by Facebook in 2011 for developing dynamic user interfaces.

> [!NOTE]+ The main idea of React
> Components help us write reusable, modular, and better organized code

## Structure

`node_modules/` for external sources
`public/` for images, video files
`src/` for project source files
in root folder there is a `index.html` with root element for rendering

For components one should use `PascalCase` where each letter in world starts with uppercase letter
All the JSX (JavaScript XML) code get converted to the functional JavaScript elements creating (for
more examples: [babeljs.io/repl](babeljs.io/repl)), also JSX markup in the return statement should
be wrapped by parenthesis in case it is multiline

React itself do not render anything on the page, it creates virtual DOM and the special library
`react-dom` renders the tree into the browser (for example, with `React Native` we can render
virtual DOM as the mobile application)

React element should return only one element, if one needs to wrap his several items in one bigger,
one can use `React.fragment` or just empty diamond braces `<>`
