#include <stdio.h>
int* enqueue_front (int n, int arr[n], int rear, int front, int a[2])
{
    rear = a[0];
    front = a[1];
    int x;
    printf("\n Enter the value : ");
    scanf("%d",&x);
    if (rear == -1 && front == -1)
    {
        rear = 0;
        front = 0;
        arr[front] = x;
    }
    else if((rear == n-1 && front == 0) || front == rear + 1)
    {
        printf("\n Overflow");
    }
    else if (front == 0)
    {
        front = n-1;
        arr[front] = x;
    }
    else
    {
        front --;
        arr[front] = x;
    }
    a[0] = rear;
    a[1] = front;
    return a;
}
int* enqueue_rear(int n, int arr[n], int rear, int front, int a[2])
{
    rear = a[0];
    front = a[1];
    int x;
    printf("\n Enter the value : ");
    scanf("%d",&x);
    if (rear == -1 && front == -1)
    {
        rear = 0;
        front = 0;
        arr[rear] = x;
    }
    else if((rear == n-1 && front == 0) || front == rear + 1)
    {
        printf("\n Overflow");
    }
    else if (rear == n-1)
    {
        rear = 0;
        arr[rear] = x;
    }
    else
    {
        rear ++;
        arr[rear] = x;
    }
    a[0] = rear;
    a[1] = front;
    return a;
}
int* dequeue_rear(int n, int arr[n], int rear, int front, int a[2])
{
    rear = a[0];
    front = a[1];
    if (rear == -1 && front == -1)
    {
        printf("\n Undeflow");
    }
    else if (rear == front)
    {
        rear = -1;
        front = -1;
    }
    else if (rear == 0)
    {
        rear = n-1;
    }
    else
    {
        rear --;
    }
    a[0] = rear;
    a[1] = front;
    return a;
}
int* dequeue_front(int n, int arr[n], int rear, int front, int a[2])
{
    rear = a[0];
    front = a[1];
    if (rear == -1 && front == -1)
    {
        printf("\n Undeflow");
    }
    else if (rear == front)
    {
        rear = -1;
        front = -1;
    }
    else if (front == n-1)
    {
        front = 0;
    }
    else
    {
        front ++;
    }
    a[0] = rear;
    a[1] = front;
    return a;
}
void display_deque(int n, int arr[n], int rear, int front, int a[2])
{
    rear = a[0];
    front = a[1];
    if (rear == -1 && front == -1)
    {
        printf("\n Empty deque");
    }
    else
    {
        for (int i = front; i != rear; i = (i + 1) % n)
        {
            printf("\t %d ", arr[i]);
        }
        printf("\t %d ", arr[rear]);
    }
}
void get_rear (int n, int arr[n], int rear, int front, int a[2])
{
    rear = a[0];
    front = a[1];
    if (rear == -1 && front == -1)
    {
        printf("\n Empty deque");
    }
    else
    {
        printf("\n The rear value is \t %d", arr[rear]);
    }
}
void get_front (int n, int arr[n], int rear, int front, int a[2])
{
    rear = a[0];
    front = a[1];
    if (rear == -1 && front == -1)
    {
        printf("\n Empty deque");
    }
    else
    {
        printf("\n The front value is \t %d", arr[front]);
    }
}
int main()
{
    int n, rear = -1, front = -1, choice = 1;
    int a[2];
    a[0] = -1;
    a[1] = -1;
    printf("Enter the maximum size of the circular array : ");
    scanf("%d", &n);
    int arr[n];
    while (choice != 0)
    {
        printf("\n Press 1 for ENQUEUE from FRONT");
        printf("\n Press 2 for ENQUEUE from REAR");
        printf("\n Press 3 for DEQUEUE from FRONT");
        printf("\n Press 4 for DEQUEUE from REAR");
        printf("\n Press 5 for GETTING the FRONT");
        printf("\n Press 6 for GETTING the REAR");
        printf("\n Press 7 for displaying the deque");
        printf("\n Enter 0 for ENDING of the PROGRAM");
        printf ("\n Enter your choice : ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            int *p1;
            p1 = enqueue_front (n, arr, rear, front, a);
        }
        else if (choice == 2)
        {
            int *p2;
            p2 = enqueue_rear (n, arr, rear, front, a);
        }
        else if (choice == 3)
        {
            int *p3;
            printf("\n The front value is deleted if not Underflow");
            p3 = dequeue_front (n, arr, rear, front, a);
        }
        else if (choice == 4)
        {
            int *p4;
            printf("\n The rear value is deleted if not Underflow");
            p4 = dequeue_rear (n, arr, rear, front, a);
        }
        else if (choice == 5)
        {
            get_front (n, arr, rear, front, a);
        }
        else if (choice == 6)
        {
            get_rear (n, arr, rear, front, a);
        }
        else if (choice == 7)
        {
            display_deque(n, arr, rear, front, a);
        }
        else if (choice == 0)
        {
            printf("\n The program is ended");
        }
        else
        {
            printf("\n WRONG CHOICE");
        }
    }
    return 0;
}
