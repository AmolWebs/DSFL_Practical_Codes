#include<iostream>
using namespace std;

class Heap{
    public:
    int heap1[20],heap2[20],totalStudent;
    void getdata()
    {
        cout<<"Enter total no.of students : ";
        cin>>totalStudent;
        heap1[0],heap2[0] = 0; // o th index use for show no. of nodes and initially it is zero . 
        for(int i = 0;i<totalStudent;i++)
        {
            int mark;
            cout<<"Enter marks of student "<<i+1<<" : ";
            cin>>mark;
            insert1(heap1,mark);
            insert2(heap2,mark);
        }
    }
    void insert1(int heap1[],int x)
    {
        int n;
        n = heap1[0];
        heap1[n+1] = x;
        heap1[0] = n+1;
        int i = n+1;
        while(i>1 && heap1[i] > heap1[i/2])// below code for upadjust
        {
            int temp;
            temp = heap1[i];
            heap1[i] = heap1[i/2];
            heap1[i/2] = temp;
            i = i/2;
        }
    }

    void insert2(int heap2[],int x)
    {
        int n;
        n = heap2[0];
        heap2[n+1] = x;
        heap2[0] = n+1;
        int i = n+1;
        while(i>1 && heap2[i]<heap2[i/2])// below code for upadjust
        {
            int temp;
            temp = heap2[i];
            heap2[i] = heap2[i/2];
            heap2[i/2] = temp;
            i = i/2;
        }
    }

    void display(){   
        cout<<"Max Heap : "<<heap1[1]<<"\nMin Heap : "<<heap2[1]<<endl;
    }
};
int main()
{
    Heap hp;
    hp.getdata();
    hp.display();
}
