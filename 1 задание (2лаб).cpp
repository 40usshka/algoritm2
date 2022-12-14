#include <iostream>
#include <time.h>

void Program(int n)
{
    double TIME1 = clock();
    int** A = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        A[i] = (int*)malloc(n * sizeof(int));
    }

    int** B = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        B[i] = (int*)malloc(n * sizeof(int));
    }

    int** C = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        C[i] = (int*)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = 10 + rand() % 90;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            B[i][j] = 10 + rand() % 90;

    double time1 = clock();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }

    double time2 = clock();
    double TIME2 = clock();
    printf("???-?? ?????????: %d\n", n);
    printf("????? ?????????: %lf \n", (time2 - time1) / CLOCKS_PER_SEC);
    printf("????? ?????????? ????????: %lf \n\n\n", (TIME2 - TIME1) / CLOCKS_PER_SEC);

    for (int i = 0; i < n; i++) {
        free(A[i]);
    }
    free(A);

    for (int i = 0; i < n; i++) {
        free(B[i]);
    }
    free(B);

    for (int i = 0; i < n; i++) {
        free(C[i]);
    }
    free(C);
}

int main(void)
{
    setlocale(0, "");
    srand(time(NULL));

    Program(100);
    Program(200);
    Program(400);
    Program(1000);
    Program(2000);
    Program(4000);
    Program(10000);
    system("pause");
    return 0;
}