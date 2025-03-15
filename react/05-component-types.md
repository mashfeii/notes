# Components Categories

- Stateless/presentational components
  - **No state**
  - Can receive props and _simply present_ received data or other content
  - Usually **small and reusable**
- Stateful components
  - **Have state**
  - Also _can be reusable_
- Structural components
  - _Pages_, _Layouts_ or _Screens_ of the application
  - Result of **composition**
  - Can be **huge** and **non-reusable**

## Composition

Composition is used for reducing the number of redundant components, or to explicitly show the
inside elements of the components, for example, it is the `{children}` prop or explicitly defined
`JSX Element` prop

### Variables inside components

Variables inside components that **should not be re-rendered** must stay outside the component
(since render is a function call that will create again all inner elements)
