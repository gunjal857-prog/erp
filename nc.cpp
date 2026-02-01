#include <iostream>
#include <ctime>
using namespace std;

namespace company {  
class ERP {
    string quality;
    float meter;
    float used;
    string date;
    int choice;

public:
    
    ERP() {
        quality = "";
        meter = 0;
        used = 0;
        date = getDate();   
    }

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

    void menu() {
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
                    addStock();
                    break;

                case 2:
                    viewStock();
                    break;

                case 3:
                    allotStock();
                    break;

                case 4:
                    cout << "Exiting program...\n";
                    return;

                default:
                    cout << "Invalid choice!\n";
            }
        }
    }

private:
    void addStock() {
        cout << "Enter quality name: ";
        cin >> quality;

        cout << "Enter meter: ";
        cin >> meter;

        used = 0;
        date = getDate();

        cout << "Stock added successfully!\n";
    }

    void viewStock() {
        if (quality.empty()) {
            cout << "No stock available!\n";
        } else {
            cout << "\n--- Stock Details ---\n";
            cout << "Quality   : " << quality << endl;
            cout << "Available : " << meter << endl;
            cout << "Alloted   : " << used << endl;
            cout << "Date      : " << date << endl;
        }
    }

    void allotStock() {
        if (quality.empty()) {
            cout << "No stock to allot!\n";
            return;
        }

        float temp;
        cout << "Enter meter to allot: ";
        cin >> temp;

        if (temp > meter) {
            cout << "Not enough stock!\n";
        } else {
            meter -= temp;
            used += temp;
            cout << "Stock allotted successfully!\n";
        }
    }
};
} // namespace end

int main() {
    company::ERP e1;   
    e1.menu();
    return 0;
}
