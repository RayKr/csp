#include <stdio.h>
#include <math.h>

int main() {
    int n, m; // n个操作, m个查询
    scanf("%d %d", &n, &m);

    int type[n]; // 操作类型，1是拉伸，2是旋转
    double value[n]; // 操作值，k或theta
    for (int i = 0; i < n; i++) {
        scanf("%d", &type[i]); // %lf -> double
        scanf("%lf", &value[i]);
    }

    int query[m][4]; // i,j,x,y
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d %d", &query[i][0], &query[i][1], &query[i][2], &query[i][3]);
    }

    // 遍历m个查询
    for (int idx = 0; idx < m; idx++) {
        // 取出x,y
        int i = query[idx][0];
        int j = query[idx][1];
        double x = query[idx][2];
        double y = query[idx][3];

        // 按照i,j依次从操作列表中取出
        for (int idx = i - 1; idx < j; idx++) {
            // 取出该行的操作
            if (type[idx] == 1) { 
                // 如果是拉伸
                x *= value[idx];
                y *= value[idx];
            } else if (type[idx] == 2) {
                // 如果是旋转
                double xn = x * cos(value[idx]) - y * sin(value[idx]);
                y = x * sin(value[idx]) + y * cos(value[idx]);
                // ! 一定注意这个地方，必须新建xn，因为计算y必须用之前的x，而不能用更新后的x
                x = xn;
            }
        }
        // 打印这一个查询的结果
        printf("%.3f %.3f\n", x, y);

    }


    return 0;
}