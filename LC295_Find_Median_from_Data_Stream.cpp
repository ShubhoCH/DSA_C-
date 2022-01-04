//Time:  O(N[No. of Elements]*logN[Insertion in HEAP])=>Insertion, O(1)=>Extraction;
//Space: O(N);
class MedianFinder {
private:
    priority_queue <int> maxH;
    priority_queue <int, vector<int>, greater<int>> minH;
    int size = 0;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(size == 0){
            maxH.push(num);
            size++;
            return;
        }
        if(size%2 == 0){
            if(num > minH.top()){
                int temp = minH.top();
                minH.pop();
                minH.push(num);
                maxH.push(temp);
            }else{
                maxH.push(num);
            }
        }
        else{
            if(num < maxH.top()){
                int temp = maxH.top();
                maxH.pop();
                maxH.push(num);
                minH.push(temp);
            }else{
                minH.push(num);
            }
        }
        size++;
    }
    
    double findMedian() {
        if(size%2!=0) return maxH.top();
        return (float)(maxH.top() + minH.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
