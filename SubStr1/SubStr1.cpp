#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <ctime>
#include <vector>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;


void Str(const string& a, const string& b, string& result)
{
    const int a_size = a.size();
    const int b_size = b.size();
   
    vector<vector<int> > arr;
    arr.resize(b_size + 1);
    for (int i = 0; i < b_size+1; ++i)
        arr[i].resize(a_size + 1);

    //typedef vector<int> solution;
    int max_lenth = 0;
    int index_a, index_b;

    for (int i = 1; i < b_size+1; i++)
    {
        for (int j = 1; j < a_size+1; j++)
        {
            if (a[j - 1] != b[i - 1])
                arr[i][j] = 0;
            else 
            {
                arr[i][j] = arr[i - 1][j - 1] + 1;
                if (max_lenth < arr[i][j])
                {
                    max_lenth = arr[i][j];
                    index_a = j;
                }
            }
            //cout << arr[i][j] << " ";

        }
        //cout << endl;
    }
    cout<<endl<<endl<< a.substr(index_a - max_lenth, max_lenth);

}

int main()
{
    string a = "", b = "", result, c;
    setlocale(LC_ALL, "Russian");

    ifstream a_file("C:\\Users\\Mary\\Desktop\\A.txt");
    if (a_file.is_open())
    {
        while (getline(a_file, c))
        {
            a += c;
        }
    }
    a_file.close();
    //cout << a;
    cout << endl << endl;
    ifstream b_file("C:\\Users\\Mary\\Desktop\\B.txt");
    if (b_file.is_open())
    {
        while (getline(b_file, c))
        {
            b += c;
        }
    }
    b_file.close();
    //cout << b;
    cout << endl;

    double Start, Finish, Duration;
    Start = clock();
    Str(a, b, result);
    Finish = clock();
    Duration = (Finish - Start) / double(CLOCKS_PER_SEC);
    printf("Time of execution = %f\n", Duration);


}



