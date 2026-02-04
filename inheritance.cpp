#include <iostream>
using namespace std;

namespace student {

class gaurav {
public:
    string name ;
    int age;
     string course = "Full Stack";
    int c, cpp, html, css, js;

    
    gaurav(string n = "Gaurav") {
        name = n;
        age = 21;
        course = "Full Stack";

        cout << "Enter marks for " << name << endl << course << endl;
        
        c   = getMarks("C");
        cpp = getMarks("C++");
        html= getMarks("HTML");
        css = getMarks("CSS");
        js  = getMarks("JavaScript");

        int total = c + cpp + html + css + js;
        float average = total / 5.0;

        cout << "\nTotal Marks: " << total << endl;
        cout << "Average: " << average << endl;

        if (average >= 40)
            cout << "Status: PASS " << endl;
        else
            cout << "Status: FAIL " << endl;
            showatkt();
    }

    int getMarks(string subject) {
        int marks;
        while (true) {
            cout << "Enter marks of " << subject << " (0-100): ";
            cin >> marks;

            if (marks >= 0 && marks <= 100)
                return marks;
            else
                cout << "nvalid marks, try again\n";
        }
    }
   void showatkt() {
        // bool fail = false;

        // cout << "\nFailed Subjects:\n";

        if (c < 40) {
            cout << " ATKT in c  : "<<c<<endl;
            
        }
        if (cpp < 40) {
            cout << "ATKT in cpp :"<<cpp<<endl;
           
        }
        if (html < 40) {
            cout << "ATKT in html :"<<html<<endl;
           
        }
        if (css < 40) {
            cout << "ATKT in css :"<<css<<endl;
         
        }
        if (js < 40) {
            cout << "ATKT in javascript :"<<js<<endl;
       
        }

    
            
    }
};

class ruchit:public gaurav{
public:
ruchit():gaurav("ruchit"){
    
}
 
};

}

void p(int n){
    cout<<"Hello "<<n<<endl;
}




int main() {
    using namespace student;
    //  ruchit r1; 
     p(12);
    return 0;
}