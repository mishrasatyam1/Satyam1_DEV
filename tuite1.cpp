#include<iostream>
#include<fstream>
using namespace std;

class temp{
    string username,Email, Password;
    string searchusername,searchEmail, searchPassword;
    fstream file;
    public:
    void Login();
    void Signup();
    void Forget();
}obj;

int main(){
    char choice;
    cout<<"\n1--Login"<<endl;
    cout<<"\n2--Signup"<<endl;
    cout<<"\n3--Forget password"<<endl;
    cout<<"\n4--Exit"<<endl;
    cout<<"\nEnter your choice";
    cin>>choice;
    switch(choice){
    case '1':
    obj.Login();
    break;

    case '2':
    obj.Signup();
     break;
    
    case '3':
    obj.Forget();
    break;
    
    case '4':
    return 0;
    break;
    default:
    cout<<"Invalid selection";

}
}
void temp:: Signup(){
    cout<<"Enter your username :: "<<endl;
    getline(cin,username);
    cout<<"Enter your Email :: "<<endl;
    getline(cin,Email);
    cout<<"Enter your Password:: "<<endl;
    getline(cin,Password);

    file.open("LoginData.txt", ios::out | ios::app);
    file<<username<<"*"<<Email<<"*"<<Password<<endl;
    file.close();
}
void temp::Login(){
    string searchName,searchPass;
    cout<<"-----------Login------"<<endl;
    cout<<"Enter your username ::"<<endl;
    getline(cin,searchName);
    cout<<"enter your Passeword ::"<<endl;
    getline(cin,searchPass);

    file.open("loginData.txt",ios::in);
    getline(file,username,'*');
    getline(file,Email,'*');
    getline(file,Password,'\n');
    while(!file.eof()){
        if(username==searchName){
            if(Password==searchPass){
                cout<<"\nAccount Login Sucessfull....!";
                cout<<"\nUsername ::"<<username<<endl;
                cout<<"\nEmail ::"<<Email<<endl;
            }else{
                cout<<"Password is wrong";
            }
        }
    getline(file,username,'*');
    getline(file,Email,'*');
    getline(file,Password,'\n');
    }
    file.close();
    
}
void temp :: Forget(){
    cout<<"Enter your username:: "<<endl;
    getline(cin,searchusername);
    cout<<"Enter your Password :: "<<endl;
    getline(cin,searchEmail);

    file.open("loginData.txt",ios::in);
    getline(file,username,'*');
    getline(file,Email,'*');
    getline(file,Password,'\n');
    while(!file.eof()){
        if(username==searchusername){
            if(Email==searchEmail){
                cout<<"\nAccount Found  !"<<endl;
                cout<<"your Password ::"<<Password<<endl;

            }else{
                cout<<"account not found";
            }
        }else{
            cout<<"\n Not found";
        }

    }
    file.close();
}