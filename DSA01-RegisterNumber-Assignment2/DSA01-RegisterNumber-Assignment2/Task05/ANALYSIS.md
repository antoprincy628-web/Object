# Q5 – Static Members and Arrays of Objects (7 Marks)

## 1. Predict the Output Analysis (`Token` Snippet)
- **Output**: `101 103 104 4`
- **Explanation**: `Token::next` starts at `100`. Array `counter[3]` invokes the default constructor 3 times, setting IDs to `101`, `102`, `103`. Object `extra` sets ID to `104`. `Token::issued()` returns `next - 100` $\to$ `104 - 100 = 4`.

## 2. Complete the Code Verification (`BusTicket`)
- Asha, Bala, and Chitra get seats `1`, `2`, and `3`. Dev gets `"Waiting"` (`seat = 0`). Total issued count is `3`.

## 3. Alternative Concept & Complexity Analysis
- **Alternative**: Using a global variable or passing a `TicketOffice` object to every `BusTicket` constructor.
- **Time & Space Complexity**: $O(1)$ time and $O(1)$ space (one integer counter) in all designs.
- **Encapsulation & Multi-Bus Support**: Static members belong to the class and provide clean encapsulation, but share state globally across all instances. If running **two separate buses simultaneously**, static members fail because they share a single global `issued` counter, whereas a `TicketOffice` instance allows multiple independent bus instances.
