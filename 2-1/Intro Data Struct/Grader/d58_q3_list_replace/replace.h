void replace(const T &x, list <T> &y) {
    auto it = begin();

    while (it != end()) {
        if (*it == x) {
            for (auto i: y) {
                insert(it, i);
            }
            it = erase(it);
        } else {
            it++;
        }
    }
}