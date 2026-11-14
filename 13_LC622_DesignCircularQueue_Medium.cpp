class MyCircularQueue {
public:
    int *arr;//so thaqt we can de4cide array size qat runtime 
    int front, rear, count, size;

    MyCircularQueue(int k) {
        arr = new int[k];

        front = 0;
        rear = 0;
        count = 0;
        size = k;
    }

    bool enQueue(int value) {
        if(count == size)
            return false;

        arr[rear] = value;
        rear = (rear + 1) % size;
        count++;

        return true;
    }

    bool deQueue() {
        if(count == 0)
            return false;

        front = (front + 1) % size;
        count--;

        return true;
    }

    int Front() {
        if(count == 0)
            return -1;

        return arr[front];
    }

    int Rear() {
        if(count == 0)
            return -1;

        return arr[(rear - 1 + size) % size];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == size;
    }

    ~MyCircularQueue() {
        delete[] arr;
    }
};
