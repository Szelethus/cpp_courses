int loop_ref(int &dst, const int &src, int n) {
    for (int i = 0; i < n; ++i) {
        dst = dst + src;
    }
    return dst;
}

int loop_val(int dst, int src, int n) {
    for (int i = 0; i < n; ++i) {
        dst = dst + src;
    }
    return dst;
}


