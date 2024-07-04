 #include <iostream>

 int main()
 {
    int t; std::cin >> t;

    while (t--)
    {
        int n; std::cin >> n;

        int p = 0;
        while (n--)
        {
            char c; std::cin >> c;
            if (c == 'U')
            {
                p++;
            }
        }

        if (p % 2 == 0)
        {
            std::cout << "NO" << '\n';
        }
        else
        {
            std::cout << "YES" << '\n';
        }
    }
 }