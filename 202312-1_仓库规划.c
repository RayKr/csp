#include <stdio.h>

// check if a is bigger than b
int is_big_than(int a[], int b[], int m)
{
    for (int i = 0; i < m; i++)
    {
        if (a[i] <= b[i])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < n; i++) // 首先遍历每一行，当前行是a[i]
    {
        int p = 0;                  // no fater
        for (int j = 0; j < n; j++) // 再取出每一行来跟当前行对比大小
        {
            if (is_big_than(a[j], a[i], m) == 1) // 如果比当前行大，说明可以作为parent备选
            {
                if (p == 0)
                {
                    p = j + 1;
                }
                else // 如果p不为0，说明之前已经存在parent，就需要做对比，看哪个更小
                {
                    if (p > j + 1)
                    {
                        // 之前的更大，说明新的更小，应该替换parent
                        p = j + 1;
                    }
                }
            }
        }
        printf("%d\n", p);
    }

    return 0;
}
