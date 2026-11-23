#include <iostream>
#include <string>

// Q5: Static Members and Arrays of Objects (College Bus Seat Tickets)

class Token {
    static int next;
    int id;
public:
    Token() { id = ++next; }
    int get() const { return id; }
    static int issued() { return next - 100; }
};

int Token::next = 100;

class BusTicket {
    static int issued;                 // shared by all BusTicket objects
    static const int CAPACITY = 3;
    int seat;
    std::string name;

public:
    explicit BusTicket(const std::string& n) : seat(0), name(n)
    {
        // TODO 1: If fewer than CAPACITY tickets have been issued, increase issued and
        // give this ticket the next seat number; otherwise leave seat as 0 (waiting list)
        if (issued < CAPACITY) {
            seat = ++issued;
        } else {
            seat = 0;
        }
    }

    static int count()
    {
        // TODO 2: Return the number of seats issued so far
        return issued;
    }

    void print() const
    {
        std::cout << name << ": "
                  << (seat ? "Seat " + std::to_string(seat) : std::string("Waiting"))
                  << '\n';
    }
};

int BusTicket::issued = 0;         // definition of the static data member

void issueBatch() {
    BusTicket localTrip[2] = {BusTicket("X") , BusTicket("Y")};
    std::cout << "[Function batch issued count: " << BusTicket::count() << "]\n";
}

int main() {
    std::cout << "=== Q5: PREDICT THE OUTPUT SNIPPET ===\n";
    Token counter[3];
    Token extra;
    std::cout << counter[0].get() << ' ' << counter[2].get() << ' ' << extra.get()
              << ' ' << Token::issued() << '\n';

    std::cout << "\n=== Q5: COMPLETE THE CODE VERIFICATION ===\n";
    BusTicket trip[4] = {BusTicket("Asha"), BusTicket("Bala"),
                         BusTicket("Chitra"), BusTicket("Dev")};
    for (const BusTicket& t : trip) t.print();
    std::cout << "Issued: " << BusTicket::count() << '\n';
    return 0;
}
