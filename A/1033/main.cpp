#include <iostream>

int main()
{
    int n; std::cin >> n;
    int ax, ay; std::cin >> ax >> ay;
    int bx, by; std::cin >> bx >> by;
    int cx, cy; std::cin >> cx >> cy;

    bool vc = ((by > ay && cy > ay) || (by < ay && cy < ay));
    bool hc = ((bx > ax && cx > ax) || (bx < ax && cx < ax));

    if (vc && hc)
    {
        std::cout << "YES" << '\n';
    }
    else
    {
        std::cout << "NO" << '\n';
    }
}