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
void* specifyFuncData(int ammount);

int main()
{
    
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

void* specifyFuncData(int ammount) {
    void* retVal[3] = {NULL, NULL, NULL};

    cout << "\nChoose operatin type (0 - iteration | 1 - id) : ";
    int choise;
    cin >> choise;
    retVal[0] = (void*)choise;

    if (choise == 0) {
        double step,
               left = -0.9,
               right = -0.9 + (1.8 / ammount);


        cout << "\nYou choose (\033[33miteration\033[0m)";
        cout << "\nEnter tabulation step : ";
        cin >> step;

        double data[3] = { step, left, right };

        retVal[1] = (void*)data;
    }
    else if (choise == 1) {
        int cycles;

        cout << "Enter ammount of cycles : ";
        cin >> cycles;

        retVal[2] = (void*)cycles;
    }
    else {
        retVal[0] = NULL;
        retVal[1] = NULL;
        retVal[2] = NULL;
    }

    return retVal;
}