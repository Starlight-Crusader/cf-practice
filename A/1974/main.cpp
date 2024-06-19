#include <iostream>

int main()
{
    int t; scanf("%d", &t);

    int xy[t][2];
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d", &xy[i][0], &xy[i][1]);
    }

    for (int i = 0; i < t; i++)
    {
        int ns = 0;
        while (xy[i][0] > 0 || xy[i][1] > 0)
        {
            ns++;
            int rspace = 15;

            while (xy[i][1] > 0 && rspace > 7)
            {
                rspace -= 4;
                xy[i][1]--;
            }

            while (xy[i][0] > 0 && rspace > 0)
            {
                rspace--;
                xy[i][0]--;
            }
        }

        printf("%d\n", ns);
    }
}