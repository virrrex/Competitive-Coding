#include <bits/stdc++.h> 
#include <fstream>
using namespace std; 

float area(int x1, int y1, int x2, int y2, int x3, int y3) 
{ 
    return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0); 
} 

bool isInside(int x1, int y1, int x2, int y2, int x3, int y3) 
{ 
    int x=0, y=0;
    float A = area (x1, y1, x2, y2, x3, y3); 
    float A1 = area (x, y, x2, y2, x3, y3); 
    float A2 = area (x1, y1, x, y, x3, y3); 	
    float A3 = area (x1, y1, x2, y2, x, y); 	
    return (A == A1 + A2 + A3); 
} 

void strToParam(string &str, int &x1, int &y1, int &x2, int &y2, int &x3, int &y3)
{
    int num=0, n, d = 1, c=0;
    n = str.length();
    for(int i=n-1; i>-1; i--)
    {
        if(str[i]==',')
        {   
            c++;
            switch(c)
            {
                case 1: y3 = num; break;
                case 2: x3 = num; break;
                case 3: y2 = num; break;
                case 4: x2 = num; break;
                case 5: y1 = num; break;
                default: ;
            }
            num=0;
            d=1;
            continue;
        }
        if(str[i]=='-')
            num *= -1;
        else
        {
            num += (str[i]-'0')*d; 
            d *= 10;
        }
    }
    x1 = num;
}

int main() 
{ 
    //Using triangles.txt, a 27K text file containing the co-ordinates of one thousand "random" triangles,
    //find the number of triangles for which the interior contains the origin.
    ifstream inFile("p102_triangles.txt");
    //inFile.open("p102_triangles.txt");
    int count = 0, x1, y1, x2, y2, x3, y3;
    if (inFile.is_open()){
        string coordinates;
        while(getline(inFile, coordinates))
        { 
            strToParam(coordinates, x1, y1, x2, y2, x3, y3);
            cout<<x1<<","<<y1<<","<<x2<<","<<y2<<","<<x3<<","<<y3<<endl;
            if(isInside( x1, y1, x2, y2, x3, y3))
                count++;
        }
        inFile.close();
    }

    cout<<count;
    return 0; 
} 
