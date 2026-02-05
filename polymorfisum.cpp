// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

namespace xyz{
    
    class student{
        public:
        int s1,s2,s3,s4,s5;
        float sum;
         float grade;
         
        student(string name = "gaurav"){
             cout<<"enter marks for "<<"("<<name<<")"<<endl;
            cout<<"enter marks for s1 : ";
            cin>>s1;
              cout<<"enter marks for s2 : ";
            cin>>s2;
              cout<<"enter marks for s3 : ";
            cin>>s3;
              cout<<"enter marks for s4 : ";
            cin>>s4;
              cout<<"enter marks for s5 :  ";
            cin>>s5;
             
            
        }
        // void average(){
        //     sum = s1+s2+s3+s4+s5 ;
        //     cout<<"TOTAL SUM : "<<sum<<endl;
        //     persentage = sum /5.0;
        //      cout<<"PERSENTAGE : "<<persentage<<endl;
        // }

  };
  class persentage:public student{
      public:
       persentage(string name= "vedant"): student(name){
        //   cout<<"enter marks for "<<"("<<name<<")";
            sum = s1+s2+s3+s4+s5 ;
            cout<<"TOTAL SUM : "<<sum<<endl;
          grade = sum /5.0;
             cout<<"PERSENTAGE : "<<grade<<"%"<<endl;
        }
  
};
}
namespace polymorphisem{
    using namespace xyz;
    class functionoverloading : public persentage{
        public:
        functionoverloading(string name):persentage(name){}
        
        public:
        void sum(int d,int m,int y){
            cout<<" date :  "<<d<<"/"<<m<<"/"<<y<<endl;
        }
        void sum(string name){
            cout<<name<<endl;
        }
    };
}

int main() {
    // using namespace xyz;
    
    // persentage  obj("vedant");
    
   using namespace polymorphisem;
   functionoverloading s1("gaurav");
   s1.sum(6,2,2026);
   s1.sum("beast of luck for next exam");

}