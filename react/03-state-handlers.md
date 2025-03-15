# How to work with data and change it

## Handlers

Handlers are attached to the elements as default HTML attributes, but in camelCase: `onClick`,
`onMouseEnter`, etc. Inside handlers, we should provide **function declaration (callback function)**,
not the function call! (`onClick={() => function()}` instead of `onClick={function()}`)

## State - the most important concept in React ("Component memory")

Data that a component **can hold over time**, necessary for information that it needs to
**remember** throughout the app's lifecycle

To create a piece of data and function to change it, we use `useState(initial_value)` hook
that provides and array: `[state_variable, function_to_change_it]`
Also, `useState` or other **hooks** can be called only **inside the component** on the top level
We **can not** update the state manually, **only using react function**

### The mechanics of state in React

We do not do direct DOM manipulations → **_In react, a view is updated by re-rendering the
component_** → A component is re-rendered when its state is updated → **To update a view, we
update the state**

> [!IMPORTANT]
> When we are changing the state based on the previous piece, it is better to use function with
> previous state as a parameter

### Practical guideline

- Use a state variable for any data that the component should keep track of ("remember") over time.
  **This is data that will change at some point**. In Vanilla JS, that's a `let` variable (or `[]`, `{}`)
- Whenever you want something in the component to be **dynamic**, create a piece of state related to
  that "thing", and update the state when the "thing" should change
- For data that could not trigger component re-renders, **do not use state**. Use a regular variable
  instead

### Controlled Elements

Simply, it is connection between state and some input field, to make such a connection, we need to
create a state, make the input value equals to state value and change the state on each input value
change

## Summary

| State                                  | Props                                        |
| -------------------------------------- | -------------------------------------------- |
| **Internal** data, owned by component  | **External** data, owned by parent component |
| Component "memory"                     | Similar to function parameters               |
| Can be updated by the component itself | **Read-only**                                |
| Updating state causes re-rendering     | **Receiving new props** causes re-render     |
| Used to make components interactive    | Used by parent to configure child            |
