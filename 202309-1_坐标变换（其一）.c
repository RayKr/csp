#include <stdio.h>

int main() {
    int n, m; // n个操作, m个坐标
    scanf("%d %d", &n, &m);

    int a[n][2]; // 操作列表，坐标列表
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i][0], &a[i][1]);
    }

    int b[m][2];
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &b[i][0], &b[i][1]);
    }

    // 先计算变化量
    for (int i = 0; i < m; i++) {
        int x = b[i][0], y = b[i][1];
        for (int i = 0; i < n; i++) {
            x += a[i][0];
            y += a[i][1];
        }
        printf("%d %d\n", x, y);
    }


    return 0;
}