#ifndef __STUDENT_H_
#define __STUDENT_H_


template<typename T, typename Comp>
bool CP::priority_queue<T, Comp>::operator==(const CP::priority_queue<T, Comp> &other) const {
    if (other.size() != size()) return false;
    priority_queue <T, Comp> qa(*this);
    priority_queue <T, Comp> qb(other);

    for (size_t i = 0; i < size(); i++) {
        if (qa.top() != qb.top()) return false;
        qa.pop();
        qb.pop();
    }
    return true;
}

#endif
