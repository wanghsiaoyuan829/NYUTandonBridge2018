#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int a[20][20],p=0,q=0;
void step(int g,int h,int i,int &u,int &v);

/* Organism is the parent class here */

class Organism
{
    public :
    int x,y,life;
};

/* Both Bugs and ants inherit from Organism */

class Ant:public Organism
{
public:
    void birth(int e,int f)
    {
        x=e;
        y=f;
        life=0;
        a[e][f]=2;
        p++;
    }
    
    /* these are there three operations required to be performed according to the problem statement */
    void move();
    void breed();
    void death()
    {
        a[x][y]=0;
    }
}Ants[1000];  // this is a bugs objects array of size 1000

/* DoodleBugs also inherit from */

class DoodleBugs:public Organism
{
public:
    int steps;
    void birth(int e,int f)
    {
        x=e;
        y=f;
        life=3;
        steps=0;
        a[e][f]=1;
        q++;
    }
    void move();
    void breed();
    void death()
    {
        a[x][y]=0;
    }
}DoodleBugsle[1000];

/* function definitions */

void Ant::move()

{
    
    int k=0,t1,t2,i;
    
    life++;
    
    for(i=0;i<4;i++)
        
    {
        
        step(x,y,i,t1,t2);
        
        if(a[t1][t2]==0)
            
            k++;
        
    }
    
    if(k>0)
        
    {
        
        if(k!=1)
            
            k=(rand()%k+1);
        
        for(i=0;i<4,k>0;i++)
            
        {
            
            step(x,y,i,t1,t2);
            
            if(a[t1][t2]==0)
                
                k--;
            
        }
        
        a[x][y]=0;
        
        a[t1][t2]=2;
        
        x=t1;
        
        y=t2;
        
        if(life>=3)
            
        {
            
            this->breed();
            
            life=0;
            
        }
        
    }
    
}

void Ant::breed()

{
    
    int i,k=0,t1,t2;
    
    for(i=0;i<4;i++)
        
    {
        
        step(x,y,i,t1,t2);
        
        if(a[t1][t2]==0)
            
            k++;
        
    }
    
    if(k!=1)
        
        k=(rand()%k+1);
    
    for(i=0;i<4,k>0;i++)
        
    {
        
        step(x,y,i,t1,t2);
        
        if(a[t1][t2]==0)
            
            k--;
        
    }
    
    Ants[p].birth(t1,t2);
    
}

void shiftb();

void shiftd();

void DoodleBugs::move()

{
    
    int k=0,t1,t2;
    
    steps ++;
    
    for(int i=0;i<4;i++)
        
    {
        
        step(x,y,i,t1,t2);
        
        if(a[t1][t2]==2)
            
            k++;
        
    }
    
    if(k==0)
        
        life--;
    
    else
        
    {
        
        if(k!=1)
            
            k=(rand()%k+1);
        
        for(int i=0;i<4,k>0;i++)
            
        {
            
            step(x,y,i,t1,t2);
            
            if(a[t1][t2]==2)
                
                k--;
            
        }
        
        life=3;
        
        for(int j=0;j<p;j++)
            
        {
            
            if((Ants[j].x==t1)&&(Ants[j].y==t2))
                
            { Ants[j].death();
                
                shiftb();
                
            }
            
        }
        
        a[this->x][this->y]=0;
        
        a[t1][t2]=1;
        
        this->x=t1;
        
        this->y=t2;
        
    }
    
    if(steps>=8)
        
        this->breed();
    
    if(life<=0)
        
        this->death();
    
}

void DoodleBugs::breed()

{
    
    int i,k=0,t1,t2;
    
    for(i=0;i<4;i++)
        
    {
        
        step(x,y,i,t1,t2);
        
        if(a[t1][t2]==0)
            
            k++;
        
    }
    
    if(k>0)
        
    {
        
        if(k!=1)
            
            k=(rand()%k+1);
        
        for(i=0;i<4,k>0;i++)
            
        {
            
            step(x,y,i,t1,t2);
            
            if(a[t1][t2]==0)
                
                k--;
            
        }
        
        DoodleBugsle[q].birth(t1,t2);
        
    }
    
}

/* Display function */

void display()

{
    
    int i,j;
    
    char c;
    
    system("cls");
    
    for(i=0;i<20;i++)
        
    {
        
        for(j=0;j<20;j++)
            
        {
            
            if(a[i][j]==0)
                
                c='-';
            
            if(a[i][j]==1)
                
                c='x';
            
            if(a[i][j]==2)
                
                c='o';
            
            cout<<c<<" ";
            
        }
        
        cout<<"\n";
        
    }
    
}

/* steps function */

void step(int g,int h,int i,int &u,int &v)

{
    
    u=g;
    
    v=h;
    
    if(i==0)
        
        u--;
    
    if(i==1)
        
        v++;
    
    if(i==2)
        
        u++;
    
    if(i==3)
        
        v--;
    
    if(u<0||v<0||u>19||v>19)
        
    {
        
        u=g;
        
        v=h;
        
    }
    
}

/* shiftb and shiftd functions */

void shiftb()

{
    
    int j,k;
    
    if(p!=1)
        
        for( j=0;j<p;)
            
        {
            
            if(a[Ants[j].x][Ants[j].y]==0)
                
            {
                
                p--;
                
                for(int k=j;k<p;k++)
                    
                    Ants[k]=Ants[k+1];
                
            }
            
            else
                
                j++;
            
        }
    
    if(p==1)
        
        if(a[Ants[0].x][Ants[0].y]==0)
            
            p--;
    
}

void shiftd()

{
    
    int j,k;
    
    if(q!=1)
        
        for( j=0;j<q;)
            
        {
            
            if(a[DoodleBugsle[j].x][DoodleBugsle[j].y]==0)
                
            {
                
                q--;
                
                for(int k=j;k<q;k++)
                    
                    DoodleBugsle[k]=DoodleBugsle[k+1];
                
            }
            
            else
                
                j++;
            
        }
    
    if(q==1)
        
        if(a[DoodleBugsle[0].x][DoodleBugsle[0].y]==0)
            
            q--;
    
}

/* Driver program */

int main()

{
    
    int m,n,i,j,s,t;
    
    char ch='y';
    
    s = 5;
    
    t = 100;
    
    for(i=0;i<20;i++)
        
        for(j=0;j<20;j++)
            
            a[i][j]=0;
    
    srand(time(NULL));
    
    for(i=0;i<s;i++)
        
    {
        
        do {
            
            m=rand()%20;
            
            n=rand()%20;
            
        }while(a[m][n]!=0);
        
        DoodleBugsle[i].birth(m,n);
        
    }
    
    for(i=0;i<t;i++)
        
    {
        
        do{
            
            m=rand()%20;
            
            n=rand()%20;
            
        }while(a[m][n]!=0);
        
        Ants[i].birth(m,n);
        
    }
    
    display ();
    
    ch=cin.get();
    
    while(true)
        
    {
        
        for(i=0;i<q;i++)
            
            DoodleBugsle[i].move();
        
        shiftd();
        
        for(i=0;i<p;i++)
            
            Ants[i].move();
        
        display();
        
        cout<<"Press Enter for next";
        
        ch=cin.get();
        
    }
    
}
