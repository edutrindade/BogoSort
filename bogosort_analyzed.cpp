#include <iostream>
#include <windows.h>
#include <time.h>
#include <chrono>

#define INSTANCE_A 10
#define INSTANCE_B 11
#define INSTANCE_C 12
#define INSTANCE_D 15

using namespace std;
using namespace chrono;

void print_vector(int *vector, int n)
{
    cout << "\nVector: ";
    for (int i = 0; i < n; i++)
        cout << vector[i] << " ";
    cout << endl;
}

void create_vector(int *vector, int n)
{
    for (int i = 0; i < n; i++)
        vector[i] = rand() % 100;
}

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
    long int attempts = 0;
    while (!is_sorted(vector, n))
    {
        shuffle(vector, n);
        attempts++;
    }
    cout << "\nAttempts: " << attempts << endl;
}

int menu()
{
    int option;
    do
    {
        system("cls");
        cout << "--- Bogo Sort ---" << endl;
        cout << "1. Instance A (10 numbers)" << endl;
        cout << "2. Instance B (11 numbers)" << endl;
        cout << "3. Instance C (12 numbers)" << endl;
        cout << "4. Instance C (15 numbers)" << endl;
        cout << "5. Exit" << endl;
        cout << "\nChoose an option: ";
        cin >> option;
    } while (option < 1 || option > 5);
    return option;
}

int main()
{
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
    srand(time(NULL));
    steady_clock::time_point t1, t2;
    duration<long double> time;

    int vector_A[INSTANCE_A];
    int vector_B[INSTANCE_B];
    int vector_C[INSTANCE_C];
    int vector_D[INSTANCE_D];

    int option = menu();

    switch (option)
    {
    case 1:
        create_vector(vector_A, INSTANCE_A);
        print_vector(vector_A, INSTANCE_A);
        t1 = steady_clock::now();
        bogosort(vector_A, INSTANCE_A);
        t2 = steady_clock::now();
        time = duration_cast<duration<long double>>(t2 - t1);
        print_vector(vector_A, INSTANCE_A);
        cout << "Size: " << INSTANCE_A << " numbers" << endl;
        cout << "Time: " << time.count() << " seconds" << endl;
        break;
    case 2:
        create_vector(vector_B, INSTANCE_B);
        print_vector(vector_B, INSTANCE_B);
        t1 = steady_clock::now();
        bogosort(vector_B, INSTANCE_B);
        t2 = steady_clock::now();
        time = duration_cast<duration<long double>>(t2 - t1);
        print_vector(vector_B, INSTANCE_B);
        cout << "Size: " << INSTANCE_B << " numbers" << endl;
        cout << "Time: " << time.count() << " seconds" << endl;
        break;
    case 3:
        create_vector(vector_C, INSTANCE_C);
        print_vector(vector_C, INSTANCE_C);
        t1 = steady_clock::now();
        bogosort(vector_C, INSTANCE_C);
        t2 = steady_clock::now();
        time = duration_cast<duration<long double>>(t2 - t1);
        print_vector(vector_C, INSTANCE_C);
        cout << "Size: " << INSTANCE_C << " numbers" << endl;
        cout << "Time: " << time.count() << " seconds" << endl;
        break;
    case 4:
        create_vector(vector_D, INSTANCE_D);
        print_vector(vector_D, INSTANCE_D);
        t1 = steady_clock::now();
        bogosort(vector_D, INSTANCE_D);
        t2 = steady_clock::now();
        time = duration_cast<duration<long double>>(t2 - t1);
        print_vector(vector_D, INSTANCE_D);
        cout << "Size: " << INSTANCE_D << " numbers" << endl;
        cout << "Time: " << time.count() << " seconds" << endl;
        break;
    case 5:
        break;
    }

    return EXIT_SUCCESS;
}
