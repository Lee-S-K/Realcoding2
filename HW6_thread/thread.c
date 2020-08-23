#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#define size 30

int max = 0;
int sum = 0;
short int score[size];

int compare(const void* a, const void* b);

int compare(const void* a, const void* b)
{
        if (*(short*)a > * (short*)b)
                return 1;
        else if (*(short*)a < *(short*)b)
                return -1;
        else
                return 0;
}

void* score_thread(void* arg)
{

        printf("score_Thread Start!!\n");
        for (int i = 0; i < size; i++) {
                scanf("%hd", &score[i]);
        }
        for(int i = 0; i < size; i++) {
                sum += score[i];
                sleep(1);
        }
        printf("평균 = %d\nSum = %d\n", sum/size, sum);
        printf("score_Thread End!!\n");

        pthread_exit(arg);
}

void* sort_thread(void* arg)
{
        printf("sort_Thread Start!!\n");
        qsort(score, size, sizeof(score[0]), compare);
        printf("성적순 정렬:");
        for (int i = size-1; i >= 0; i--) {
                printf(" %hd", score[i]);
        }
        printf("\n");
        printf("sort_Thread End!!\n");

        pthread_exit(arg);
}

int main(void)
{
        pthread_t tid;
        pthread_t tid2;
        int status;
        int status2;

        printf("Main_Thread Start!!\n");
        status = pthread_create(&tid, NULL, score_thread, (void*)3);
        status2 = pthread_create(&tid2, NULL, sort_thread, (void*)3);

        if (status != 0) {
                perror("thread create");
                exit(1);
        }
        if (status != 0) {
                perror("thread create");
                exit(1);
        }
        for (int i = 1; i <= 4; i++) {
                sleep(1);
        }

        printf("Main_Thread End!!\n");
        pthread_exit(NULL);
        return 0;

}
