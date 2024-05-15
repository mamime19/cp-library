void extgcd(int a, int b, int &x, int &y) {
    if (b != 0) {
        extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1;
        y = 0;
    }
}