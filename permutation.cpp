#include<iostream>
#include<conio.h>
#include<stdlib.h>
 
using namespace std;
 
void permute(int *a, int k, int size)
{
    if (k == size)
    {
        for (int i = 0; i < size; i++)
        {
            cout << *(a + i);
        }
        cout << endl;
    }
    else
    {
        for (int i = k; i < size; i++)
        {
            int temp = a[k];
            a[k] = a[i];
            a[i] = temp;
 
            permute(a, k + 1, size);
 
            temp = a[k];
            a[k] = a[i];
            a[i] = temp;
        }
    }
 
}
int main(int argc, char **argv)
{
    cout << "Enter the length of the password: ";
    int m;
    cin >> m;
    int a[m];
    for (int i = 0; i < m; i++)
    {
        /*generates random number between 1 and 10*/
        a[i] = rand() % 10;
    }
    for (int i = 0; i < m; i++)
    {
        cout << a[i] << ", ";
    }
    cout << "The Passwords are: ";
    permute(a, 0, m);
}
