#include <iostream>
#include <ctime>
using namespace std;

class ERP {
    string quality;
    float meter;
    string date;
    int choice;
 float used ;
public:
    // function to get current date
    string getDate() {
        time_t now = time(0);
        tm *ltm = localtime(&now);

        int day   = ltm->tm_mday;
        int month = 1 + ltm->tm_mon;
        int year  = 1900 + ltm->tm_year;

        return to_string(day) + "/" +
               to_string(month) + "/" +
               to_string(year);
    }

    void add() {
        while (1) {
            cout << "\n---- MENU ----\n";
            cout << "1. Add new stock\n";
            cout << "2. View stock\n";
            cout << "3. Allot stock\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter quality name: ";
                    cin >> quality;

                    cout << "Enter meter: ";
                    cin >> meter;

                    date = getDate();
                    cout << "Stock added successfully!\n";
                    break;

                case 2:
                    if (quality.empty()) {
                        cout << "No stock available!\n";
                    } else {
                        cout << "\n--- Stock Details ---\n";
                        cout << "Quality : " << quality << endl;
                        cout << "Meter   : " << meter << endl;
                        cout << "Date    : " << date << endl;
                         cout << "alloted    : "<<used <<\\ << date << endl;
                    }
                    break;

                case 3:
                    if (quality.empty()) {
                        cout << "No stock to allot!\n";
                    } else {
                     
                        cout << "Enter meter to allot: ";
                        cin >> used;

                        if (used > meter) {
                            cout << "Not enough stock!\n";
                        } else {
                            meter -= used;
                            cout << "Stock allotted successfully!\n";
                        }
                    }
                    break;

                case 4:
                    cout << "Exiting program...\n";
                    return;

                default:
                    cout << "Invalid choice!\n";
            }
        }
    }
};

int main() {
    ERP e1;
    e1.add();
    return 0;
}
