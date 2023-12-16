// Security System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

    int main()
{
    int a, i = 0;
    string text, old, password1, password2, pass, name, password0, age, user, word, word1;
    string creds[2], cp[2];

    cout << "     Security System     " << endl;
    cout << "_________________________" << endl;
    cout << "|     1. Register        |" << endl;
    cout << "|     2. Login           |" << endl;
    cout << "|     3. Change Password |" << endl;
    cout << "|     4. End Program     |" << endl;
    cout << "__________________________" << endl;

    do {
        cout << endl << endl;
        cout << "  Enter your choice :- ";
        cin >> a;
        switch (a)
        {
        case 1: {
            cout << "___________________"<<endl;
            cout << "|------register----|" << endl;
            cout << "___________________|" << endl;
            cout << "Please Enter User :-" << endl;
            cin >> name;
            cout << "Please Enter Your Password :-";
            cin >> password0;
            cout << "Age";
            cin >> age;

            ofstream pf1;
            pf1.open("file.txt");
            if (pf1.is_open())
            {
                pf1 << name;
                pf1 << password0;
                cout << "Registration Succesfull";

            }
            break;
        }
        case 2: {
            i = 0;
            cout << "__" << endl;
            cout << "login" << endl;
            cout << "__" << endl;

            ifstream of2;
            of2.open("file.text");
            cout << "Please enter the username:-";
            cin >> user;
            cout << "please enter the password:-";
                cin >> pass;

            if (of2.is_open()) {
                while (!of2.eof())
                {
                    while (getline(of2, text)) {
                        istringstream iss(text);
                        iss >> word;
                        creds[i] = word;
                        i++;
                    }

                    if (user == creds[0] &&pass == creds[1])
                    {
                        cout << "log in successfull";
                        cout << endl << endl;
                        cout << "details:"<<endl;
                        cout << "password:" + pass << endl;
                        cout << "age:+age" << endl;

                    }
                    else {
                        cout << "incorrect credentials";
                        cout << "press 2 to login";
                        cout << "press 3 to change password";
                        break;
                    }
                }
            }
            break;
        }
        case 3: {
            i = 0;
            cout << "-----------------change password--------------------";

            ifstream of0;
            of0.open("file.txt");
            cout << "enter the old password";
            cin >> old;
            if (of0.is_open())
            {
                while (of0.eof())
                {
                    while (getline(of0, text)) {
                        istringstream iss(text);
                        iss >> word1;
                        cp[i] = word1;
                        i++;
                    }
                    if (old == cp[1])
                    {
                        of0.close();
                        ofstream of1;
                        if (of1.is_open())
                        {
                            cout << "enter new pass";
                            cin >> password1;
                            cout << "enter password again";
                            cin >> password2;
                            if (password1 == password2)
                            {
                                of1 << cp[0] << " ";
                                of1 << password1;
                                cout << "pass change successfull";
                            }
                            else {
                                of1 << cp[0] << " ";
                                of1 << old;
                                cout << "pass doesn't match";
                            }
                        }
                    }
                    else {
                        cout << "please enter valid password";
                        break;
                    }
                }
            }break; }
        case 4:
              {cout << "--------------!!Thank You--------------";
              break;
              }
              default:
                  cout << "Enter a valid choice";
        }
    } while (a != 4);
    return 0;
}
