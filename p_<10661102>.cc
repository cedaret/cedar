#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;
void Students();
void Course();
void Workers();


struct Student
{
string name;
vector<string> Scourses;
int year;
int level;
};

struct Staff
{
    string name;
    string job;
    int year;
};



int main()
{

vector<Staff> workers;
vector<string> courses;
vector<Student> Stud;
vector<char> grades;
vector<string> coursesS;
courses.push_back("ECONOMICS");
courses.push_back("FRENCH");
courses.push_back("GEOGRAPHY");

    cout<<"                      CEDARET SCHOOL MANAGEMENT SYSTEM                  "<<endl;
    cout<<"========================================================================"<<endl;
    cout<<"Please enter a record to display"<<endl;
    cout<<"S or s for student"<<endl;
    cout<<"W or w for Workers/Staff"<<endl;
    cout<<": ";
    char c;

    cin>>c;
    cout<<"========================================================================"<<endl;
while(c!='q')
{
     if(c=='s'||c=='S')
    {
        char op;
        cout<<"Please what would you like to do?"<<endl;
        cout<<"A or a to add to record."<<endl;
        cout<<"E or e to edit an item in existing record."<<endl;
        cout<<"D or d to delete an item in the record."<<endl;
        cout<<"G or g to add grades to a Student's courses."<<endl;
        cout<<"P or p to print out a Student's Academic Record."<<endl;
        cout<<":";
        cin>>op;
        cout<<"========================================================================"<<endl;
        if(op=='a'||op=='A')
        {   char reply;
            string sname,sfname,slname;
            int syearr;
            int slvl;
            cout<<"Please enter the surname name of the new student: ";
            cin>>sfname;
            cout<<endl;
            cout<<"Please enter the first name of the new student: ";
            cin>>slname;
            cout<<endl;
            sname=sfname+" "+slname;
            cout<<"Please enter the year of admission: ";
            cin>>syearr;
            cout<<endl;
            cout<<"Please enter the level of the student: ";
            cin>>slvl;
            cout<<endl;
            for(int i=0; i<courses.size(); i++)
                {cout<<i+1<<". "<<courses[i]<<endl;}
            int number;
            cout<<"Please enter the position of the course you wish to add the student to: ";
            cin>>number;
            cout<<endl;
            number=number-1;
            coursesS.push_back(courses[number]);
            cout<<"Please do you want to add more courses?Input 'Y' or 'y' for yes and 'N' or 'n' for no: ";
            cin>>reply;
            while(reply=='y'||reply=='Y')
                {
                cout<<"Please enter the position of the course you wish to add the student to: ";
                cin>>number;
                cout<<endl; //if condition
                number=number-1;
                coursesS.push_back(courses[number]);
                cout<<"Please do you want to add more courses?Input 'Y' or 'y' for yes and 'N' or 'n' for no: ";
                cin>>reply;
                }

            Student info={sname,coursesS,syearr,slvl};
            Stud.push_back(info);
            cout<<Stud[0].name<<endl;

            for(int i=0; i<Stud.size(); i++)
            {
                    cout<<i<<". "<<Stud[i].name<<"    L"<<Stud[i].level<<endl;
            }
        }
        else
        {

            //////////////////////////////////////////
            if(op=='g'||op=='G')
            {
            int snumber;
            for(int i=0;i<Stud.size();i++)
            {
                    cout<<i<<". "<<Stud[i].name<<"    L"<<Stud[i].level<<endl;
            }
            cout<<"Please enter the position of the Student whose grades you want to record: "<<endl;
            cin>>snumber;
            cout<<endl;
            if(Stud[snumber].Scourses.empty()==true)
            {
                cout<<"Please there are no courses available to this student."<<endl;
            }
            else
            {
                char g;
                for(int i=0;i<Stud[snumber].Scourses.size();i++)
                {
                    cout<<"Please enter the grades for "<<Stud[snumber].Scourses[i]<<":";
                    cin>>g;
                    grades.push_back(g);
                    cout<<endl;
                }
                cout<<endl;

            }
            }
            else
            {
                if(op=='p'||op=='P')
                {
             int no;
                for(int i=0;i<Stud.size();i++)
             {
                    cout<<i<<". "<<Stud[i].name<<"  L"<<Stud[i].level<<endl;
             }
             cout<<"Please enter the Student's number: "<<endl;
             cin>>no;
             ofstream outfile;
             outfile.open("Studentfile.txt");


             outfile<<"ID:00"<<no<<endl;
             outfile<<"Name: "<<Stud[no].name<<setw(20)<<"Year:L"<<Stud[no].level<<endl;
             outfile<<"Subject"<<setw(20)<<"Grade"<<endl;
             outfile<<"--------------------------------------------------------------------------------"<<endl;
              for(int i=0;i<Stud[0].Scourses.size();i++)
            {
                outfile<<Stud[0].Scourses[i]<<setw(20)<<grades[i]<<endl;
            }
             outfile<<"--------------------------------------------------------------------------------"<<endl;
             outfile.close();
                }
                 else
                 {
                     if(op=='E'||op=='e')
                     {
                          int input;
            string first,last,nam;
            int lvl;
            int yearr2;
            char reply;
              for(int i=1;i<Stud.size();i++)
            {
                    cout<<i<<". "<<Stud[i].name<<"    L"<<Stud[i].level<<endl;
            }
            cout<<"Please enter the position of the Student you want to edit: ";
            cin>>input;

            cout<<endl;
            cout<<"Please enter the first name of the Student: ";
            cin>>first;
            cout<<endl;
            cout<<"Please enter the last name of the Student: ";
            cin>>last;
            cout<<endl;
            nam=first+" "+last;
            cout<<"Please enter the Year of Admission: ";
            cin>>yearr2;
            cout<<endl;
            cout<<"Please enter the Level of the Student:";
            cin>>lvl;
            cout<<endl;
            for(int i=0;i<courses.size();i++)
                {cout<<i+1<<". "<<courses[i]<<endl;}
            int number;
            cout<<"Please enter the position of the course you wish to add the student to: ";
            cin>>number;
            cout<<endl;
            number=number-1;
            coursesS.push_back(courses[number]);
            cout<<"Please do you want to add more courses?Input 'Y' or 'y' for yes and 'N' or 'n' for no: ";
            cin>>reply;
            while(reply=='y'||reply=='Y')
                {
                cout<<"Please enter the position of the course you wish to add the student to: ";
                cin>>number;
                cout<<endl; //if condition
                number=number-1;
                coursesS.push_back(courses[number]);
                cout<<"Please do you want to add more courses?Input 'Y' or 'y' for yes and 'N' or 'n' for no: ";
                cin>>reply;
                }
            Stud[input].name=nam;
            Stud[input].year=yearr2;
            Stud[input].level=lvl;
            for(int i=0;i<Stud[input].Scourses.size();i++)
            {
                Stud[input].Scourses[i]=coursesS[i];
            }
                     }
                     else
                     {
                         if(op=='D'||op=='d')
                         {
                             for(int i=0;i<Stud.size();i++)
                {
                    cout<<i<<". "<<Stud[i].name<<"  L"<<Stud[i].level<<endl;
            }
            int number;
            cout<<"Please enter the number of the Student you want to delete: ";
            cin>>number;
            cout<<endl;
            Stud.erase(Stud.begin() + number);
                         }
                         else
                         {
                             cout<<"Invalid Input"<<endl;
                         }
                     }
                 }

            }
        }
    }
      else
      {
          if(c=='W'||c=='w')
          {
               char op;
        cout<<"Please what would you like to do?"<<endl;
        cout<<"A or a to add to record."<<endl;
        cout<<"E or e to edit an item in existing record."<<endl;
        cout<<"D or d to delete an item in the record."<<endl;
        cout<<":";
        cin>>op;
        cout<<"========================================================================"<<endl;
              if(op=='a'||op=='A')
{
char c;

    cin>>c;
      cout<<"Please what would you like to do?"<<endl;
        cout<<"A or a to add to record."<<endl;
        cout<<"E or e to edit an item in existing record."<<endl;
        cout<<"D or d to delete an item in the record."<<endl;
        char op;
        cin>>op;

    string namee,fname,lname;
           string jobb;
           int yearr;
           workers.push_back(Staff());
           cout<<"Please enter the first name of the new Staff: ";
          cin>>fname;
           cout<<endl;
           cout<<"Please enter the last name of the new Staff: ";
           cin>>lname;
           cout<<endl;
           namee=fname+" "+lname;
           cout<<"Please enter the job of the new Staff: ";
           cin>>jobb;
           cout<<endl;
           cout<<"Please enter the year of employment: ";
           cin>>yearr;
           cout<<endl;
           Staff info={namee,jobb,yearr};
           workers.push_back(info);
           for(int i=1;i<workers.size();i++)
           {
                cout<<i<<". "<<workers[i].name<<" "<<workers[i].job<<" "<<workers[i].year<<endl;
           }

}
else
{
    if(op=='e'||op=='E')
    {
         int input;
            string first,last,nam;
            string jobb2;
            int yearr2;
            for(int i=1;i<workers.size();i++)
            {
                    cout<<i<<". "<<workers[i].name<<" "<<workers[i].job<<" "<<workers[i].year<<endl;
            }
            cout<<"Please enter the position of the Staff you want to edit: ";
            cin>>input;

            cout<<endl;
            cout<<"Please enter the first name of the Staff: ";
            cin>>first;
            cout<<endl;
            cout<<"Please enter the last name of the Staff: ";
            cin>>last;
            cout<<endl;
            nam=first+" "+last;
            cout<<"Please enter the Job: ";
            cin>>jobb2;
            cout<<endl;
            cout<<"Please enter the Year of Employment: ";
            cin>>yearr2;
            cout<<endl;
            workers[input].name=nam;
            workers[input].job=jobb2;
            workers[input].year=yearr2;
            for(int i=1;i<workers.size();i++)
           {
               cout<<i<<". "<<workers[i].name<<" "<<workers[i].job<<" "<<workers[i].year<<endl;
           }

    }
    else{
        if(op=='d'||op=='D')
    {
           for(int i=1;i<workers.size();i++)
            {
                    cout<<i<<". "<<workers[i].name<<" "<<workers[i].job<<" "<<workers[i].year<<endl;
            }
            int number;
            cout<<"Please enter the number of the Staff you want to delete: ";
            cin>>number;
            cout<<endl;
            workers.erase(workers.begin() + number);
             for(int i=1;i<workers.size();i++)
           {
               cout<<i<<". "<<workers[i].name<<" "<<workers[i].job<<" "<<workers[i].year<<endl;
           }
    }
    else
    {
        cout<<"Invalid Input"<<endl;
    }
    }

}
          }
          else
          {
              if(c=='C'||c=='c')
              {   char op;
                  cout<<"Please what would you like to do?"<<endl;
        cout<<"A or a to add to record."<<endl;
        cout<<"E or e to edit an item in existing record."<<endl;
        cout<<"D or d to delete an item in the record."<<endl;
        cout<<":";
        cin>>op;
        cout<<"========================================================================"<<endl;
if(op=='a'||op=='A')
{
    string input;
            cout<<"Please enter the course you want to add:";
            cin>>input;
            courses.push_back(input);
            cout<<endl;
            cout<<"The new course list is: "<<endl;
            for(int i=0;i<courses.size();i++)
            {
                cout<<i+1<<". "<<courses[i]<<endl;
            }
}
else
{
    if(op=='e'||op=='E')
    {
        int input;
            string input2;
            for(int i=0;i<courses.size();i++)
                {
                    cout<<i+1<<". "<<courses[i]<<endl;
                }
            cout<<"Please enter the position of the course you want to edit: ";
            cin>>input;
            input=input-1;
            cout<<endl;
            cout<<"Please enter the name of the course you wish to replace "<<courses[input]<<" with:";
            cin>>input2;
            cout<<endl;
            courses[input]=input2;
               cout<<"The new course list is: "<<endl;
            for(int i=0;i<courses.size();i++)
            {
                cout<<i+1<<". "<<courses[i]<<endl;
            }
    }
    else
    {
        if(op=='d'||op=='D')
        {
             for(int i=0;i<courses.size();i++)
                {
                    cout<<i+1<<". "<<courses[i]<<endl;
                }
                int number;
                cout<<"Please enter the position of the course you want to delete: ";
                cin>>number;
                cout<<endl;
                number=number-1;
                courses.erase(courses.begin() + number);
            cout<<"The new course list is: "<<endl;
            for(int i=0;i<courses.size();i++)
            {
                cout<<i+1<<". "<<courses[i]<<endl;
            }
        }
        else
        {
            cout<<"Invalid Input."<<endl;
        }
    }
}
              }
          }
      }
      cout<<endl;
      cout<<"========================================================================"<<endl;
 cout<<"Please enter a record you would like to work on."<<endl;
    cout<<"S or s for student"<<endl;
    cout<<"W or w for Workers/Staff"<<endl;
    cout<<":";
    char c;

    cin>>c;
    cout<<"========================================================================"<<endl;
}
cout<<"Exiting..."<<endl;



        return 0;
}

