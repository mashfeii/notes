# "Thinking in React"

1. Break the desired UI into **components** and establish the **component tree**
2. Build a **static** version in React (without state)
3. Think about **state**:
   - When to use state
   - Types of state: local vs. global
   - Where to place each piece of state
4. Establish **data flow:**
   - One-way data flow
   - Child-to-parent communication
   - Accessing global state

## State management

> [!NOTE] State management
> Deciding **when** to create pieces of state, what **type** of state are necessary, **where** to
> place each piece of state, and how data **flows** through the application

| Local State                                                                                  | Global State                                                                         |
| -------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------ |
| State needed **only by one or few components**                                               | State that **many components** might need                                            |
| State is defined in a component and **only that component and child ones** have access to it | **Shared** state that is accessible to **every component** in the entire application |

**Global State** can be managed either with React Context API or external library (e.g.: Redux)

## State: when and where to create?

**When** to create state:
Need to store data → Will data change at some point? → **NO** → Regular `const` variable
→ **YES** → Can be computer from existing state/props? → **YES** → Derive state
→ **NO** → Should it re-render component? → **NO** → Ref(`useRef`)
→ **YES** → Place a new piece of state in component

**Where** to create state:
Only used by this component? → **YES** → Leave in component
→ **NO** → Also used by a child component? → **YES** → Pass to child via props
→ **NO** → Used by one or a few sibling components? → **YES** → Lift state up to first common parent
→ **NO** → Probably **global state**

### Lifting state up

> [!NOTE]
> By **lifting state up**, we have successfully **shared** one piece of state with multiple
> component in **different positions** in the component tree

### Derived State

> [!NOTE] Derived state
> State that is computed from an existing piece of state or from props, just regular variables, no `useState`
