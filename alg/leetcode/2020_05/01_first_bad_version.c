// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    int low = 1;
    int high = n;
    while (low < high) {
        int middle = low + (int)((high - low) / 2);

        int isBad = isBadVersion(middle);

        if (isBad != isBadVersion(middle + 1)) {
            return middle + 1;
        }

        if (isBad) {
            high = middle;
        } else {
            low = middle;
        }
    }
    return high;
}