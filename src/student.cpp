#include "Student.h"
#include <iomanip>
#include <cstring>
#include <fstream>
#include <algorithm>
using namespace std;

/*Constant Separator*/
const string Separator = string(67, '-');


// ! *****************************  Main Functions (CRUD) ***********************************
void Main_Menu(vector <stStudents> &students)
{
    system("color 0F");
    system("cls");
    Header('=', 67, 16, 16, "STUDENTS RECORDS MANAGEMENT SYSTEM");
    cout << "[1] Add New Student Record" << endl;
    cout << string(26, '-') << endl;
    cout << "[2] Show All Students" << endl;
    cout << string(21, '-') << endl;
    cout << "[3] Search in Students Records" << endl;
    cout << string(29, '-') << endl;
    cout << "[4] Update Student Record" << endl;
    cout << string(25, '-') << endl;
    cout << "[5] Delete Student Record" << endl;
    cout << string(25, '-') << endl;
    cout << "[6] Statistics & Reports" << endl;
    cout << string(24, '-') << endl;
    cout << "[7] Arrange Records" << endl;
    cout << string(19, '-') << endl;
    cout << "[8] Export to TXT File" << endl;
    cout << string(22, '-') << endl;
    cout << "[9] Import from TXT File" << endl;
    cout << string(24, '-') << endl;
    cout << "[10] Backup & Restore" << endl;
    cout << string(24, '-') << endl;
    cout << "[11] Exit" << endl;
    cout << string(67, '-') << endl;
    int choice = Verify_Integers("Please Enter Your Choice");    

    switch(choice)
    {
        case 1:
            Add_New_Student(students);
            break;
        case 2:
            Show_All_Students(students);
            break;
        case 3:
            Search_Student(students);
            break;
        case 4:
            Update_Student(students);
            break;
        case 5:
            Delete_Student(students);
            break;
        case 6:
            Statistics_And_Reports(students);
            break;
        case 7:
            Arrange_Students(students);
            break;
        case 8:
            Export_To_TXT_File(students, '-');
            break;
        case 9:
            Import_From_TXT_File(students, '-');
            break;
        case 10:
            Backup_And_Restore(students);
            break;
        default:
            break;
    }   
}
void Add_New_Student(vector <stStudents> &students)
{
    system("cls");
    Header('=', 67, 25, 26, "ADD NEW Record");  

    stStudents student;
    student.RollNumber = get_next_roll(students);
    strcpy_s(student.First_Name, Verify_Name("Please Enter First Name").c_str());
    strcpy_s(student.Last_Name, Verify_Name("Please Enter Last Name").c_str());
    strcpy_s(student.Department, Verify_Department("Please Enter Department").c_str());
    student.Semester = Verify_Semester("Please Enter Semester", "ADD NEW Record");
    student.cGPA = Verify_cGPA("Please Enter cGPA", "ADD NEW Record");
    strcpy_s(student.Date_of_Birth, Verify_Date("Please Enter Date of Birth").c_str());
    strcpy_s(student.Phone_Number, Verify_Phone("Please Enter Phone Number", "ADD NEW Record").c_str());
    strcpy_s(student.Email, Verify_Email("Please Enter Email", "ADD NEW Record").c_str());
    student.Is_Active = Verify_Is_Active("Please Enter Student Status", "ADD NEW Record");

    system("color 20");
    students.push_back(student);
    Export_To_Binary(students);
    Message(students, "Student Added Successfully");
}
void Show_All_Students(vector <stStudents> &students)
{
    if(students.empty())
    {
        system("color 40");
        system("cls");
        Header('=', 67, 23, 25, "Show All Students"); 
        Message(students, "NO Students Found");
    }
    else
    {
        system("color 60");
        int Page_Size = 10;
        int Total_Students = students.size();
        int Total_Pages = (Total_Students + Page_Size - 1) / Page_Size;
        int Current_Page = 0; 
        char op = ' ';
        while(true)
        {
            system("cls"); 
            Header('=', 106, 38, 38, "Show All Students (Page " + to_string(Current_Page + 1) + "/" + to_string(Total_Pages) + ")"); 
            cout << left << setw(4) << "N" << setw(8) << "R.NUM" << setw(20) << "Student Name" << setw(6) << "DEP" << setw(7) << "Sem" << setw(7) << "GPA" << setw(12) << "DOB" << setw(13) << "PhoneNumber" <<  setw(22) << "Email" << setw(9) << "Status" << endl;
            cout << string(106, '=') << endl;
            int start = Current_Page * Page_Size;
            int end = min(start + Page_Size, Total_Students);
    
            for (int i = start; i < end; i++)
            {
                cout << left << setw(4) << i+1 << setw(8) << students[i].RollNumber << setw(20) << string(students[i].First_Name) + ' ' + string(students[i].Last_Name) << setw(6) << students[i].Department << setw(7) << students[i].Semester << setw(7) << fixed << setprecision(2) << students[i].cGPA << setw(12) << students[i].Date_of_Birth << setw(13) << students[i].Phone_Number <<  setw(22) << students[i].Email << setw(9) << Print_Boolean_as_String(students[i].Is_Active) << endl;
            }

            cout << string(106, '=') << endl;
            cout << "Please Enter your choice" << endl;
            cout << Separator << endl;
            cout << "[N] Next Page" << endl;
            cout << "[P] Previous Page" << endl;
            cout << "[M] Main Menu" << endl;
            cout << "[E] Exit" << endl;
            cout <<  Separator << endl;
            cout << ">> ";
            cin >> op;

            if (tolower(op) == 'n' && Current_Page < Total_Pages - 1) 
            {
                Current_Page++;
            }
            else if (tolower(op) == 'p' && Current_Page > 0) 
            {
                Current_Page--;
            }
            else if (tolower(op) == 'm') 
            {
                Main_Menu(students);
            }
            else if (tolower(op) == 'e') 
            {
                break;   
            }
        }            
    }
}
void Search_Student(vector <stStudents> &students)
{
    if(students.empty())
    {
        system("color 40");
        system("cls");
        Header('=', 67, 21, 23, "Search Student Record"); 
        Message(students, "NO Students Found");
    }
    else
    {
        system("cls");
        Header('=', 67, 21, 23, "Search Student Record"); 
        cout << "[1] Search BY Roll Number" << endl;
        cout << string(25, '-') << endl;
        cout << "[2] Search BY Name" << endl;
        cout << string(18, '-') << endl;
        cout << "[3] Search BY Department" << endl;
        cout << string(24, '-') << endl;
        cout << "[4] Search BY cGPA" << endl;
        cout << string(19, '-') << endl;
        cout << "[Any Key] Return to Main Menu" << endl;
        cout << string(67, '-') << endl;
        int choice = Verify_Integers("Please Enter Your Choice");  
        bool found = false;
        int Search_Roll;
        string Search;
        float Search_cGPA;

        switch(choice)
        {
            case 1:
                system("cls");
                Header('=', 106, 41, 42, "Search BY Roll Number"); 
                Search_Roll = Verify_Integers("Please Enter a number to search");

                for(stStudents &s : students)
                {
                    if(Search_Roll == s.RollNumber)
                    {
                        system("color 20");
                        Print_Student_Header();
                        Print_Student_Row(s);
                        found = true;
                    }
                }
                break;
            case 2:
                system("cls");
                Header('=', 106, 45, 45, "Search BY Name"); 
                cout << "Please Enter a Name to search" << endl;
                cout << ">> ";
                cin >> Search;
                Print_Student_Header();
                for(stStudents &s : students)
                {
                    if(Convert_To_Lower(Search) == Convert_To_Lower(s.First_Name))
                    {
                        system("color 20");
                        Print_Student_Row(s);
                        found = true;
                    }
                }
                break;
            case 3:
                system("cls");
                Header('=', 106, 42, 42, "Search BY Department"); 
                cout << "Please Enter a Department to search" << endl;
                cout << ">> ";
                cin >> Search;
                Print_Student_Header();
                for(stStudents &s : students)
                {
                    if(Search == s.Department)
                    {
                        system("color 20");
                        Print_Student_Row(s);
                        found = true;
                    }
                }
                break;
            case 4:
                system("cls");
                Header('=', 106, 45, 45, "Search BY cGPA"); 
                Search_cGPA = Verify_Integers("Please Enter a cGPA to search");
                Print_Student_Header();
                for(stStudents &s : students)
                {
                    if(Search_cGPA == s.cGPA)
                    {
                        system("color 20");
                        Print_Student_Row(s);
                        found = true;
                    }
                }
                break;
            default:
                Main_Menu(students);
        }  
        if(!found)
        {
            system("color 40");
            Message(students, "Student Not Found");
        }
        else
        {
            Message(students, "Search Done Successfully");
        }
    }
}
void Update_Student(vector <stStudents> &students)
{
    if(students.empty())
    {
        system("color 40");
        system("cls");
        Header('=', 67, 25, 26, "Update Student"); 
        Message(students, "NO Students Found");
    }
    else
    {
        system("cls");
        Header('=', 67, 25, 26, "Update Student"); 
        int Search_roll = Verify_Integers("Please Enter Student ID to Update");
        int index = Find_Student(students, to_string(Search_roll));
        char confirm;

        if(index != -1)
        {
            system("color 20");
            Print_Student_Header();
            Print_Student_Row(students[index]);
            cout << Separator << endl;
            cout << "What Do You Want To Edit? " << endl;
            cout << "[1] Semester" << endl;
            cout << "[2] cGPA" << endl;
            cout << "[3] Phone Number" << endl;
            cout << "[4] Email" << endl;
            cout << "[5] Status" << endl;
            cout << Separator << endl;
            int choice = Verify_Integers("Please Enter Your Choice");

            int New_Semester;
            float New_cGPA;
            string New_Phone, New_Email;
            bool New_Status;

            switch(choice)
            {
                case 1:
                    New_Semester = Verify_Semester("Please Enter New Semester","Update Student");
                    Confirm_Message("Update");
                    cin >> confirm;
                    if(confirm == 'Y' || confirm == 'y')
                    {
                        students[index].Semester = New_Semester;
                    }
                    break;
                case 2:
                    New_cGPA = Verify_cGPA("Please Enter New cGPA", "Update Student");
                    Confirm_Message("Update");
                    cin >> confirm;
                    if(confirm == 'Y' || confirm == 'y')
                    {
                        students[index].cGPA = New_cGPA;
                    }
                    break;
                case 3:
                    New_Phone = Verify_Phone("Please Enter New Phone", "Update Student");
                    Confirm_Message("Update");
                    cin >> confirm;
                    if(confirm == 'Y' || confirm == 'y')
                    {
                        strcpy_s(students[index].Phone_Number, New_Phone.c_str());
                    }
                    break;
                case 4:
                    New_Email = Verify_Email("Please Enter New Email", "Update Student");
                    Confirm_Message("Update");
                    cin >> confirm;
                    if(confirm == 'Y' || confirm == 'y')
                    {
                        strcpy_s(students[index].Email, New_Email.c_str());
                    }
                    break;
                case 5:
                    New_Status = Verify_Is_Active("Please Enter New Status", "Update Student");
                    Confirm_Message("Update");
                    cin >> confirm;
                    if(confirm == 'Y' || confirm == 'y')
                    {
                        students[index].Is_Active = New_Status;
                    }
                    break;
                default:
                    Main_Menu(students);
                    break;
            }

        }

        if(confirm != 'y' || confirm != 'Y')
        {
            system("color 60");
            Message(students, "Canceled Operation");
        }
        if(index == -1)
        {
            system("color 40");
            Message(students, "Student Not Found");
        }
        system("color 20");
        Export_To_Binary(students);
        Message(students, "Student Updated Successfully");  
    }
}
void Delete_Student(vector <stStudents> &students)
{
    if(students.empty())
    {
        system("color 40");
        system("cls");
        Header('=', 67, 25, 26, "Update Student"); 
        Message(students, "NO Students Found");
    }
    else
    {
        system("cls");
        Header('=', 67, 25, 26, "Delete Student"); 
        string Delete_Student;
        cout << "Please Enter Student Roll Number OR Name To Delete" << endl;
        cout << ">> ";
        Clear_Buffer();
        getline(cin, Delete_Student);
        Convert_To_Lower(Delete_Student);
        int index = Find_Student(students, Delete_Student);
        if(index != -1)
        {
            system("color 20");
            Print_Student_Header();
            Print_Student_Row(students[index]);
            cout << Separator << endl;
            cout << "Please Enter Deletion Type" << endl;
            cout << Separator << endl;
            cout << "[1] Logical Delete" << endl;
            cout << "[2] Actual Delete" << endl;
            cout << "[Any Number] Return To Main Menu" << endl;
            cout << Separator << endl;
            int choice = Verify_Integers("Please Enter Your Choice");

            switch(choice)
            {
                case 1:
                    system("color 20");
                    students[index].Is_Active = false;
                    Export_To_Binary(students);
                    Message(students, "Record Deleted Successfully (Logical)");        
                    break;  
                case 2:
                    system("color 20");
                    students.erase(students.begin() + index);
                    Export_To_Binary(students);
                    Message(students, "Record Deleted Successfully (Actual)");        
                    break;
                default:
                    Main_Menu(students);
                    break;

            }
        }
        if(index == -1)
        {
            system("color 40");
            Message(students, "Student Not Found");
        }
    }    
}
void Statistics_And_Reports(vector <stStudents> &students)
{
    if(students.empty())
    {
        system("color 40");
        system("cls");
        Header('=', 67, 21, 22, "Statistics And Reports"); 
        Message(students, "NOT Enough Data To Display");
    }
    else
    {
        system("color 60");
        system("cls");
        Header('=', 67, 21, 22, "Statistics And Reports"); 

        // ******************* Geneal Statistics ********************* //
        cout << Separator << endl;
        cout << "\t\t\tGeneral Statistics" << endl;
        cout << Separator << endl;
        int Active = 0, InActive = 0;
        for(stStudents &s : students)
        {
            if(s.Is_Active)
                Active++;
            else
                InActive++;
        }
        cout << " - Total Students : " << students.size() << endl;
        cout << " - Active Students : " << Active << endl;
        cout << " - InActive Students : " << InActive << endl;

        // ****************** Students According to Department ********************* //
        cout << Separator << endl;
        cout << "\t\tStudents According to Department" << endl;
        cout << Separator << endl;
        int CS = 0, ME = 0, EE = 0, IT = 0, CE = 0;
        for(stStudents &s : students)
        {
            if(strcmp(s.Department, "IT") == 0)
                IT++;
            else if(strcmp(s.Department, "ME") == 0)
                ME++; 
            else if(strcmp(s.Department, "CS") == 0)
                CS++;
            else if(strcmp(s.Department, "EE") == 0)
                EE++;
            else if(strcmp(s.Department, "CE") == 0)
                CE++;
        }
        cout << " - Information Technology [IT] : " << IT << endl;
        cout << " - Computer Science       [CS] : " << CS << endl;
        cout << " - Mechanical Engineering [ME] : " << ME << endl;
        cout << " - Electrical Engineering [EE] : " << EE << endl;
        cout << " - Civil Engineering      [CE] : " << CE << endl;
        
        // ****************** Students According to cGPA ********************* //
        cout << Separator << endl;
        cout << "\t\t\tStudents According to cGPA" << endl;
        cout << Separator << endl;
        int Excellent = 0, Very_Good = 0, Good = 0, Accepted = 0;
        for(stStudents &s : students)
        {
            if(s.cGPA >= 3.5 && s.cGPA <= 4.0)
                Excellent++;
            else if(s.cGPA >= 3.0 && s.cGPA <= 3.49)
                Very_Good++; 
            else if(s.cGPA >= 2.5 && s.cGPA <= 2.99)
                Good++;
            else if(s.cGPA < 2.5)
                Accepted++;
        }
        cout << " - [3.5 - 4.0] Excellent  : " << Excellent << endl;
        cout << " - [3.0 - 3.49] Very GOOD : " << Very_Good << endl;
        cout << " - [2.5 - 2.99] GOOD      : " << Good << endl;
        cout << " - [< 2.5] Accepted       : " << Accepted << endl;

        // ****************** Students According to Semester ********************* //
        cout << Separator << endl;
        cout << "\t\t\tStudents According to Semester" << endl;
        cout << Separator << endl;
        int Sem1 = 0, Sem2 = 0, Sem3 = 0, Sem4 = 0, Sem5 = 0, Sem6 = 0, Sem7 = 0, Sem8 = 0;
        for(stStudents &s : students)
        {
            if(s.Semester == 1)
                Sem1++;
            else if(s.Semester == 2)
                Sem2++; 
            else if(s.Semester == 3)
                Sem3++;
            else if(s.Semester == 4)
                Sem4++;
            else if(s.Semester == 5)
                Sem5++;
            else if(s.Semester == 6)
                Sem6++;
            else if(s.Semester == 7)
                Sem7++;
            else if(s.Semester == 8)
                Sem8++;
        }
        cout << " - Semester [1]  : " << Sem1 << endl;
        cout << " - Semester [2]  : " << Sem2 << endl;
        cout << " - Semester [3]  : " << Sem3 << endl;
        cout << " - Semester [4]  : " << Sem4 << endl;
        cout << " - Semester [5]  : " << Sem5 << endl;
        cout << " - Semester [6]  : " << Sem6 << endl;
        cout << " - Semester [7]  : " << Sem7 << endl;
        cout << " - Semester [8]  : " << Sem8 << endl;

        Message(students, "End of Report");
    }
}
void Arrange_Students(vector <stStudents> &students)
{
    if(students.empty())
    {
        system("color 40");
        system("cls");
        Header('=', 67, 24, 26, "Arrange Records"); 
        Message(students, "NOT Enough Data to Arrange");
    }
    else
    {
        system("cls");
        Header('=', 67, 24, 26, "Arrange Records"); 
        cout << "[1] Arrange According to Roll Number [Ascending]" << endl;
        cout << string(48, '-') << endl;
        cout << "[2] Arrange According to Roll Number [Descending]" << endl;
        cout << string(48, '-') << endl;
        cout << "[3] Arrange According to Name [A-Z]" << endl;
        cout << string(44, '-') << endl;
        cout << "[4] Arrange According to cGPA [Descending]" << endl;
        cout << string(41, '-') << endl;
        cout << "[5] Arrange According to Semester [Ascending]" << endl;
        cout << string(44, '-') << endl;
        cout << "[Any Key] Return to Main Menu" << endl;
        cout << string(67, '-') << endl;
        int choice = Verify_Integers("Please Enter Your Choice");  
        char confirm;

        switch(choice)
        {
            case 1:
                system("cls");
                Header('=', 67, 11, 10, "Arrange According to Roll Number [Ascending]"); 
                Confirm_Message("Arrange");
                cin >> confirm;
                if(confirm == 'Y' || confirm == 'y')
                {
                    system("color 20");
                    sort(students.begin(), students.end(), Compare_Roll_Ascending);
                    Export_To_Binary(students);
                }
                break;
            case 2:
                system("cls");
                Header('=', 67, 11, 10, "Arrange According to Roll Number [Descending]"); 
                Confirm_Message("Arrange");
                cin >> confirm;
                if(confirm == 'Y' || confirm == 'y')
                {
                    system("color 20");
                    sort(students.begin(), students.end(), Compare_Roll_Descending);
                    Export_To_Binary(students);
                }
                break;
            case 3:
                system("cls");
                Header('=', 67, 17, 17, "Arrange According to Name [A-Z]"); 
                Confirm_Message("Arrange");
                cin >> confirm;
                if(confirm == 'Y' || confirm == 'y')
                {
                    system("color 20");
                    sort(students.begin(), students.end(), Compare_Name);
                    Export_To_Binary(students);
                }
                break;
            case 4:
                system("cls");
                Header('=', 67, 14, 14, "Arrange According to cGPA [Descending]"); 
                Confirm_Message("Arrange");
                cin >> confirm;
                if(confirm == 'Y' || confirm == 'y')
                {
                    system("color 20");
                    sort(students.begin(), students.end(), Compare_cGPA);
                    Export_To_Binary(students);
                }
                break;
            case 5:
                system("cls");
                Header('=', 67, 12, 12, "Arrange According to Semester [Ascending]"); 
                Confirm_Message("Arrange");
                cin >> confirm;
                if(confirm == 'Y' || confirm == 'y')
                {
                    system("color 20");
                    sort(students.begin(), students.end(), Compare_Semester_Ascending);
                    Export_To_Binary(students);
                }
                break;
            default:
                Main_Menu(students);
        } 

        if(confirm != 'y' || confirm != 'Y')
        {
            system("color 60");
            Message(students, "Canceled Operation");
        } 
        Message(students, "Arrange Done Successfully");
    }
}
void Export_To_TXT_File(vector <stStudents> &students, char delimiter)
{
    if(students.empty())
    {
        system("color 40");
        system("cls");
        Header('=', 67, 23, 24, "Export To TXT File"); 
        Message(students, "NOT Enough Data to Export");
    }    
    else
    {
        system("cls");
        Header('=', 67, 23, 24, "Export To TXT File"); 
        Confirm_Message("Export To txt File");
        char confirm;
        cin >> confirm;
        if(confirm == 'Y' || confirm == 'y')
        {
            system("color 20");
            ofstream txt_export("Student Management System/Student.txt");
            if(txt_export.is_open())
            {
                for(stStudents &s : students)
                {
                    txt_export << s.RollNumber << delimiter << s.First_Name << delimiter << s.Last_Name << delimiter << s.Department << delimiter << s.Semester << delimiter << s.cGPA << delimiter << s.Date_of_Birth << delimiter << s.Phone_Number << delimiter << s.Email << delimiter << s.Is_Active << endl;
                }
                txt_export.close();
            }
        }
        else
        {
            system("color 60");
            Message(students, "Canceled Operation");
        }

        Message(students, "Exported Successfully");
    }
}
void Import_From_TXT_File(vector <stStudents> &students, char delimiter)
{
        system("cls");
        Header('=', 67, 22, 23, "Import From TXT File"); 
        Confirm_Message("Import From txt File");
        char confirm;
        cin >> confirm;
        if(confirm == 'Y' || confirm == 'y')
        {
            system("color 20");
            ifstream txt_import("Student Management System/Student.txt");
            if(txt_import.is_open())
            {
                
                string Line;
                while(getline(txt_import, Line))
                {
                    stringstream ss(Line);
                    stStudents s;

                    string roll, semester, cGPA, firstname, lastname, department, phone, email, date, isActive;

                    getline(ss, roll, delimiter);
                    s.RollNumber = stoi(roll);
                    getline(ss, firstname, delimiter);
                    strcpy_s(s.First_Name, firstname.c_str());
                    getline(ss, lastname, delimiter);
                    strcpy_s(s.Last_Name, lastname.c_str());
                    getline(ss, department, delimiter);
                    strcpy_s(s.Department, department.c_str());
                    getline(ss, semester, delimiter);
                    s.Semester = stoi(semester);
                    getline(ss, cGPA, delimiter);
                    s.cGPA = stoi(cGPA);
                    getline(ss, date, delimiter);
                    strcpy_s(s.Date_of_Birth, date.c_str());
                    getline(ss, phone, delimiter);
                    strcpy_s(s.Phone_Number, phone.c_str());
                    getline(ss, email, delimiter);
                    strcpy_s(s.Email, email.c_str());
                    getline(ss, isActive, delimiter);
                    s.Is_Active = stoi(isActive);

                    if(!Exist_Student(students, s.RollNumber))
                    {
                        students.push_back(s);
                    }

                }
                Export_To_Binary(students);
                txt_import.close();
            }
            Message(students, "Imported Done Successfully");
        }
        else
        {
            system("color 60");
            Message(students, "Canceled Operation");
        }   
        
}
void Backup_And_Restore(vector <stStudents> &students)
{
    system("cls");
    Header('=', 67, 23, 24, "Backup And Restore"); 
    cout << "[1] Backup All Data" << endl;
    cout << string(48, '-') << endl;
    cout << "[2] Restore All Data" << endl;
    cout << string(48, '-') << endl;
    cout << "[Any Key] Return to Main Menu" << endl;
    cout << string(67, '-') << endl;
    int choice = Verify_Integers("Please Enter Your Choice");  
   
    switch(choice)
    {
        case 1:
            if(students.empty())
            {
                system("color 40");
                system("cls");
                Header('=', 67, 24, 26, "Backup All Data"); 
                Message(students, "NOT Enough Data to Backup");
            }    
            else   
            {
                system("cls");
                Header('=', 67, 24, 26, "Backup All Data"); 
                cout << "Are You Sure You Want to Backup All Data?" << endl;
                cout << Separator << endl;
                cout << "[Y] Yes" << endl;
                cout << "[Any Key] No" << endl;
                cout << Separator << endl;
                cout << ">> ";
                char confirm;
                cin >> confirm;
                if(confirm == 'Y' || confirm == 'y')
                {
                    system("color 20");
                    Export_To_Binary(students);
                    Message(students, "Backup Done Successfully");
                }
                else
                {
                    system("color 60");
                    Message(students, "Canceled Operation");
                }   
            }
            break;
        case 2:
                system("cls");
                Header('=', 67, 24, 25, "Restore All Data"); 
                cout << "Are You Sure You Want to Restore All Data?" << endl;
                cout << Separator << endl;
                cout << "[Y] Yes" << endl;
                cout << "[Any Key] No" << endl;
                cout << Separator << endl;
                cout << ">> ";
                char confirm;
                cin >> confirm;
                if(confirm == 'Y' || confirm == 'y')
                {
                    system("color 20");
                    students = Import_From_Binary_File();
                    Message(students, "Restore Done Successfully");
                }
                else
                {
                    system("color 60");
                    Message(students, "Canceled Operation");
                }   
            break;
        default:
                Main_Menu(students);
                break;
    }
}
// ! *************************  Reading & Verifying Fuctions ********************************
int Verify_Integers(string message)
{
    int number;
    cout << message << endl;
    cout << ">> ";
    cin >> number;
    while(true)
    {
        if(cin.fail())
        {
            system("color 40");
            Clear_Buffer();
            cout << Separator << endl;
            cout << "Invalid Character, Please Re-Enter A Valid Value" << endl;
            cout << Separator << endl;
            cout << ">> ";
            cin >> number;
        }
        else if(number < 0)
        {
            system("color 40");
            cout << Separator << endl;
            cout << "Invalid Value, Value Must be > 0" << endl;
            cout << Separator << endl;
            cout << ">> ";
            cin >> number;
        }
        else
        {
            break;
        }
    }
    system("color 0f");
    return number;
}
int Verify_Roll_Number(vector <stStudents> &students, string message)
{
    int roll;
    cout << message << endl;
    cout << ">> ";
    cin >> roll;
    while(true)
    {
        if(cin.fail())
        {
            system("color 40");
            Clear_Buffer();
            cout << Separator << endl;
            cout << "Invalid Character, Please Re-Enter A Valid Value" << endl;
            cout << Separator << endl;
            cout << ">> ";
            cin >> roll;
        }
        else if(roll < 0)
        {
            system("color 40");
            cout << Separator << endl;
            cout << "Invalid Value, Value Must be > 0" << endl;
            cout << Separator << endl;
            cout << ">> ";
            cin >> roll;
        }
        else if(Check_if_Exist(students, roll))
        {
            system("color 40");
            cout << Separator << endl;
            cout << "Already Exist, Please Enter Another" << endl;
            cout << Separator << endl;
            cout << ">> ";
            cin >> roll;
        }
        else
        {
            break;
        }
    }
    system("color 0f");
    return roll;
}
bool Check_if_Exist(vector <stStudents> &students, int roll)
{
    for(stStudents &s : students)
    {
        if(s.RollNumber == roll)
        {
            return true;
        }
    }
    return false;
}
string Verify_Name(string message)
{
    string name;
    cout << message << endl;
    cout << ">> ";
    cin >> name;
    while(Is_Digit(name))
    {
        system("cls");
        system("color 40");
        Header('=', 67, 25, 26, "ADD NEW Record");  
        cout << Separator << endl;
        cout << "Invalid Character, Must be letters only" << endl;
        cout << Separator << endl;
        cout << ">> ";    
        cin >> name;        
    }
    system("cls");
    Header('=', 67, 25, 26, "ADD NEW Record");  
    system("color 0f");
    return name;
}
bool Is_Digit(string txt)
{
    for(int i = 0; i < txt.length(); i++)
    {
        if(isdigit(txt[i]))
        {
            return true;
        }
    }
    return false;
}
string Verify_Department(string message)
{
    string department;
    cout << message << endl;
    cout << ">> ";
    cin >> department;
    while(department != "CS" && department != "IT" && department != "ME" && department != "EE" && department != "CE")
    {
        system("color 40");
        system("cls");
        Header('=', 67, 25, 26, "ADD NEW Record");  
        cout << Separator << endl;
        cout << "Invalid Department, Must be one of the following:" << endl;
        cout << "[IT] Information Technology" << endl;
        cout << "[CS] Computer Science" << endl;
        cout << "[CE] Civil Engineering" << endl;
        cout << "[ME] Mechanical Engineering" << endl;
        cout << "[EE] Electrical Engineering" << endl;
        cout << Separator << endl;
        cout << ">> ";    
        cin >> department;         
    }
    system("cls");
    Header('=', 67, 25, 26, "ADD NEW Record");  
    system("color 0f");
    return department;
}
int Verify_Semester(string message, string Title)
{
    int semester;
    cout << message << endl;
    cout << ">> ";
    cin >> semester;

    while(semester <= 0 || semester > 8)
    {
        system("color 40");
        system("cls");
        Header('=', 67, 25, 26, Title);  
        cout << Separator << endl;
        cout << "Invalid Value, Value Must be > 0 & <= 8" << endl;
        cout << Separator << endl;
        cout << ">> ";
        cin >> semester;      
    }
    system("cls");
    Header('=', 67, 25, 26, Title);  
    system("color 0f");
    return semester;
}
float Verify_cGPA(string message, string Title)
{
    float cGPA;
    cout << message << endl;
    cout << ">> ";
    cin >> cGPA;

    while(cGPA < 0.0 || cGPA > 4.0)
    {
        system("color 40");
        system("cls");
        Header('=', 67, 25, 26, Title); 
        cout << Separator << endl;
        cout << "Invalid Value, Value Must be >= 0.0 & <= 4.0" << endl;
        cout << Separator << endl;
        cout << ">> ";
        cin >> cGPA;      
    }
    system("cls");
    Header('=', 67, 25, 26, Title);  
    system("color 0f");
    return cGPA;
}
string Verify_Date(string message)
{
    int day = verify_Day("Please Enter Day of birth");
    int month = verify_Month("Please Enter Month of birth");
    int year = verify_Year("Please Enter Year of birth");

    string d = (day < 10 ? "0" : "") + to_string(day);
    string m = (month < 10 ? "0" : "") + to_string(month);

    return d + "/" + m + "/" + to_string(year);
}
int verify_Day(string message)
{
    int day;
    cout << message << endl;
    cout << ">> ";
    cin >> day;
    while(true)
    {
        if(cin.fail())
        {
            system("color 40");
            Clear_Buffer();
            system("cls");
            Header('=', 67, 25, 26, "ADD NEW Record");  
            cout << Separator << endl;
            cout << "Invalid Character, Please Re-Enter A Valid Value" << endl;
            cout << Separator << endl;
            cout << ">> ";
            cin >> day;
        }
        else if(day < 0 || day > 31)
        {
            system("color 40");
            system("cls");
            Header('=', 67, 25, 26, "ADD NEW Record"); 
            cout << Separator << endl;
            cout << "Invalid Value, Value Must be > 0 and <= 31" << endl;
            cout << Separator << endl;
            cout << ">> ";
            cin >> day;
        }
        else
        {
            break;
        }
    }
    system("cls");
    Header('=', 67, 25, 26, "ADD NEW Record");  
    system("color 0f");
    return day;    
}
int verify_Month(string message)
{
    int month;
    cout << message << endl;
    cout << ">> ";
    cin >> month;
    while(true)
    {
        if(cin.fail())
        {
            system("color 40");
            Clear_Buffer();
            system("cls");
            Header('=', 67, 25, 26, "ADD NEW Record"); 
            cout << Separator << endl;
            cout << "Invalid Character, Please Re-Enter A Valid Value" << endl;
            cout << Separator << endl;
            cout << ">> ";
            cin >> month;
        }
        else if(month < 0 || month > 12)
        {
            system("color 40");
            system("cls");
            Header('=', 67, 25, 26, "ADD NEW Record");  
            cout << Separator << endl;
            cout << "Invalid Value, Value Must be > 0 and <= 12" << endl;
            cout << Separator << endl;
            cout << ">> ";
            cin >> month;
        }
        else
        {
            break;
        }
    }
    system("cls");
    Header('=', 67, 25, 26, "ADD NEW Record");  
    system("color 0f");
    return month;    
}
int verify_Year(string message)
{
    int month;
    cout << message << endl;
    cout << ">> ";
    cin >> month;
    while(true)
    {
        if(cin.fail())
        {
            system("color 40");
            Clear_Buffer();
            system("cls");
            Header('=', 67, 25, 26, "ADD NEW Record");  
            cout << Separator << endl;
            cout << "Invalid Character, Please Re-Enter A Valid Value" << endl;
            cout << Separator << endl;
            cout << ">> ";
            cin >> month;
        }
        else if(month < 1980 || month > 2026)
        {
            system("color 40");
            system("cls");
            Header('=', 67, 25, 26, "ADD NEW Record"); 
            cout << Separator << endl;
            cout << "Invalid Value, Value Must be > 1980 and <= 2026" << endl;
            cout << Separator << endl;
            cout << ">> ";
            cin >> month;
        }
        else
        {
            break;
        }
    }
    system("cls");
    Header('=', 67, 25, 26, "ADD NEW Record"); 
    system("color 0f");
    return month;    
}
string Verify_Phone(string message, string Title)
{
    string phone;
    cout << message << endl;
    cout << ">> ";
    cin >> phone;
    while(phone.length() != 9)
    {
        system("color 40");
        system("cls");
        Header('=', 67, 25, 26, Title);  
        cout << Separator << endl;
        cout << "Invalid Phone Number, Must be (9 Numbers):" << endl;
        cout << Separator << endl;
        cout << ">> ";    
        cin >> phone;         
    }
    system("cls");
    Header('=', 67, 25, 26, Title);  
    system("color 0f");
    return phone;
}
string Verify_Email(string message, string Title)
{
    string email;
    cout << message << endl;
    cout << ">> ";
    cin >> email;
    while(!Has_at(email))
    {
        system("color 40");
        system("cls");
        Header('=', 67, 25, 26, Title);  
        cout << Separator << endl;
        cout << "Invalid Email, Must Contain (@):" << endl;
        cout << Separator << endl;
        cout << ">> ";    
        cin >> email;         
    }
    system("cls");
    Header('=', 67, 25, 26, Title);  
    system("color 0f");
    return email;
}
bool Has_at(string email)
{
    for(int i = 0; i < email.length(); i++)
    {
        if(email[i] == '@')
        {
            return true;
        }
    }
    return false;
}
bool Verify_Is_Active(string message, string Title)
{
    bool Is_Active;
    cout << message << endl;
    cout << ">> ";
    cin >> Is_Active;
    while(true)
    {
        if(cin.fail())
        {
            system("color 40");
            Clear_Buffer();
            system("cls");
            Header('=', 67, 25, 26, Title); 
            cout << Separator << endl;
            cout << "Invalid Value, Must be one of the following:" << endl;
            cout << "[1] True" << endl;
            cout << "[0] True" << endl;
            cout << Separator << endl;
            cout << ">> ";
            cin >> Is_Active;
        }
        else
        {
            break;
        }
    }
    system("cls");
    Header('=', 67, 25, 26, Title); 
    system("color 0f");
    return Is_Active;    
}
// ! ***************************  Local Storage Functions **********************************
vector <stStudents> Import_From_Binary_File()
{
    ifstream import_binary("Student Management System/Students.data", ios::binary);
    vector <stStudents> students;
    stStudents s;

    if(import_binary.is_open())
    {
        while(import_binary.read(reinterpret_cast<char*>(&s), sizeof(s)))
        {
            students.push_back(s);
        }
        import_binary.close();
    }
    return students;
}
void Export_To_Binary(vector <stStudents> &students)
{
    ofstream export_binary("Student Management System/Students.data", ios::binary);
    if(export_binary.is_open())
    {
        for(stStudents &s : students)
        {
            export_binary.write(reinterpret_cast<char*>(&s), sizeof(s));
        }
        export_binary.close();
    }
}
// ! *************************  Header & Message Functions *********************************
void Header(char symbol, int symbol_length, int M_Left, int M_Right, string Mess)
{
    cout << string(symbol_length, symbol) << endl;
    cout << string(M_Left, symbol) << " " << Mess << " " << string(M_Right, symbol) << endl;
    cout << string(symbol_length, symbol) << endl;
}
void Message(vector <stStudents> &students, string NOTE)
{
    cout << Separator << endl;
    cout << NOTE << endl;
    cout << Separator << endl;
    cout << "- [E] EXIT Program" << endl;
    cout << "- [Any Key] Return To Main Menu" << endl;

    cout << Separator << endl;    
    cout << ">> ";    
    char choice;
    cin >> choice;
    switch (choice)
    {
        case 'E':
        case 'e':
            break;
        default:
            Main_Menu(students);
            break;
    }
}
void Print_Student_Row(stStudents &s)
{
    cout << left << setw(8) << s.RollNumber << setw(20) << string(s.First_Name) + ' ' + string(s.Last_Name) << setw(6) << s.Department << setw(7) << s.Semester << setw(7) << fixed << setprecision(2) << s.cGPA << setw(12) << s.Date_of_Birth << setw(13) << s.Phone_Number <<  setw(22) << s.Email << setw(9) << Print_Boolean_as_String(s.Is_Active) << endl; 
}
void Print_Student_Header()
{
    cout << string(106, '=') << endl;
    cout << left << setw(8) << "R.NUM" << setw(20) << "Student Name" << setw(6) << "DEP" << setw(7) << "Sem" << setw(7) << "GPA" << setw(12) << "DOB" << setw(13) << "PhoneNumber" <<  setw(22) << "Email" << setw(9) << "Status" << endl;
    cout << string(106, '=') << endl;
}
void Confirm_Message(string title)
{
    cout << "Are You Sure You Want to " << title << "?" << endl;
    cout << Separator << endl;
    cout << "[Y] Yes" << endl;
    cout << "[Any Key] No" << endl;
    cout << Separator << endl;
    cout << ">> ";
}
string Print_Boolean_as_String(bool isactive)
{
	if(isactive)
		return "Active";
	else
		return "InActive";
}
// ! **************************  Arrange Comparing Functions ********************************
bool Compare_Roll_Ascending(stStudents s1, stStudents s2)
{
    return s1.RollNumber < s2.RollNumber;
}
bool Compare_Roll_Descending(stStudents s1, stStudents s2)
{
    return s1.RollNumber > s2.RollNumber;
}
bool Compare_Name(stStudents s1, stStudents s2)
{
    return string(s1.First_Name) < string(s2.First_Name);
}
bool Compare_cGPA(stStudents s1, stStudents s2)
{
    return s1.cGPA > s2.cGPA;
}
bool Compare_Semester_Ascending(stStudents s1, stStudents s2)
{
    return s1.Semester < s2.Semester;
}
// ! ******************************  Other Help Functions ***********************************
string Convert_To_Lower(string text)
{
    transform(text.begin(), text.end(), text.begin(), ::tolower);

    return text;
}
void Clear_Buffer()
{
    cin.clear();
    cin.ignore(100, '\n');
}
bool Exist_Student(vector <stStudents> &students, int roll)
{
    for(stStudents &s : students)
    {
        if(s.RollNumber == roll)
        {
            return true;
        }
    }
    return false;
}
int Find_Student(vector <stStudents> &students, string student_name_roll)
{
    for(int i = 0; i < students.size(); i++)
    {
        if(to_string(students[i].RollNumber) == student_name_roll || Convert_To_Lower(string(students[i].First_Name) + " " + string(students[i].Last_Name))  == student_name_roll)
        {
            return i;
        }
    }
    return -1;
}
int get_next_roll(vector <stStudents> &students)
{
    if(students.empty())
    {
        return 1000;
    }

    int max = students[0].RollNumber;
    for(stStudents &s : students)
    {
        if(s.RollNumber > max)
        {
            max = s.RollNumber;
        }
    }
    return max + 1;
}