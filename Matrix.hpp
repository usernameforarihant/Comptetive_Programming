//Matrix.hpp

//Libraries to Use
#include <iostream>
#include <vector>
using namespace std;

//Matrix
class Matrix
{
    public:

    //Transpose
    vector<vector<double>> transpose(vector<vector<double>> a)
    {
        vector<vector<double>> temp;
        int rows,columns;
        rows = a.size();
        columns = a[0].size();

        //Loop for Conversion
        for(int i = 0;i<columns;i++)
        {
            vector<double> temp1;
            for(int j = 0;j<rows;j++)
            {
                temp1.push_back(a[j][i]);
            }
            temp.push_back(temp1);
        }
        return temp;
    }

    //Matrix Multiplication
    vector<vector<double>> mat_mul(vector<vector<double>> a, vector<vector<double>> b)
    {
        vector<vector<double>> temp;
        int rows = a.size();
        int columns = b[0].size();
        int common = a[0].size();

        for(int i = 0;i<rows;i++)
        {
            vector<double> row;
            //Calculating Row
            for(int j = 0;j<columns;j++)
            {
                int sum = 0;
                //Calculating Elements for the Row
                for(int k = 0;k<common;k++)
                {
                    sum += a[i][k]*b[k][j];
                }
                row.push_back(sum);
            }
            //Adding row
            temp.push_back(row);
        }
        return temp;
    }
};