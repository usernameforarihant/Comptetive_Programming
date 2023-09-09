//DataFrame.hpp

//Libraries to Use
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

//DataFrame
class DataFrame
{
    //Feature Vector
    vector<vector<double>> X;

    //Class Vector
    vector<vector<double>> Y;

    public:
    void read_csv(string name)
    {
        //First Reading in String Format
        vector<vector<string>> content;
	    vector<string> row;
	    string line, word;

        fstream file (name, ios::in);

        //Parsing CSV File
        if(file.is_open())
        {
            while(getline(file, line))
            {
                row.clear();
                
                stringstream str(line);
    
                while(getline(str, word, ','))
                {
                    row.push_back(word);
                }
                content.push_back(row);
            }
        }

        //Defining Rows and Columns
        int rows = content.size();
        int columns = content[0].size();
        
        //Converting String to Double
        for(int i = 1;i<rows;i++)
        {
            vector<double> temp_x;
            vector<double> temp_y;
            for(int j = 0;j<columns-1;j++)
            {
                temp_x.push_back(stod(content[i][j]));
            }
            temp_y.push_back(stod(content[i][columns-1]));

            X.push_back(temp_x);
            Y.push_back(temp_y);
        }
    }

    //Returning Feature Vector
    vector<vector<double>> get_X()
    {
        return X;
    }

    //Returning Class Vector
    vector<vector<double>> get_Y()
    {
        return Y;
    }
};