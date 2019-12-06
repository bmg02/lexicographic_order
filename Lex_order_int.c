#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <math.h>

int main()
{
    int i = 0, j = 0, k = 0, l = 0, MAX = 0, *nums, maxLen = 0;
    double dt1, dt2;
    char *buff, **strs;
    int size;

    printf("Enter number of elements you want to enter: ");
    scanf("%d", &MAX);
    nums = malloc(sizeof(int)*MAX);
    buff = malloc(sizeof(char)*MAX);
    strs = malloc(sizeof(char *)*MAX);
    printf("\n");
    for(i = 0; i < MAX; i++) {
        printf("[%d]: ", i+1);
        scanf("%d", &nums[i]);
    }

    for(i = 0; i < MAX; i++) {
        strs[i] = malloc(sizeof(nums[i]) + 1);
        sprintf(strs[i], "%-*d", MAX, nums[i]);
        if(maxLen < strlen(strs[i])) {
            maxLen = strlen(strs[i]);
        }
    }

    for(i = 0; i < MAX; i++) {
        for(j = 0; j < MAX; j++) {
            for(k = j+1; k < MAX; k++) {
                if((int*)strs[j][i] > (int*)strs[k][i]) {
                    if(i == 0) {
                        strcpy(buff, strs[j]);
                        strcpy(strs[j], strs[k]);
                        strcpy(strs[k], buff);
                    }
                    else {
                        if((int*)strs[j][i-1] == (int*)strs[k][i-1]) {
                            if((int*)strs[j][i] > (int*)strs[k][i]) {
                                for(l = i; l < MAX; l++) {
                                    buff[0] = strs[k][l];
                                    strs[k][l] = strs[j][l];
                                    strs[j][l] = buff[0];
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("\nAFTER SORTING: \n");
    for(i = 0; i < MAX; i++) {
        printf("%s| ", strs[i]);
    }
    return 0;
}


/*
OUTPUT:

Enter 5 values:
[1]: 9
[2]: 876
[3]: 88
[4]: 754
[5]: 870


AFTER SORTING:
754  | 870  | 876  | 88   | 9    |

*/
