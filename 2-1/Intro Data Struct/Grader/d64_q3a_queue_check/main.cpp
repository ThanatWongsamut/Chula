#include <iostream>

using namespace std;

int main() {
    int n;
    int mFront, mSize, mCap, last, correction;

    cin >> n;

    while (n--) {
        cin >> mFront >> mSize >> mCap >> last >> correction;

//        mFront check
        bool mFrontCheck = mFront < mCap;

//        mSize check
        bool mSizeCheck = mSize <= mCap;

//        mCap check
        bool mCapCheck = mCap >= mSize && mCap > last;

//        Last check
        bool lastCheck = last < mCap && last == (mFront + mSize) % mCap;

        if (mFrontCheck && mSizeCheck && mCapCheck && lastCheck) {
            cout << "OK" << endl;
        } else {
            if (correction == 0) {
                cout << "WRONG" << endl;
            } else if (correction == 1) {
                cout << "WRONG " << (last - mSize < 0 ? last + mCap - mSize : last - mSize) << endl;
            } else if (correction == 2) {
                cout << "WRONG " << (last - mFront < 0 ? last + mCap - mFront : last - mFront) << endl;
            } else if (correction == 3) {
                cout << "WRONG " << (mFront + mSize - last < last ? last + 1 : mFront + mSize - last) << endl;
            } else if (correction == 4) {
                cout << "WRONG " << (mFront + mSize) % mCap << endl;
            }
        }
    }
}