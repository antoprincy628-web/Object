#include <iostream>

// Q3: Default Arguments and Function Overloading (Courier Charge Calculator)

struct Parcel {
    double weightKg;
};

// Overloaded functions to avoid ambiguity
double calculateCharge(int weightGrams) {
    return static_cast<double>(weightGrams) * 0.05; // Rs 0.05 per gram
}

double calculateCharge(double weightKg, bool express = false, bool insured = false) {
    double base = weightKg * 50.0; // Rs 50 per kg
    if (express) base += 100.0;
    if (insured) base += 50.0;
    return base;
}

double calculateCharge(const Parcel& p) {
    return p.weightKg * 50.0;
}

int main() {
    std::cout << "=== Q3: OVERLOADING & DEFAULT ARGUMENTS ===\n";
    
    // Test cases predicted and executed
    std::cout << "charge(500 grams int)     : Rs " << calculateCharge(500) << '\n';
    std::cout << "charge(2.0 double)        : Rs " << calculateCharge(2.0) << '\n';
    std::cout << "charge(2.0, true)         : Rs " << calculateCharge(2.0, true) << '\n';
    std::cout << "charge(2.0, true, true)   : Rs " << calculateCharge(2.0, true, true) << '\n';
    
    Parcel parcel{3.5};
    std::cout << "charge(Parcel obj)        : Rs " << calculateCharge(parcel) << '\n';

    // What happens with charge(2) or charge(2.0f)?
    // charge(2): 2 is an int. If calculateCharge(int) exists, it matches. If only double overload exists, int promotes to double.
    // charge(2.0f): float promotes to double for double overload.
    std::cout << "charge(2 [int match])     : Rs " << calculateCharge(2) << '\n';
    std::cout << "charge(2.0f [float prom]) : Rs " << calculateCharge(2.0f) << '\n';
    return 0;
}
