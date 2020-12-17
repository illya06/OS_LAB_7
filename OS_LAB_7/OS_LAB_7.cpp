#include <iostream>
#include <Windows.h>

using namespace std;

#define MAX_THREADS 16

/*

    TO DO:
    1. create threads
    2. make work for threads (A - iter | B - id)
    3. sync em
    4. make progress counter

*/

HANDLE threadList[MAX_THREADS];
DWORD  threadIDList[MAX_THREADS];

int  ammountOfThreads();
void createThreadWithData(void* data, int num);

int main()
{
    
}

int ammountOfThreads() {
    int ammount;

    cout << "\nEnter ammount of processes (up to \033[30m"
        << MAX_THREADS << "\033[0m) : ";
    cin >> ammount;

    if (ammount > 0 && ammount < MAX_THREADS + 1)
        return ammount;
    else
        return 0;
}

void createThreadWithData(void* data, int num) {
    threadList[num] = CreateThread(
        NULL,
        0,
        NULL,
        data,
        CREATE_SUSPENDED,
        &threadIDList[num]
    );
    if (threadList[num] == NULL) {
        printf(
            "\n\033[32mERROR\033[0m Could`n create thread (%d)",
            GetLastError()
        );
    }
}
        

