#include <iostream>
#include <vector>
#include <string>
#include <fstream> // <-- need for File IO

using namespace std;

//Function prototypes...
void display(vector <double> );
vector <double> averageAssignment( vector <vector <double> >);

//Main program...
int main()
{
  string filename;
  int exercises=0;
  int students=0;
  vector < vector<double> > gradebook;
  vector <double> avgGrade;
  
  cout<<"Enter gradebook file: ";
  cin>>filename;
  gradebook = loadGrades( filename ); // <-- IMPLEMENT FUNCTION FOR THIS
  avgGrade = averageAssignment( gradebook );
  
  display(avgGrade);

  return 0;
}

//Takes a 2-dimensional matrix of grades and averages each column to return a
//1-dimensional vector of each column's average.
vector <double> averageAssignment( vector <vector <double> > all)
{
  vector <double> result;
  double columnSum;
  int rows = all.size();
  int cols = all[0].size();
  
  for(int c = 0; c < cols; c++)
  {
    columnSum = 0.0;
    for(int r=0; r < rows; r++)
    {
      columnSum = columnSum + all[r][c];
    }
    result.push_back(columnSum/rows);
  }
  return result;
}

//Takes a vector of doubles and displays its contents, separated by spaces,
//as the average grades per assignment
void display(vector <double> grades)
{
  cout<<"===AVERAGE GRADES PER ASSIGNMENT===\n";
  for(int i = 0; i < grades.size(); i++)
  {
    cout<<grades[i]<<" ";
  }
  cout<<endl;
}