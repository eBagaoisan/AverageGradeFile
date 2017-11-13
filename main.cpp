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
  gradebook = loadGrades( filename );
  avgGrade = averageAssignment( gradebook ); // <-- IMPLEMENT FUNCTION FOR THIS
  
  display(avgGrade);

  return 0;
}

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

void display(vector <double> grades)
{
  cout<<"===AVERAGE GRADES PER ASSIGNMENT===\n";
  for(int i = 0; i < grades.size(); i++)
  {
    cout<<grades[i]<<" ";
  }
  cout<<endl;
}