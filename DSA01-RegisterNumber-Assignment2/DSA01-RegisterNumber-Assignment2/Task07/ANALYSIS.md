# Q7 – Day-4 Design Challenge: Diagnose, Redesign and Validate (13 Marks)

## A. Diagnose the Limitation (2 Marks)
- **Identified Limitation**: In Q4, the mini-statement transaction history relies on a fixed array of size 10 that shifts elements left whenever an 11th transaction arrives. If the requirement changes to store the last $k = 10,000$ transactions, shifting $10,000$ elements takes $O(k)$ time per transaction deposit/withdrawal, degrading performance significantly in high-frequency banking systems.

## B. Define the Design Objective (2 Marks)
- **Measurable Objective**: Reduce the time complexity of adding a new transaction from $O(k)$ (linear shifting time) to **$O(1)$ constant time**, regardless of how large the transaction history capacity $k$ is.

## C. Design the Revised Solution (4 Marks)
- **Changes**: Replaced the fixed array with a **Circular Buffer** backed by a `std::vector` with integer `head`, `tail`, and `size` pointers.
- **Memory & Trade-offs**: Requires pre-allocating a fixed capacity buffer in memory ($O(capacity)$ space), but insertions and deletions operate in strictly $O(1)$ time without data shifting.

## D. Predict Before Implementing (1 Mark)
- **Prediction**: The circular buffer implementation will execute $10,000$ insertions significantly faster than the shifting array approach (eliminating nested shift loops).

## E. Implement and Validate the Redesign (2 Marks)
- **Validation**: Tested with capacity $k = 5$ and scaled workloads; the circular buffer correctly overwrites oldest transactions in $O(1)$ time.

## F. Defend the Final Design (2 Marks)
- **Evaluation**: The design objective was fully achieved. The circular buffer is optimal for fixed-capacity rolling histories. The original shifting array is acceptable only for very small fixed sizes ($k \le 10$), whereas the circular buffer scales gracefully to millions of items.
