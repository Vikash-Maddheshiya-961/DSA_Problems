class MyCircularQueue {
private:
    vector<int> cq;
    int rear;
    int front;
    int size;
public:
    MyCircularQueue(int k) {
        size = k;
        cq.resize(size);
        rear=-1;
        front=-1; 
    }
    
    bool enQueue(int value) {
        if(front == (rear+1)%size){
            return false;
        }else if(front == -1){
            front=rear=0;
        }else if(rear == size-1){
            rear = 0;
        }else{
            rear++;
        }
        cq[rear]=value;
        return true;
    }
    
    bool deQueue() {
        if(front == -1){
            return false;
        }else if(front == rear){
            front = rear = -1;
        }else if(front == size-1){
            front = 0;
        }else{
            front++;
        }
        return true;
    }
    
    int Front() {
        if(front == -1) return -1;
        return cq[front];
    }
    
    int Rear() {
        if(rear == -1) return -1;
        return cq[rear];
    }
    
    bool isEmpty() {
        if(front == -1){
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if(front == (rear+1)%size){
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */