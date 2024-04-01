void shift(int k) {
    
    while (k < 0) {
        k += mSize;
    }

    k = k % mSize;

    for (int i = 0; i < k; i++) {
        auto a = mHeader->next;
        auto b = mHeader->next->next;
        auto c = mHeader->prev;

        mHeader->next = b;
        mHeader->prev = a;

        a->next = mHeader;
        a->prev = c;

        b->prev = mHeader;

        c->next = a;
    }
}
