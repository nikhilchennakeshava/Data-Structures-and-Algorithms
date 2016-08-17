#include <bits/stdc++.h>

#define SIZE 5

using namespace std;

int s[SIZE];
int top=-1;

bool isempty()
{
    if(top==-1)
        return true;
    else
        return false;
}

bool isfull()
{
    if(top==(SIZE-1))
        return true;
    else
        return false;
}

void push(int item)
{
    s[++top]=item;
}

int pop()
{
    return (s[top--]);
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
                        printf("stack full\n");
                    else
                    {
                        cout<<"enter element to push\n";
                        cin>>item;
                        push(item);
                    }
                    break;

            case 2:
                    if(isempty())
                        cout<<"stack empty\n";
                    else
                    {
                        item=pop();
                        cout<<"popped element is :"<<item<<endl;
                    }
                    break;

            case 3:
                    if(isempty())
                        printf("stack empty\n");
                    else
                    {
                        for(i=0;i<=top;i++)
                            cout<<s[i]<<"\t";
                    }
                    break;
            case 4:
                    exit(0);
        }
    }
    return 0;
}


