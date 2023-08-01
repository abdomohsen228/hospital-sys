 #include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#define ll long long
#define endl '\n'
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int speclization[20][5];
deque<pair<int,string>>adding;
void add_new_pation();
void print_all_pation();
void get_next_patient();
int main() {
    cout<<"hello sir i wish you will be good isa"<<endl;
    int do_thing=0;
    cout<<" if you need to rent with doctor enter 1 ..if you want to see all pation enter 2 ... to next pation 3 ..and to exit enter 4"<<endl;
    cin>>do_thing;
    if(do_thing==1){
        add_new_pation();
    }else if(do_thing==2){
        print_all_pation();
    }else if(do_thing=3){
        get_next_patient();
    }else{
        return 0;
    }
}
void add_new_pation(){
    cout<<"enter your speclization"<<endl; 
    int spec_number;
    cin>>spec_number;
    cout<<"enter your name"<<endl;
    int pat_count=0;
    for(int i=0;i<adding.size();i++){
        if(adding[i].first==spec_number){
            pat_count++;
        }
    }if(pat_count>5){
        cout<<"soryy we canot add more patient in speciliaztion "<<spec_number<<endl;
        main();
    }
    string name;
    cin>>name;
        cout<<"enter your satis"<<endl; 
    int stat;
    cin>>stat;
    if(stat==0){
        name=name+'0';
        adding.push_back({spec_number,name});
    }else if(stat==1){
        name=name+'1';
        adding.push_front({spec_number,name});
    }else{
        cout<<"sorry sir itis 0  for regular or 1 for urgent "<<endl;
        main();
    }
    main();
}void print_all_pation(){
    cout<<"enter your specilzion you need to see its patients"<<endl;
    int spec=0;
    cin>>spec;
    cout<<endl;
    int cont=0;
    for(int i=0;i<adding.size();i++){
        if(adding[i].first==spec){
            cont++;
        }
    }cout<<"there are "<<cont<<" patients in specilization "<<spec<<endl;
    for(int i=0;i<adding.size();i++){
        if(adding[i].first==spec){
            string trasion=adding[i].second;
            int size_of_it=trasion.size();
            if(trasion[size_of_it-1]=='0'){
                trasion[size_of_it-1]=' ';
                cout<<trasion<<"regular"<<endl;
            }else{
                trasion[size_of_it-1]=' ';
                cout<<trasion<<"unrgent"<<endl;
            }
        }
    }
    main();
}void get_next_patient(){
    int spc=0;
    cout<<"enter the specilizatio"<<endl;
    cin>>spc;
    int f=0;
     for(int i=0;i<adding.size();i++){
        if(adding[i].first==spc){
            f=1;
            break;
        }
     }if(f==0){
        cout<<"no pationt at the moment .have rest ,Dr"<<endl;
     }else{
        string go_on=adding[0].second;
        go_on[go_on.size()-1]=' ';
        cout<<go_on<<"please go with Dr"<<endl;
        auto it=adding.begin();
        adding.erase(it);
     }
     main();
}




































/*
cout << true && false;  ==1 wow --<< has higher precedence that &&. This is parsed as: (cout << true) && false. We did not mention << in the lecture for now. You should use: cout << (true && false);



int y=x+ ++x; if x=1,y=4; ++x is first

b=3 
a=b++
a=3
b=4
----
b=3
a=++b
b=4
a=4
()-- /*% -- -
*/
/* const int DAYS = 7; 			//number of strings in array
const int MAX = 10; 			//maximum size of each string

char star[DAYS][MAX] = { “Sunday”, “Monday”, “Tuesday”, “Wednesday”, “Thursday”, “Friday”, “Saturday” };	//array of strings*/

/*    string s="Ali Khaled al-naggar";
int index=s.find("al")  البحث عن أول ظهور ة: * ;
if(index==string::npos)
cout<<"Not found\n";
else
cout<<index<<'\n';
*/





















/*fast   gcd
    ll int n,k;
    cin>>n>>k;
    vector<ll>v;
    v.push_back(n);
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            v.push_back(i);
            if(i*i<n){
                v.push_back(n/i);
            }
        }
    }ll siz=v.size();
    //cout<<siz<<endl;
    sort(v.begin(),v.end());
    if(k<siz){
       cout<<v[k-1];
    }else{
        cout<<-1;
    }*/

// int n;
//  cin>>n;
//  int arr[n];int ans;
//  for (int i =0 ; i<n ;i++){
//      cin>>arr[i];
//  }for (int i=1; i<n ;i++){
//      arr[i]=arr[i]+arr[i-1];
//  }int q; cin>>q;
//  while (q--){
//      int l,r;
//      cin>>l>>r;
//      ans=arr[r];
//      if (l>0){
//          ans-=arr[l-1];
//      }cout<<ans<<endl;
//          }

// }
/*#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n=10,x;cin>>x;
    vector<int>v ={1,2,3,4,5,6,7,8,9};
    int l=0, r=n-1;
    while(l<=r){
        int mid=(l+r)/2;
        if (v[mid] ==x){
            cout<<"yes" ;return 0;
        }else if (v[mid]<x){
            l= mid+1;
        } else {
            r=mid-1;
        }
    }*/

/*void fac(int x){
    if(x==0){
        return ;
    }else{
        cout<<x%10<<endl;
        fac(x/10);
    }
}
int main()
{
    int x;0
    cin>>x;
    fac(x);

}*/

/*int fac(int x,int y){
    if(x==y){
        return x;
    }else{
        return y+fac(x,y-1);
    }

}
int main()
{
    int x,y;
    cin>>x>>y;
    cout<<fc(x,y)

}*/
/*int fac(int x){
    if(x==0|| x==1){;
        return x;
    }else{
        return x+fac(x-1);
    }

}int main()
{
    int c;
    cin>>c;
    cout<<fac(c);
}*/

/*int fac(int x){
    if(x==0 || x==1){
        return x;
    }else{
        return fac(x-1)+fac(x-2);
    }

}int main()
{
    int x;
    cin>>x;
    cout<<fac(x);

}*/
/*int fac(int x){
    if(x==0){
        return 1;
    }else{
        return x*fac(x-1);
    }
}int main()
{
    int x;
    cin>>x;
    cout<<fac(x);
}*/

/*void f(int n){
    if(n<1){//based case
        return;
    }else{
        cout<<"round: "<<n<<endl;//logic
        f(n-1);//call by it self (sub problem)
    }
}
int main(){
    int x;
    cin>>x;
    f(x);
}*/
