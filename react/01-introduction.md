# First look at React

The most common parts of React are **state**, **effect** and **props** where state is a piece of data that
should be displayed in UI (`const [state, setState] = useState(initial value)`), effect
executes the function inside it on every change of controlled variables (`useEffect(function to
call, [values to handle])`) and props are like parameters to the function/data from parent to child
component that is written in JSX element as normal HTML attributes (`<Element prop={something} />`)

## Approaches to site creation

_Server-side rendering_:
The "old" way is server-side rendering: site is build on server then client through browser gets it
with request and browser itself paints it, where JavaScript was included for simple functionality as
animations, hovers

Frontend web application are all about **handling data** and **displaying** it in a user interface
Thus, the main task of application is to keep the UI in sync with data
The main problems with Vanilla JavaScript for modern web applications:

- Requires lots of direct **DOM Manipulations** and **traversing** that leads to mess in code
- Data (state) is usually **stored in the DOM**, shared across entire app

## What is React?

> [!NOTE]
> Extremely popular, declarative, component-based, state driven, JavaScript library for building
> user interfaces created by Facebook

### Based on components

- **Components** are the building blocks of user interface in React (React takes the components and
  draws them on webpage)

### Declarative

- We **describe** how components look like and how they work using a **declarative syntax - JSX**
- **Declarative**: telling React what a component should look like, **based on current data (state)**
- React is **abstraction** away from the DOM: we **never touch the DOM**

### State-driven

There is a some piece of data called **state** → based on it React renders a UI (using
_components_) → Based on some event, the **state** might change → we handle such update and React
**re-renders ** the UI

### JavaScript library

> [!NOTE]
> React is only the _view_ layer, to convert React into framework we need to use Next.js or Remix
> (complete frameworks built on top of React)

## Summary

React is perfect at several things:

1. Rendering components on a webpage (UI) based on their current state
2. Keeping the UI in sync with state, by re-rendering (_reacting_) when state changes

## Options for setting up a React project

1. Create-react-app
   Nowadays can be only used for **experiments**, since it lost the support and works under **webpack**
2. Vite
   Modern tool to create real world application with simple configuration, faster experience and
   lower dependencies
