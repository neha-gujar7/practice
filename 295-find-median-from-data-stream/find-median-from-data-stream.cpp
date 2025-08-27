class MedianFinder {
public:
    priority_queue<int> lt; // max heap
    priority_queue<int, vector<int>, greater<int>> rt; // min heap

    MedianFinder() {}

    void addNum(int num) {
        lt.push(num);
        rt.push(lt.top());
        lt.pop();

        if (lt.size() < rt.size()) {
            lt.push(rt.top());
            rt.pop();
        }
    }

    double findMedian() {
        if (lt.size() > rt.size()) return lt.top();
        return (lt.top() + rt.top()) / 2.0;
    }
};


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


 