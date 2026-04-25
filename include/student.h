#pragma once
#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

struct stStudents
{
    int RollNumber;
    char First_Name[40];
    char Last_Name[40];
    char Department[40];
    int Semester;
    float cGPA;
    char Date_of_Birth[12];
    char Phone_Number[20];
    char Email[40];
    bool Is_Active;
};

// * ****************************************************************************************
// *                                (Function Prototypes)
// * ****************************************************************************************
// ! *****************************  Main Functions (CRUD) ***********************************
void Main_Menu(vector <stStudents> &students);
void Add_New_Student(vector <stStudents> &students);
void Show_All_Students(vector <stStudents> &students);
void Search_Student(vector <stStudents> &students);
void Update_Student(vector <stStudents> &students);
void Delete_Student(vector <stStudents> &students);
void Statistics_And_Reports(vector <stStudents> &students);
void Arrange_Students(vector <stStudents> &students);
void Export_To_TXT_File(vector <stStudents> &students, char delimiter);
void Import_From_TXT_File(vector <stStudents> &students, char delimiter);
void Backup_And_Restore(vector <stStudents> &students);
// ! *************************  Reading & Verifying Fuctions ********************************
int Verify_Integers(string message);
int Verify_Roll_Number(vector <stStudents> &students, string message);
bool Check_if_Exist(vector <stStudents> &students, int roll);
string Verify_Name(string message);
bool Is_Digit(string txt);
string Verify_Department(string message);
int Verify_Semester(string message, string Title);
float Verify_cGPA(string message, string Title);
string Verify_Date(string message);
int verify_Day(string message);
int verify_Month(string message);
int verify_Year(string message);
string Verify_Phone(string message, string Title);
string Verify_Email(string message, string Title);
bool Has_at(string email);
bool Verify_Is_Active(string message, string Title);
// ! ***************************  Local Storage Functions **********************************
vector <stStudents> Import_From_Binary_File();
void Export_To_Binary(vector <stStudents> &students);
// ! *************************  Header & Message Functions *********************************
void Header(char symbol, int symbol_length, int M_Left, int M_Right, string Mess);
void Message(vector <stStudents> &students, string NOTE);
string Print_Boolean_as_String(bool isactive);
void Print_Student_Row(stStudents &s);
void Print_Student_Header();
void Confirm_Message(string title);
// ! **************************  Arrange Comparing Functions ********************************
bool Compare_Roll_Ascending(stStudents s1, stStudents s2);
bool Compare_Roll_Descending(stStudents s1, stStudents s2);
bool Compare_Name(stStudents s1, stStudents s2);
bool Compare_cGPA(stStudents s1, stStudents s2);
bool Compare_Semester_Ascending(stStudents s1, stStudents s2);
// ! ******************************  Other Help Functions ***********************************
string Convert_To_Lower(string text);
void Clear_Buffer();
bool Exist_Student(vector <stStudents> &students, int roll);
int Find_Student(vector <stStudents> &students, string student_name_roll);
int get_next_roll(vector <stStudents> &students);
