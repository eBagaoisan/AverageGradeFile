#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Global constants...
const int MAX_EXERCISES = 10;
const int MAX_STUDENTS = 5;

//Function prototypes...
vector < vector <double> > fillGradebook(int,int);
int getNum(string,int);
void display(vector <double> );

//Main program...
int main()
{
  int exercises=0;
  int students=0;
  vector < vector<double> > gradebook;
  vector <double> avgGrade;

  exercises = getNum("exercises",MAX_EXERCISES);
  students = getNum("students",MAX_STUDENTS);
  gradebook = fillGradebook(students,exercises);
  
  avgGrade = averageAssignment( gradebook ); // <-- IMPLEMENT FUNCTION FOR THIS
  
  display(avgGrade);

  return 0;
}

vector < vector <double> > fillGradebook(int students, int exercises)
{
  vector < vector<double> > grades;
  //make row for each student
  grades.resize(students);

  for(int student=0; student < students; student++ )
  {
    cout<<"Enter student "<<(student+1)<<"'s "
        <<exercises<<" grades: ";
    for(int exercise=0; exercise < exercises; exercise++)
    {
      //add a column for each student's grade
      double grade;
      cin>>grade;
      grades[student].push_back(grade);
    }
  }
  return grades;
}

int getNum(string name,int maximum)
{
  int count = 0;
  do
  {
    cout<<"How many "<<name<<" are there?"<<endl;
    cin>>count;
    if( count < 1 || count > maximum )
    {
      cout<<"ERROR: Must be between 1-"<<maximum<<".\n";
    }
  }while( count < 1 || count > maximum);
  return count;
}

void display(vector <double> grades)
{
  cout<<"===AVERAGE GRADES PER ASSIGNMENT===\n";
  for(int i = 0; i < grades.size(); i++)
  {
    cout<<grades[i]<<" ";
  }
  cout<<endl;
}