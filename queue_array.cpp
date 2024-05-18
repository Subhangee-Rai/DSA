#include <iostream>
using namespace std;
using std::string;

struct queue
{
    int size, f, r; // f=front & r=rear of queue
    int *arr;
};
int isfull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}
int isempty(struct queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}
void enqueue(struct queue *q, int val)
{
    if (isfull(q))
    {
        cout << "This queue is full" << endl;
        return;
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}
int dequeue(struct queue *q)
{
    int a = -1;
    if (isempty(q))
    {
        cout << "This queue is empty" << endl;
        exit(0);
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}
int main()
{
    struct queue q;
    q.size = 100;
    q.f = q.r = -1;
    q.arr = new int();
    if (isempty(&q))
    {
        cout << "Queue is empty" << endl;
    }
    // enqueue elements
    enqueue(&q, 12);
    enqueue(&q, 13);
    enqueue(&q, 14);
    if (isempty(&q))
    {
        cout << "Queue is empty" << endl;
    }

    // dequeue
    cout << "Dequeue element: " << dequeue(&q) << endl;
    cout << "Dequeue element: " << dequeue(&q) << endl;
    cout << "Dequeue element: " << dequeue(&q) << endl;
    cout << "Dequeue element: " << dequeue(&q) << endl;

    return 0;
}