class MyCircularDeque {
public:
    int *arr;
    int front, rear, count, size;

    MyCircularDeque(int k) {
        arr = new int[k];
        front = -1;
        rear = -1;
        count = 0;
        size = k;
    }

    bool insertFront(int value) {
        if(count == size)
            return false;

        if(count == 0) {
            front = rear = 0;
        }
        else if(front == 0) {
            front = size - 1;
        }
        else {
            front--;
        }

        arr[front] = value;
        count++;

        return true;
    }

    bool insertLast(int value) {
        if(count == size)
            return false;

        if(count == 0) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % size;
        }

        arr[rear] = value;
        count++;

        return true;
    }

    bool deleteFront() {
        if(count == 0)
            return false;

        if(front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % size;
        }

        count--;
        return true;
    }

    bool deleteLast() {
        if(count == 0)
            return false;

        if(front == rear) {
            front = rear = -1;
        }
        else if(rear == 0) {
            rear = size - 1;
        }
        else {
            rear--;
        }

        count--;
        return true;
    }

    int getFront() {
        if(count == 0)
            return -1;

        return arr[front];
    }

    int getRear() {
        if(count == 0)
            return -1;

        return arr[rear];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == size;
    }

    ~MyCircularDeque() {
        delete[] arr;
    }
};
