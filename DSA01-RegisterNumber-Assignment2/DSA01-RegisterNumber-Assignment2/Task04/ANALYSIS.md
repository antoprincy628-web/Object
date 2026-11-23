# Q4 – Specifying a Class with an Array Inside It (6 Marks)

## 1. Encapsulation & Array Safety
- The array `transactions[10]` must be `private` so external code cannot corrupt transaction history or bypass balance invariants.

## 2. Handling the 11th Transaction
- **Shifting**: Moving $k$ elements takes $O(k)$ time ($O(10)$ for fixed size 10, but $O(50)$ for 50 transactions).
- **Circular Buffer**: Uses a start index pointer, achieving $O(1)$ constant time insertion without shifting elements.

## 3. Alternative Concept & Complexity Analysis
- **Alternative**: Using `std::deque<double>` (`push_back` and `pop_front`) instead of a fixed array or circular buffer.
- **Time Complexity**: Adding a transaction takes $O(1)$ amortized time in `std::deque` and $O(k)$ for shifting $k$ elements in a fixed array.
- **Space Complexity**: Fixed array uses $O(1)$ static stack space ($10 \times 8 = 80$ bytes), whereas `std::deque` allocates dynamic heap memory with pointer overhead.
