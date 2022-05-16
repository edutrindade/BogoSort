#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

using namespace std;

bool is_sorted(int *vector, int n)
{
    while (--n >= 1)
    {
        if (vector[n] < vector[n - 1])
            return false;
    }
    return true;
}

void shuffle(int *vector, int n)
{
    int position, random;
    for (int i = 0; i < n; i++)
    {
        position = vector[i];
        random = rand() % n;
        vector[i] = vector[random];
        vector[random] = position;
    }
}

void bogosort(int *vector, int n)
{
    while (!is_sorted(vector, n))
        shuffle(vector, n);
}

int main()
{
    int vector[] = {1, 10, 9, 7, 3, 0};

    bogosort(vector, 6);
    for (int i = 0; i < 6; i++)
        cout << vector[i] << " ";
    cout << endl;
}
