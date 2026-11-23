# Q3 – Default Arguments and Function Overloading (6 Marks)

## 1. Ambiguity Explanation
- If a function is declared with default arguments and also overloaded with fewer parameters (e.g., `void f(double);` and `void f(double, bool = false);`), calling `f(2.0)` causes an **ambiguous call compiler error** because the compiler cannot decide whether to match the 1-parameter function or the 2-parameter function with its default argument.

## 2. Overload Resolution Rules
- **Exact Match**: The parameter types match the argument types precisely.
- **Promotion**: Standard promotions (e.g., `float` $\to$ `double`, `char` $\to$ `int`).
- **Conversion**: Standard conversions (e.g., `int` $\to$ `double`).
- **Default Arguments**: Must always be specified from right to left in parameter lists so calls remain unambiguous.

## 3. Alternative Concept & Complexity Analysis
- **Alternative**: Passing a single `Parcel` structure with optional fields or using function templates.
- **Time Complexity**: Overload resolution happens entirely at **compile time** ($O(0)$ runtime cost), compiling down to direct function calls.
- **Maintainability**: Adding a new courier option (e.g., `fragile`) to overloaded default arguments requires updating every overload signature, whereas a configuration structure (`ParcelOptions`) accommodates new fields cleanly without breaking existing function signatures.
