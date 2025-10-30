
int loop_ref(volatile int &dst, volatile const int &src, int n);

int loop_val(int dst, int src, int n);


int foo(volatile int a, volatile int b) {
    const int N = 1000000;

    int tmp1 = loop_ref(a, b, N);
    int tmp2 = loop_val(a, b, N);
    return tmp1+tmp2;
}

