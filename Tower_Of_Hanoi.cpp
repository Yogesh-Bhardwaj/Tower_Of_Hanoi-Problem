#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<windows.h>
using namespace std;

class Rods
{
    int N;
    vector<string> v;
    public:
        vector<stack<int>> V;
        Rods(int n)
        {
            N = n;
            
            for(int i=0;i<3;i++)
            V.push_back(stack<int>());

            for(int i=N;i>0;i--)
            V[0].push(i);


            int shift = to_string(n).length() + 5;

            string a(6*n + 11 + shift,' ');
            a[n+1 + shift] = a[3*n+5 + shift] = a[5*n+9 + shift] = '|';
            
            for(int i=1;i<=(n+1);i++)
            v.push_back(a);
            
            v[n] = string(6*n + 11 + shift,'_');
            for(int j=0;j < shift;j++)
            v[n][j] = ' ';
            v[n][n+1 + shift] = v[n][3*n+5 + shift] = v[n][5*n+9 + shift] = '|';
            v[n][2*n+3 + shift] = v[n][2*(2*n+3) + 1 + shift] = ' ';
            
            string b(6*n+11+shift,' ');
            b[n+1 + shift] = 'A';b[3*n+5 + shift] = 'B';b[5*n+9 + shift] = 'C';
            v.push_back(b);

            for(int i=0;i<n;i++)
            {
                string temp = to_string(i+1);

                for(int j= n-i-temp.length() + shift;j<n-i + shift;j++)
                v[i][j] = temp[j-n + i + temp.length() - shift];
                
                for(int j = n-i + shift;j<=(n+i+2 + shift);j++)
                {
                    if(j == (n+1 + shift))
                    continue;
                    v[i][j] = '_';
                }
            }
        }
        void transfer(char a,char b)
        {
            int n = N;
            int shift = to_string(n).length() + 5;
            int source = a - 'A',destination = b - 'A';
            int to_be_transfered = 0;

            int temp = shift + n + source*(2*n+4);
            int tem = 2*(temp+1);
            
            for(int i=0;i<n;i++)
            if(v[i][temp] == '_')
            {
                while(v[i][temp] == '_')
                {
                    v[i][temp] = ' ';
                    v[i][tem - temp] = ' ';
                    temp--;
                    to_be_transfered++;
                }
                while(v[i][temp] != ' ')
                {
                    v[i][temp] = ' ';
                    temp--;
                }
                break;
            }
            
            cout<<"Transfer disk "<<to_be_transfered<<" from "<<a<<" to "<<b<<endl<<endl;
            
            V[b-'A'].push(V[a-'A'].top());
            V[a-'A'].pop();
            
            temp = shift + n + destination*(2*n+4);
            int center  = temp+1;
            
            for(int i=n-1;i>=0;i--)
            if(v[i][temp] == ' ')
            {
                string numm = to_string(to_be_transfered);
                int l = numm.length();
                for(int j= center-to_be_transfered - l;j < center-to_be_transfered;j++)
                v[i][j] = numm[j-(center-to_be_transfered - l)];
                for(int j = center - to_be_transfered;j<=center + to_be_transfered;j++)
                {
                    if(j == center)
                    continue;
                    v[i][j] = '_';
                }
                break;
            }

        }
        void display()
        {
            for(auto i:v)
            cout<<i<<endl;
            cout<<endl;
            cout<<"...\b\b\b\b";
            Sleep(1500);
            cout<<"    ";
            cout<<endl;
        }
        void Move_Disk_between_rods(char s,char d)
        {
            stack<int> S = V[s-'A'];
            stack<int> D = V[d-'A'];
            if(D.empty())
            {
                transfer(s,d);
                display();
            }
            
            else if(S.empty())
            {
                transfer(d,s);
                display();
            }

            else{
                if(S.top() > D.top())
                {
                    transfer(d,s);
                    display();
                }
                
                else
                {
                    transfer(s,d);
                    display();
                }
            }
        }
};

void towerofHanoi_Recursive(Rods &T,int n, char src, char dest, char helper)
{
    static int step=0;
    if(n==0)
    return;
    
    towerofHanoi_Recursive(T,n-1,src, helper, dest);
    
    cout<<"Step "<< (++step) << " - ";
    T.transfer(src,dest);
    T.display();

    
    towerofHanoi_Recursive(T,n-1,helper,dest ,src);
}

void towerofHanoi_NonRecursive(Rods &T,int n)
{
    char src = 'A',dest = 'C',helper  = 'B';
    int no_of_moves = (1<<n) - 1;
    int step = 0;
    if(n % 2 == 0)
    swap(dest,helper);
    
    for(int i=1;i<= no_of_moves;i++)
    {
        cout<<"Step "<< (++step) << " - ";
        if(i%3 == 1)
        T.Move_Disk_between_rods(src,dest);
        else if(i%3 == 2)
        T.Move_Disk_between_rods(src,helper);
        else
        T.Move_Disk_between_rods(helper,dest);
    }
}


int main()
{
    cout<<"Enter number of disks in the first rod : ";
    int n;cin>>n;
    Rods t(n);

    cout<<"\nInitially\n\n";
    t.display();
    towerofHanoi_NonRecursive(t,n);
    
    cout<<"\nAll the disks are transfered from A to C\n";

    return 0;
}