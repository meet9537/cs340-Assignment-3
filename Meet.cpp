#include<iostream>
using namespace std;

int position(int* x, int Begin, int End)
{
    int Pivot = x[End];
    
    int P_Index = Begin;
    int i, j; 


    for (i = Begin; i < End; i++)
    {
        if (x[i] <= Pivot)
        {
            j = x[i];
            x[i] = x[P_Index];
            x[P_Index] = j;
            P_Index++;
        }
    }
    
    j = x[End];
    x[End] = x[P_Index];
    x[P_Index] = j;

   
    return P_Index;
}
void Quicksort(int* x, int Begin, int End)
{
    if (Begin < End)
    {
        int P_Index = position(x, Begin, End);
        Quicksort(x,Begin, P_Index - 1);
        Quicksort(x, P_Index + 1, End);
    }
}
int main()
{
    const int n = 10;
    int x[n];

    cout<< "Please enter the array elements"<<endl;

    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    Quicksort(x, 0, n - 1);

    cout<< "after Quick Sort the array element is"<<endl;

    for (int i = 0; i < n; i++)
    {
        cout << x[i] << " ";
    }
    return 0;
}