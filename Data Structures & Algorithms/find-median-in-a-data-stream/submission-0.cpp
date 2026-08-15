class MedianFinder {
private:
    // Nửa nhỏ: phần tử lớn nhất nằm ở đầu
    priority_queue<int> left;

    // Nửa lớn: phần tử nhỏ nhất nằm ở đầu
    priority_queue<int, vector<int>, greater<int>> right;

public:
    MedianFinder() {
    }

    void addNum(int num) {
        // Đưa num vào một trong hai heap
        if (left.empty() || num <= left.top()) {
            left.push(num);
        } else {
            right.push(num);
        }

        // Cân bằng hai heap
        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        }
        else if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {
        // Số phần tử lẻ
        if (left.size() > right.size()) {
            return left.top();
        }

        // Số phần tử chẵn
        return (left.top() + right.top()) / 2.0;
    }
};