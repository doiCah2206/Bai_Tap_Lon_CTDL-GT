#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

class Student
{
    string Name;
    int Date[3];
    int Stu_Code;
    string Class;
    float Score[3];

public:
    Student(){
        Name = "";
        Date[0] = Date[1] = Date[2] = 0;
        Stu_Code = 0;
        Score[0] = Score[1] = Score[2] = 0;
        Class = "";
    }
    Student(string N, int *D, int Scd, float *S, string C){
        Name = N;
        Stu_Code = Scd;
        Class = C;
        for (int i = 0; i < 3; i++){
            Date[i] = D[i];
            Score[i] = S[i];
        }
    }
    string upperName(string N){
        for (int i = 0; i < N.length(); i++){
            if (i == 0 || (i > 0 && N[i - 1] == ' ')){
                if (N[i] >= 'a' && N[i] <= 'z'){
                    N[i] = N[i] - 32;
                }
            }
            else{
                if (N[i] >= 'A' && N[i] <= 'Z'){
                    N[i] = N[i] + 32;
                }
            }
        }
        return N;
    }
    friend istream &operator>>(istream &is, Student &s){
        cout << "Enter Full Name Student: ";
        is.ignore(); getline(is, s.Name);
        s.Name = s.upperName(s.getName());
        cout << "Enter Student Code: ";
        is >> s.Stu_Code;
        cout << "Enter Date Of Birth(dd mm yyyy): \n";
        cout << "  Day: ";
        is >> s.Date[0];
        cout << "  Month: ";
        is >> s.Date[1];
        cout << "  Year: ";
        is >> s.Date[2];
        cout << "Enter Class(Ex : 10A1): ";
        is.ignore(); getline(is, s.Class);
        cout << "Enter Scores(Literature,Math,English) \n";
        cout << "  Literature: ";
        is >> s.Score[0];
        cout << "  Math: ";
        is >> s.Score[1];
        cout << "  English: ";
        is >> s.Score[2];
        return is;
    }
    friend ostream &operator<<(ostream &os, Student &s){
        os << "Name: " << s.Name << endl
           << "Student Code: " << s.Stu_Code << endl
           << "Date of Birth: " << s.Date[0] << "/" << s.Date[1] << "/" << s.Date[2] << endl
           << "Class: " << s.Class << endl
           << "Scores:" << endl
           << "       Literature: " << s.Score[0] << endl
           << "       Math: " << s.Score[1] << endl
           << "       English: " << s.Score[2] << endl;
        return os;
    }
    double Average_Score(){
        double As = 0;
        for (int i = 0; i < 3; i++){
            As += Score[i];
        }
        return As / 3;
    }
    // getter
    string getName(){ return Name; }
    int getStuCode(){ return Stu_Code; }
    int *getDate(){ return Date; }
    string getClass(){ return Class; }
    float *getScore(){ return Score; }
    // setter
    void setName(string N){ Name = N; }
    void setScode(int Sc){ Stu_Code = Sc; }
    void setDay(int d){ Date[0] = d; }
    void setMonth(int m){ Date[1] = m; }
    void setYear(int y){ Date[2] = y; }
    void setClass(string C){ Class = C; }
    void setLiterature(float l){ Score[0] = l; }
    void setMath(float m){ Score[1] = m; }
    void setEnglish(float e){ Score[2] = e; }
};
