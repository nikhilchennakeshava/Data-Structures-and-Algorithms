#include<bits/stdc++.h>
using namespace std;

long higher(long num)
{
    long temp,t,n,number[1<<10],a,b;
    int i=0,j=0,k=0;
    temp=num;

    while(temp)
    {
        number[i]=temp%10;
        temp=temp/10;
        i++;
    }
    n=i;

    //reverse array
    int start=0,end=n-1,tempp;
    while (start < end)
    {
        tempp = number[start];
        number[start] = number[end];
        number[end] = tempp;
        start++;
        end--;
    }

    //to find the first inversion
    //  Start from the right most digit and find the first digit that is
    // smaller than the digit next to it.
    for (i = n-1; i > 0; i--)
        if (number[i] > number[i-1])
           break;
    long inv=i;
    //cout<<"\ninv:"<<inv;


    //if no inversions then return original number
    if(inv==0)
        return num;

    // after that Find the smallest digit on right side of (i-1)'th digit that is
    // greater than number[i-1]
    int x = number[i-1], smallest = i;
    for (j = i+1; j < n; j++)
        if (number[j] > x && number[j] < number[smallest])
            smallest = j;

    // next Swap the above found smallest digit with number[i-1]
    swap(number[smallest], number[i-1]);

    // now Sort the digits after (i-1) in ascending order
    sort(number+i, number+n);

    t=0;
    for(i=0;i<n;i++)
    {
        t=t+number[i]*pow(10,n-i-1);
    }

    return t;


    /*
    this doesnt work well for all cases

    a=number[0];
    for(i=1;i<n;i++)
    {
        if(a>number[i])
        {
            inv=i;
            swap(number[0],number[i]);
            break;
        }
    }
    if(inv==-1)
        return num;

    if(inv>1)
    {
        for(i=0;i<inv-1;i++)
            for(j=0;j<inv-i-1;j++)
                if(number[j]<number[j+1])
                    swap(number[j],number[j+1]);
    }
    
    t=0;
    for(i=0;i<n;i++)
    {
        t=t+number[i]*pow(10,i);
        
    }
    return t;*/
}

int main()
{
    long num;
    cin>>num;
    num=higher(num);
    cout<<"Next number : "<<num<<endl;
    return 0;
}
