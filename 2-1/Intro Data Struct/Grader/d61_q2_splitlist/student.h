void splitList(list <T> &list1, list <T> &list2) {
    size_t size1 = mSize - (mSize / 2);
    size_t size2 = (mSize / 2);

    iterator it = begin();
    for (size_t i = 0; i < size1; i++) it++;
    list1.mHeader->prev->next = mHeader->next;
    mHeader->next->prev = list1.mHeader->prev;
    list1.mHeader->prev = it.ptr->prev;
    it.ptr->prev->next = list1.mHeader;
    it.ptr->prev = list2.mHeader->prev;
    list2.mHeader->prev->next = it.ptr;
    list2.mHeader->prev = mHeader->prev;
    mHeader->prev->next = list2.mHeader;

    mHeader->prev = mHeader;
    mHeader->next = mHeader;

    mSize = 0;
    list1.mSize = size1;
    list2.mSize = size2;
}