/* 5b. Design, Develop and Implement a Program for the following Stack Applications - Solving Tower of Hanoi problem with n disks.
*/

#include<stdio.h>

void TOH(int n, char from, char to, char via) {
    if(n == 1) {
        printf("Disk 1 moved from %c to %c\n", from, to);
        return;
    }
    TOH(n-1, from, via, to);
    printf("Disk %d moved from %c to %c\n", n, from, to);
    TOH(n-1, via, to, from);
}

int main() {
    int n;
    
    printf("Enter the number of disks : ");
    scanf("%d", &n);

    TOH(n, 'A', 'B', 'C');
    return 0;
}