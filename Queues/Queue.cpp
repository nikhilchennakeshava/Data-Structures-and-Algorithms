#include <bits/stdc++.h>

#define SIZE 10

using namespace std;

int q[SIZE];
int front=-1,rear=-1;

bool isempty()
{
    if(front==rear)
        return true;
    else
        return false;
}

bool isfull()
{
    if(rear==(SIZE-1))
        return true;
    else
        return false;
}

void push(int item)
{
    q[++rear]=item;
}

int pop()
{
    return (q[++front]);
}

int main()
{
    int opt,i;
    int item;

    while(1)
    {
        cout<<"\nMenu:\nEnter 1 for push 2 for pop 3 for display 4 to exit\n";
        cin>>opt;

        switch(opt)
        {
            case 1:
                    if(isfull())
                        printf("Queue full\n");
                    else
                    {
                        cout<<"enter element to push\n";
                        cin>>item;
                        push(item);
                    }
                    break;

            case 2:
                    if(isempty())
                        cout<<"Queue empty\n";
                    else
                    {
                        item=pop();
                        cout<<"popped element is :"<<item<<endl;
                    }
                    break;

            case 3:
                    if(isempty())
                        printf("Queue empty\n");
                    else
                    {
                        for(i=front+1;i<=rear;i++)
                            cout<<q[i]<<"\t";
                    }
                    break;
            case 4:
                    exit(0);
        }
    }
    return 0;
}



