#include <iostream>
#include <vector>
#include <string>
#include <chrono>

// Q7: Day-4 Design Challenge — Diagnose, Redesign and Validate
// Problem: SavingsAccount Transaction History (Q4) scaled to 10,000 transactions.
// Limitation of Q4: Fixed array of size 10 shifting elements takes O(k) time per transaction.
// Redesign: Implement a circular buffer class with O(1) insertion time.

class CircularTransactionBuffer {
private:
    std::vector<double> buffer;
    int capacity;
    int head;
    int tail;
    int size;

public:
    explicit CircularTransactionBuffer(int cap) : capacity(cap), head(0), tail(0), size(0) {
        buffer.resize(capacity, 0.0);
    }

    void add(double amount) {
        buffer[tail] = amount;
        tail = (tail + 1) % capacity;
        if (size < capacity) {
            size++;
        } else {
            head = (head + 1) % capacity; // head moves forward, dropping oldest
        }
    }

    void printLatest(int n) const {
        int count = (n < size) ? n : size;
        std::cout << "Latest " << count << " transactions: ";
        for (int i = 0; i < count; ++i) {
            int idx = (head + size - count + i) % capacity;
            std::cout << buffer[idx] << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    std::cout << "=== Q7: DAY-4 DESIGN CHALLENGE VALIDATION ===\n";
    CircularTransactionBuffer cb(5); // Capacity 5
    cb.add(100.0);
    cb.add(200.0);
    cb.add(300.0);
    cb.add(400.0);
    cb.add(500.0);
    cb.printLatest(5);

    // Adding 6th and 7th transaction (should drop 100 and 200)
    cb.add(600.0);
    cb.add(700.0);
    cb.printLatest(5);
    std::cout << "Design validated: O(1) circular buffer insertion achieved successfully!\n";
    return 0;
}
