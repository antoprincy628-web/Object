# Q6 – Friend Functions and Inline Functions (8 Marks)

## 1. Friend Function Rationale
- A friend function is needed when a function operates symmetrically on two objects of the same class (e.g., comparing `Time a` and `Time b`) and needs direct access to private members `h` and `m` without favoring either object as the implicit `this` pointer recipient.

## 2. Friend vs. Member Function
- **Member function**: Called on an object (`obj.func()`), has an implicit `this` pointer.
- **Friend function**: Non-member function called normally (`func(a, b)`), but granted explicit access to `private` and `protected` members.

## 3. Inline Functions
- The `inline` keyword requests the compiler to replace the function call site directly with the function body to eliminate function call overhead for high-frequency small functions called millions of times.

## 4. Alternative Concept & Complexity Analysis
- **Alternative**: Using public member functions (`a.minutesTo(b)`) or public getters (`getHour()`, `getMinute()`).
- **Time & Space Complexity**: $O(1)$ time per call across all designs after inlining.
- **Encapsulation**: Public getters expose internal representation and violate encapsulation by allowing arbitrary external code to mutate or inspect raw private fields, whereas friend functions restrict access exclusively to designated helper functions.
