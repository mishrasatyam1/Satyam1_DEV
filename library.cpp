#include<iostream>
#include<fstream>
using namespace std;
class temp{
    string id,name,author,search;
    fstream file;
    public:
    void addbooks();
    void showall();
    void ExtractBook();
}obj;
    int main(){
    char choice;
    cout<<"-----------------"<<endl;
    cout<<"1--show all the books"<<endl;
    cout<<"2--extractBook"<<endl;
    cout<<"3--Add the new book"<<endl;
    cout<<"exist"<<endl;
    cout<<"--------------------";
    cout<<"Enter your choice  ";
    cin>>choice;

    switch(choice){
        case '1':
        cin.ignore();
        obj.showall();
        break;
        case '2':
        cin.ignore();
        obj.ExtractBook();
        break;
        case '3':
        cin.ignore();
        obj.addbooks();
        break;
        case '4':
       return 0;
         break;
        default:
         cout<<"Invalid selection";

    }

}
void temp::addbooks(){
    cout<<"\n Enter Book Id :: ";
    getline(cin,id);
    cout<<"Enter book name :: ";
    getline(cin,name);
    cout<<"enter books author name :: ";
    getline(cin,author);
    file.open("bookData.txt",ios::out | ios::app);
    file<<id<<"*"<<name<<"*"<<author<<endl;
    file.close();
}
void temp::showall(){
    file.open("bookData.txt",ios::in);
    getline(file,id,'*');
    getline(file,name,'*');
    getline(file,author,'\n');
    cout<<"\n\n";
    cout<<"\t\t Book Id \t\t Book name \t\t Author name"<<endl;
    while(!file.eof()){
        cout<<"\t\t"<<id<<"\t\t"<<name<<"\t\t"<<author<<endl;
        getline(file,id,'*');
        getline(file,name,'*');
         getline(file,author,'\n');
        
    }
    file.close();
}
void temp::ExtractBook(){
    showall();
    cout<<"enter book id:: ";
    getline(cin,search);

    file.open(".txt",ios::in);
    getline(file,id,'*');
    getline(file,name,'*');
    getline(file,author,'\n');
    cout<<"\n\n";
    cout<<"\t\t Book Id \t\t Book name \t\t author name"<<endl;
    while(!file.eof()){
        if(search==id){
            cout<<"\t\t"<<id<<"\t\t"<<name<<"\t\t"<<author<<endl;
            cout<<"Book extract sucessfully----!";
        }
        getline(file,id,'*');
        getline(file,name,'*');
        getline(file,author,'\n');
    }
    file.close();
    
}