int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int min(int x, int y) {
    if (x < y) {
        return x;
    } else {
        return y;
    }
}

int main() {
    int x = 10;
    int y = 20;
    int result = max(x, y);
    int minimum = min(x, y);
    return result;
}
