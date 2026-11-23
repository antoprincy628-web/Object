#include <iostream>
#include <vector>
#include <algorithm>

// Q2: Return by Reference and Its Dangers (Examination Marks Register)

// 1. Returning a reference to an element in an array/vector
int& getHighestMark(std::vector<int>& marks) {
    auto maxIt = std::max_element(marks.begin(), marks.end());
    return *maxIt; // safe as long as vector outlives reference
}

// 2. Dangerous function returning reference to local variable (generates compiler warning)
// int& getLocalRef() {
//     int localVal = 99;
//     return localVal; // DANGER: Dangling reference!
// }

int main() {
    std::cout << "=== Q2: RETURN BY REFERENCE & VECTOR GROWTH DANGER ===\n";
    std::vector<int> marks = {78, 85, 92, 65, 88};
    
    std::cout << "Before moderation, highest mark: " << getHighestMark(marks) << '\n';
    
    // Using return by reference on the left of assignment operator (=) to apply +2 moderation
    getHighestMark(marks) += 2;
    
    std::cout << "After applying +2 moderation directly: " << getHighestMark(marks) << '\n';

    std::cout << "\n--- Vector Growth Invalidation Demonstration ---\n";
    int& topRef = getHighestMark(marks);
    std::cout << "topRef points to highest mark: " << topRef << '\n';
    
    // Trigger vector reallocation by pushing many elements
    marks.insert(marks.end(), {95, 99, 100, 105, 110, 120, 130});
    std::cout << "Vector reallocated due to growth.\n";
    // topRef is now dangling! Accessing it is undefined behaviour.
    std::cout << "Safe practice: index or iterator should be used instead of raw references across reallocations.\n";
    return 0;
}
