#include <stdio.h>
#include <string.h>

struct op {
    char l[20];
    char r[20];
} op[10];

int main() {
    int n, lineno = 1;
    printf("Enter the number of values: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\tleft: ");
        scanf("%s", op[i].l);
        printf("\tright: ");
        scanf("%s", op[i].r);
    }

    printf("Intermediate Code:\n");
    for (int i = 0; i < n; i++) {
        printf("Line No=%d\n\t\t\t%s = %s\n", lineno++, op[i].l, op[i].r);
    }

    printf("***Data Flow Analysis for the Above Code ***\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (strstr(op[j].r, op[i].l)) {
                printf("\n%s is live at %s\n", op[i].l, op[j].r);
            }
        }
    }
    return 0;
}