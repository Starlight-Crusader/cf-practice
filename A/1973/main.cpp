#include <iostream>

int main()
{
    int t;
    scanf("%d", &t);

    int p[t][3];

    for (int i = 0; i < t; i++)
    {
        scanf("%d %d %d", &p[i][0], &p[i][1], &p[i][2]);
    }

    for (int i = 0; i < t; i++)
    {
        int res = 0;

        if ((p[i][0] + p[i][1] + p[i][2]) % 2 == 1)
        {
            res = -1;
        }
        else
        {
            for (int d01 = 0; d01 < 30; d01++)
            {
                for (int d02 = 0; d02 < 30; d02++)
                {
                    for (int d12 = 0; d12 < 30; d12++)
                    {
                        int cs0 = p[i][0] - d01 - d02;
                        bool c01 = cs0 % 2 == 0;
                        bool c02 = cs0 >= 0;

                        int cs1 = p[i][1] - d01 - d12;
                        bool c11 = cs1 % 2 == 0;
                        bool c12 = cs1 >= 0;

                        int cs2 = p[i][2] - d02 - d12;
                        bool c21 = cs2 % 2 == 0;
                        bool c22 = cs2 >= 0;

                        if (c01 && c02 && c11 && c12 && c21 && c22)
                        {
                            int dsum = d01 + d02 + d12;
                            if (dsum > res)
                            {
                                res = dsum;
                            }
                        }
                    }
                }
            }
        }

        printf("%d\n", res);
    }
}