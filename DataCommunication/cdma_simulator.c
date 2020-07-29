#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#define NUM 4
#define LEN 8

int main(void) {
    int i, j;
    int seq[NUM][LEN], input[NUM];

    // 4 chip sequence(8) input
    for (i = 0; i < NUM; i++) {
        printf("%d chip sequence : ", i + 1);
        for (j = 0; j < LEN; j++) {
            scanf("%d", &seq[i][j]);
        }
    }
    // 4 input bits(1) input
    for (i = 0; i < NUM; i++) {
        printf("%d input bit(1 or 0 or extra number(2~9)) : ", i + 1);
        scanf("%d", &input[i]);
    }

    int td[2], rd[2];
    pipe(td);  // make pipe - name : td
    pipe(rd);  // make pipe - name : rd

    if (pipe(td) == -1) {  // pipe error
        printf("transmitter pipe fail \n");
        exit(1);
    }
    if (pipe(rd) == -1) {  // pipe error
        printf("receiver pipe fail \n");
        exit(1);
    }

    pid_t tpid, rpid;
    tpid = fork();  // transmitter child process
    rpid = fork();  // receiver child process

    if (tpid == -1 || rpid == -1) {  // fork error
        printf("fork fail \n");
    }
    else if (tpid == 0) {  // child - tranmitter process
        int t_seq[NUM][LEN];
        for (i = 0; i < NUM; i++) {
            for (j = 0; j < LEN; j++) {
                t_seq[i][j] = 0;  // initialize
            }
        }
        for (i = 0; i < NUM; i++) {
            for (j = 0; j < LEN; j++) {
                // different calculate by input bits
                if (input[i] != 1 && input[i] != 0) {  // input bit is not (1 or 0)
                    t_seq[i][j] = 0;  // all zero
                }
                else if (input[i] == 1) {  // input bit is 1
                    t_seq[i][j] = seq[i][j];  // not changed
                }
                else if (input[i] == 0) {  // input bit is 0
                    t_seq[i][j] = seq[i][j] * (-1);  // minus
                }
            }
        }
        write(td[1], t_seq, sizeof(t_seq));  // to joiner(parent) process
    }
    else if (tpid > 0 && rpid > 0) {  // parent - joiner process
        int buffer[NUM][LEN];
        int s[LEN];
        for (i = 0; i < LEN; i++) {
            s[i] = 0;  // initialize
        }
        read(td[0], buffer, sizeof(buffer));  // from transmitter process
        for (j = 0; j < LEN; j++) {
            for (i = 0; i < NUM; i++) {
                s[j] += buffer[i][j];  // calculate S(total) signal
            }
        }
        write(rd[1], s, sizeof(s));  // to recevier process
    }
    else if (rpid == 0) {  // child - receiver process
        int tmp[LEN];
        int cal_arr[NUM][LEN];
        int sum[NUM];
        int result[NUM];

        for (i = 0; i < NUM; i++) {
            sum[i] = 0;  // initialize
            result[i] = 0;  // initialize
            for (j = 0; j < LEN; j++) {
                cal_arr[i][j] = 0;  // initialize
            }
        }
        read(rd[0], tmp, sizeof(tmp));  // from joiner(parent) process
        for (i = 0; i < NUM; i++) {
            for (j = 0; j < LEN; j++) {
                cal_arr[i][j] = tmp[j] * seq[i][j];  //multiply S & chip sequence
            }
        }
        for (i = 0; i < NUM; i++) {
            for (j = 0; j < LEN; j++) {
                sum[i] += cal_arr[i][j];  // sum all bits(signal)
            }
            result[i] = sum[i] / LEN;  // divide 8

            // print result
            if (result[i] == 1) {
                printf("%d output bit = %d -> %d send 1!!\n", i + 1, result[i], i + 1);
            }
            else if (result[i] == -1) {
                printf("%d output bit = %d -> %d send 0!!\n", i + 1, result[i], i + 1);
            }
            else if (result[i] == 0) {
                printf("%d output bit = %d -> %d don't send!!\n", i + 1, result[i], i + 1);
            }
        }
    }
    exit(0);
    return 0;
}
