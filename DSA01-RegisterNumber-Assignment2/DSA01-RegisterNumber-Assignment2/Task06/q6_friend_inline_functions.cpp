#include <iostream>
#include <cmath>

// Q6: Friend Functions and Inline Functions (Train Journey Planner)

class Time {
    int h, m;

public:
    Time(int hh, int mm) : h(hh), m(mm) {}
    
    // Friend functions declaration
    friend int minutesBetween(const Time& a, const Time& b);
    friend bool earlier(const Time& a, const Time& b);
};

int minutesBetween(const Time& a, const Time& b)
{
    // TODO 1: Using the private members h and m, return the absolute difference between
    // the two times in minutes
    int totalMinA = a.h * 60 + a.m;
    int totalMinB = b.h * 60 + b.m;
    int diff = totalMinA - totalMinB;
    return (diff < 0) ? -diff : diff;
}

bool earlier(const Time& a, const Time& b)
{
    // TODO 2: Return true if a is earlier in the day than b
    int totalMinA = a.h * 60 + a.m;
    int totalMinB = b.h * 60 + b.m;
    return totalMinA < totalMinB;
}

int main()
{
    std::cout << "=== Q6: TRAIN JOURNEY PLANNER (FRIEND FUNCTIONS) ===\n";
    Time departure(9, 45), arrival(13, 10);
    std::cout << minutesBetween(departure, arrival) << ' '
              << std::boolalpha << earlier(arrival, departure) << '\n';

    // Test same time twice and across noon
    Time noon1(12, 0), noon2(12, 0);
    Time night(23, 30), morning(1, 15);
    std::cout << "Same time diff: " << minutesBetween(noon1, noon2) << " mins\n";
    std::cout << "Across noon earlier (night, morning): " << std::boolalpha << earlier(night, morning) << '\n';
    return 0;
}
