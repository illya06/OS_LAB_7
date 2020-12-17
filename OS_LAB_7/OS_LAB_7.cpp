#include <iostream>
#include <Windows.h>

using namespace std;

#define MAX_THREADS 16

/*

    TO DO:
    1. create threads
    2. make work for threads
    3. sync em
    4. make progress counter

*/

HANDLE threadList[MAX_THREADS];
DWORD  threadIDList[MAX_THREADS];

void creareThreads();
void** specifyFuncData(int ammount);

int main()
{
    void** test = specifyFuncData(3);
    int ch = *(int*)test[0];
    cout << "test";
}

void creareThreads() {
    void* inputType;
    int ammount;

    cout << "\nEnter ammount of processes (up to \033[30m"
        << MAX_THREADS << "\033[0m) : ";
    cin >> ammount;


    //Creation
    for (int i = 0; i < ammount; i++) {
        threadList[i] = CreateThread(
            NULL,
            0,
            NULL,
            NULL,
            CREATE_SUSPENDED,
            &threadIDList[i]
        );
        if (threadList[i] == NULL) {
            printf(
                "\n\033[32mERROR\033[0m Could`n create thread (%d)",
                GetLastError()
            );
        }
    }
}