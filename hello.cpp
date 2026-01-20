#include<iostream>
#include<string.h>
using namespace std;
class student{
    int rollno;
    string name;
    int marks;
    public:
       void getdata(int a,string b,int c){
        rollno=a;
        name=b;
        marks=c;
       }
       void display();
};

void student:: display(){
    cout<<"roll no:"<<rollno<<"\n";
    cout<<"name:"<<name<<"\n";
    cout<<"marks:"<<marks<<"\n";
}

int main(){
 student S[3];
 int a,c;
 string b;
for(int i=0;i<3;i++){
    cout<<"enter roll no:";
    cin>>a;
    cout<<"enter name:";
    cin>>b;
    cout<<"enter marks:";
    cin>>c;
    S[i].getdata(a,b,c);
}

for(int i=0;i<3;i++){
    S[i].display();
}
return 0;
}