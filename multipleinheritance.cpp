#include <iostream>
using namespace std;

namespace student {

// -------- Base class 1 ----------
class StudentDetails {
public:
    string name;
    int age;
    string course;

    StudentDetails(string n = "Gaurav", int a = 21) {
        name = n;
        age = a;
        course = "Full Stack";
    }

    void showStudent() {
        cout << "\n--- Student Details ---\n";
        cout << "Name   : " << name << endl;
        cout << "Age    : " << age << endl;
        cout << "Course : " << course << endl;
    }
};

// -------- Base class 2 ----------
class Address {
public:
    string city;
    string state;
    int pincode;

    Address() {
        city = "Nandurbar";
        state = "Maharashtra";
        pincode = 425412;
    }

    void showAddress() {
        cout << "\n--- Address Details ---\n";
        cout << "City    : " << city << endl;
        cout << "State   : " << state << endl;
        cout << "Pincode : " << pincode << endl;
    }
};

// (Multiple Inheritance)
class Marksheet : public StudentDetails, public Address {
public:
    int c, cpp, html, css, js;

    Marksheet(string n) : StudentDetails(n) {
        cout << "\nEnter marks for " << name << endl;

        c   = getMarks("C");
        cpp = getMarks("C++");
        html= getMarks("HTML");
        css = getMarks("CSS");
        js  = getMarks("JavaScript");
    }

    int getMarks(string subject) {
        int marks;
        while (true) {
            cout << "Enter marks of " << subject << " (0-100): ";
            cin >> marks;
            if (marks >= 0 && marks <= 100)
                return marks;
            else
                cout << "Invalid marks, try again\n";
        }
    }

    void showMarksheet() {
        int total = c + cpp + html + css + js;
        float avg = total / 5.0;

        cout << "\n--- Marksheet ---\n";
        cout << "Total   : " << total << endl;
        cout << "Average : " << avg << endl;

        if (avg >= 40)
            cout << "Status  : PASS\n";
        else
            cout << "Status  : FAIL\n";

        showATKT();
    }

    void showATKT() {
        cout << "\n--- ATKT Details ---\n";
        if (c < 40)   cout << "ATKT in C\n";
        if (cpp < 40) cout << "ATKT in C++\n";
        if (html < 40)cout << "ATKT in HTML\n";
        if (css < 40) cout << "ATKT in CSS\n";
        if (js < 40)  cout << "ATKT in JavaScript\n";
    }
};

//Hierarchical Inheritance
class Ruchit : public Marksheet {
public:
    Ruchit() : Marksheet("Ruchit") {}
};

class Gaurav : public Marksheet {
public:
    Gaurav() : Marksheet("Gaurav") {}
};

} // namespace end

int main() {
    using namespace student;

    Ruchit r1;
    r1.showStudent();
    r1.showAddress();
    r1.showMarksheet();
     
     Gaurav g1;
     g1.showStudent();
    g1.showAddress();
    g1.showMarksheet();

    // Agar aur student chahiye
    // GauravStudent g1;

    return 0;
}
