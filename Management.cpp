#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "Student.cpp"
using namespace std;

class Management
{
    vector<Student> Vec_Student;

public:
    Management() {}
    vector<Student> &getVector(){ return Vec_Student; }
    void Add_Student(const Student &s){
        Vec_Student.push_back(s);
    }
    void Del_Student(vector<Student>::iterator f){
        Vec_Student.erase(f);
    }
    vector<Student>::iterator Find(int X){
        for (auto it = Vec_Student.begin(); it != Vec_Student.end(); ++it){
            if (it->getStuCode() == X){
                cout << "Student information with code " << X << endl
                     << endl;
                cout << *it;
                return it;
            }
        }
        cout << "Study With Code \"" << X << "\" Not Found.\n ";
        return Vec_Student.end();
    }
    void Edit(int x, vector<Student>::iterator f){
        if (f != Vec_Student.end()){
            switch (x){
            case 1:{
                cout << "Enter new name: ";
                string newN;
                cin.ignore();
                getline(cin, newN);
                newN = f->upperName(newN);
                f->setName(newN);
                cout << right << setw(20) << "Edit Succesfull\n";
                break;
            }
            case 2:{
                cout << "Enter new Student Code : ";
                int newSc;
                cin >> newSc;
                f->setScode(newSc);
                cout << right << setw(20) << "Edit Succesfull\n";
                break;
            }
            case 3:{
                cout << "Enter new day of birth: ";
                int newD;
                cin >> newD;
                f->setDay(newD);
                cout << right << setw(20) << "Edit Succesfull\n";
                break;
            }
            case 4:{
                cout << "Enter new month of birth: ";
                int newM;
                cin >> newM;
                f->setMonth(newM);
                cout << right << setw(20) << "Edit Succesfull\n";
                break;
            }
            case 5:{
                cout << "Enter new year of birth: ";
                int newY;
                cin >> newY;
                f->setYear(newY);
                cout << right << setw(20) << "Edit Succesfull\n";
                break;
            }
            case 6:{
                cout << "Enter new class: ";
                string newCl;
                cin.ignore();
                getline(cin, newCl);
                f->setClass(newCl);
                cout << right << setw(20) << "Edit Succesfull\n";
                break;
            }
            case 7:{
                cout << "Enter new Literature Score: ";
                float newL;
                cin >> newL;
                f->setLiterature(newL);
                cout << right << setw(20) << "Edit Succesfull\n";
                break;
            }
            case 8:{
                cout << "Enter new Math Score: ";
                float newMt;
                cin >> newMt;
                f->setMath(newMt);
                cout << right << setw(20) << "Edit Succesfull\n";
                break;
            }
            case 9:{
                cout << "Enter new English Score: ";
                float newE;
                cin >> newE;
                f->setEnglish(newE);
                cout << right << setw(20) << "Edit Succesfull\n";
                break;
            }
            }
        }
    }
    void Arrange(){
        sort(Vec_Student.begin(), Vec_Student.end(), [this](Student &a, Student &b)
             { return a.Average_Score() > b.Average_Score(); });
    }
    void Print(){
        cout << left << setw(20) << "Full name"
             << setw(20) << "Student Code"
             << setw(20) << "Date of Birth"
             << setw(10) << "Class"
             << setw(15) << "Literature"
             << setw(10) << "Math"
             << setw(10) << "English"
             << setw(10) << "Avarage_Score" << endl;

        for (auto &s : Vec_Student){
            cout << left << setw(20) << s.getName()
                 << setw(20) << s.getStuCode()
                 << (s.getDate())[0] << "\\" << (s.getDate())[1] << "\\" << setw(14 + (s.getDate()[0] > 10 ? 0 : 1) + (s.getDate()[1] > 10 ? 0 : 1)) << (s.getDate())[2]
                 << setw(10) << s.getClass()
                 << setw(15) << (s.getScore())[0]
                 << setw(10) << (s.getScore())[1]
                 << setw(10) << (s.getScore())[2]
                 << setw(10) << setprecision(2) << s.Average_Score() << endl;
        }
    }
};
