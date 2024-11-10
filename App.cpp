#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Management.cpp"
using namespace std;

class App
{
    Management *M;

public:
    App() { M = new Management(); }
    ~App() { delete M; }
    void Menu(){
        while (true){
            cout << endl;
            int width = 50;
            string separator(width, '-');
            cout << separator << endl;
            cout << right;
            cout << setw(27) << "Menu" << endl;
            cout << setw(23) << "0. Exit" << endl;
            cout << setw(30) << "1. Add Student" << endl;
            cout << setw(33) << "2. Delete Student" << endl;
            cout << setw(31) << "3. Find Student" << endl;
            cout << setw(23) << "4. Edit" << endl;
            cout << setw(31) << "5. List Student" << endl;
            cout << "\nYour Choice: ";
            int choice; cin >> choice;
            switch (choice){
            case 0:{
                cout << "Exit Menu Has Been Completed";
                return;
            }
            case 1:{
                cout << setw(28) << "Add Student" << endl;
                Student s; cin >> s;
                bool find = false;
                for (auto &m : M->getVector()){
                    if (m.getStuCode() == s.getStuCode()){
                        cout << setw(50) << "\n!!! Student with code " << s.getStuCode() << " allready exists!!!" << endl;
                        M->Find(s.getStuCode());
                        cout << right << setw(33) << "!!! Try Again !!!";
                        find = true;
                        break;
                    }
                }
                if (find) break;
                M->Add_Student(s);
                break;
            }
            case 2:{
                cout << setw(28) << "Delete Student" << endl;
                cout << "Enter Student Code: ";
                int x; cin >> x;
                auto find = M->Find(x);
                if (find != (M->getVector()).end()){
                    cout << "Confirm deletion (Y/N): ";
                    char C; cin >> C;
                    while (C != 'Y' && C != 'N'){
                        cout << "Try Again!!!\n";
                        cout << "Enter your choice Y or N : ";
                        cin >> C;
                    }
                    if (C == 'Y'){
                        M->Del_Student(find);
                        cout << "Student with code " << x << " has been deleted.\n";
                    }
                }
                break;
            }
            case 3:{
                cout << setw(29) << "Find Student" << endl;
                cout << "Enter Student Code: ";
                int X; cin >> X;
                M->Find(X);
                break;
            }
            case 4:{
                cout << setw(29) << "Edit Student" << endl;
                cout << "Enter Student Code: ";
                int X; cin >> X;
                auto find = M->Find(X);
                if (find == (M->getVector()).end()) break;
                bool edit = true;
                while (edit){
                    cout << endl;
                    cout << right;
                    cout << setw(50) << "Choose your choice to edit information: \n";
                    cout << " 0. Exit" << endl;
                    cout << " 1. Name" << endl;
                    cout << " 2. Student code " << endl;
                    cout << " 3. Day of birth " << endl;
                    cout << " 4. Month of birth" << endl;
                    cout << " 5. Year of birth" << endl;
                    cout << " 6. Class" << endl;
                    cout << " 7. Literature Score " << endl;
                    cout << " 8. Math Score " << endl;
                    cout << " 9. English Score " << endl;
                    cout << "\nYour Choice: ";
                    int ch; cin >> ch;
                    switch (ch){
                    case 0:{
                        cout << "Exit Edit Information Student\n";
                        edit = false;
                        break;
                    }
                    case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:{
                        M->Edit(ch, find);
                        break;
                    }
                    default:{
                        cout << "Invalid choice! Please select an option from 0 to 9\n";
                        break;
                    }
                    }
                }
                break;
            }
            case 5:{
                cout << setw(50) << "Student List" << endl;
                M->Arrange();
                M->Print();
            }
            }
        }
    }
};

int main()
{
    App Menu;
    Menu.Menu();
}
