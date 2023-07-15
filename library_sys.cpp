#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#define ll long long
#define endl '\n'
#define FAST cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
using namespace std;
vector<pair<string,int>>nam_id;
vector<pair<string,int>>nam_qun;
vector<pair<string,string>>nam_book_borrwoed;
vector<pair<int,int>>id_qun;
vector<pair<string,int>>book_borrwoed;
vector<pair<string,int>>user_id;
void add_book();
void search_prefix();
void do_borrowd_name();
void print_byid();
void print_borrowed();
void print_byname();
void users_id();
void do_return_name();
void print_users();
int main() {
	//FAST;
        cout<<" choice from 1 to 10 services"<<endl;
        cout<<" simple explaining for library admin system \n 1-to adding book \n 2-to search for book by adding prefix \n 3-to print who borrwed books \n 4-print all details for book by id ascending order \n 5-print all details for book by name ascending order \n 6-to add user \n 7-to make Book borrowing process \n 8-Book returning process \n 9-print all details from users \n 10-to exit the program "<<endl;
        int service;
        cin>>service;
        if(service==1){
            add_book();
        }else if(service==2){
            search_prefix();
        }else if(service==3){
            print_borrowed();
        }
        else if(service==4){
            print_byid();
        }else if(service==5){
            print_byname();
        }else if(service==6){
            users_id();
        }
        else if(service==7){
            do_borrowd_name();
        }else if(service==8){
            do_return_name();
        }else if(service==9){
            print_users();
        }else if(service==10){
            cout<<"i wish you good day "<<endl;
            return 0;
        }
	
}
void search_prefix(){
    vector<string>srch;
    cout<<" enter book name or the prefix for it "<<endl;
    string key;
    cin>>key;
    for(int i=0;i<nam_qun.size();i++){
        int ff=0;
        string s=nam_qun[i].first;
        string comp;
         for(int j=0;j<key.size();j++){
            comp+=s[j];
         }         if(comp==key){
            srch.push_back(s);
         }
    }
    if(srch.size()==0){
        cout<<"no books with such prefix "<<endl;
    }else{
        for(int i=0;i<srch.size();i++){
            cout<<srch[i]<<endl;
        }
    }main();
}
void add_book(){
    cout<<" entre the book name , the book name and the book quantity "<<endl;
    string book;
    cin>>book;
    int id;
    cin>>id;
    int quamtity;
    cin>>quamtity;
    nam_id.push_back({book,id});
    nam_qun.push_back({book,quamtity});
    book_borrwoed.push_back({book,0});
    id_qun.push_back({id,quamtity});
    main();
}
void do_borrowd_name(){
    cout<<"enter your name and book name "<<endl;
    string user_name,book_name;
    cin>>user_name;
    cin>>book_name;
    nam_book_borrwoed.push_back({user_name,book_name});
    for(int i=0;i<book_borrwoed.size();i++){
        if(book_name==book_borrwoed[i].first){
            if(book_borrwoed[i].second==nam_qun[i].second){
            cout<<" sorry the book isnot avalible now "<<endl;
            main();
        }
        }
        if(book_borrwoed[i].first==book_name){
            book_borrwoed[i].second++;
        }
   
    
} main();
}
void print_byid(){
    int size=nam_id.size();
    int ids[size];
    string ams[10000];
    for(int i=0;i<size;i++){
        ids[i]=nam_id[i].second;
        ams[nam_id[i].second]=nam_id[i].first;
    }sort(ids,ids+size);
    for(int i=0;i<size;i++){
        cout<<" id =";
        cout<<ids[i]<<" name = "<<ams[ids[i]]<< " total_quantity ";
        int x=0,y=0;
         for(int j=0;j<size;j++){
            if(ams[ids[i]]==book_borrwoed[j].first){
                x=j;
                break;
            }
            }for(int b=0;b<size;b++){
                if(ams[ids[i]]==nam_qun[b].first){
                    y=b;
                break;
            }
         }cout<<nam_qun[y].second-book_borrwoed[x].second<<" total_borrowed "<<book_borrwoed[x].second<<endl;
    }main();

}void print_borrowed(){
    cout<< " enter book name "<<endl;
    string naming;
    int flag=1;
    cin>>naming;
    for(int i=0;i<nam_book_borrwoed.size();i++){
        if(naming==nam_book_borrwoed[i].second){
            cout<< nam_book_borrwoed[i].first<<endl;
            flag=0;
        }
    }if(flag){
        cout<<"Invalid book name."<<endl;
    }main();
  }void print_byname(){
    int size=nam_id.size();
    string ids[size];
    for(int i=0;i<size;i++){
        ids[i]=nam_id[i].first;
    }sort(ids,ids+size);
    for(int i=0;i<size;i++){
        cout<<" id = ";
        for(int j=0;j<size;j++){
            if(ids[j]==nam_id[j].first){
                cout<<nam_id[j].second;
                break;
            }
        }
        cout<<" name = "<< ids[i] << " total_quantity ";

        int x=0,y=0;
         for(int j=0;j<size;j++){
            if(ids[j]==book_borrwoed[j].first){
                x=j;
                break;
            }
            }for(int b=0;b<size;b++){
                if(ids[b]==nam_qun[b].first){
                    y=b;
                break;
            }
         }cout<<nam_qun[y].second-book_borrwoed[x].second<<" total_borrowed "<<book_borrwoed[x].second<<endl;
    }main();
}
void users_id(){
    cout<<" to click users enter name and id "<<endl;
    string nm;
    int idu;
    cin>>nm>>idu;
    user_id.push_back({nm,idu});
    main();
}void do_return_name(){
    cout<<" to return book enter your name and book name "<<endl;
    string name;
    string book_name;
    cin>>name>>book_name;
    int siz=nam_book_borrwoed.size();
    vector<pair<string,string>>::iterator it;
    int fff=0;
    for(int i=0;i<siz;i++){
        if(nam_book_borrwoed[i].first==name && nam_book_borrwoed[i].second==book_name){
            it=nam_book_borrwoed.begin()+i;
            nam_book_borrwoed.erase(it);
            fff=1;
            break;
        }
    }if(fff==0){
        cout<<"no book for this name is borrowed to return it "<<endl;
        main();
    } for(int i=0;i<siz;i++){
        if(book_name==book_borrwoed[i].first)
        {
            book_borrwoed[i].second--;
        }
    }
main();
}void print_users(){
    vector<string>booking;
    vector<int>idos;
    for(int i=0;i<user_id.size();i++){
        cout<<" user "<<user_id[i].first<<" id "<<user_id[i].second<<" borrowed book names: ";
            for(int j=0;j<nam_book_borrwoed.size();j++){
                if(nam_book_borrwoed[j].first==user_id[i].first){
                    cout<<nam_book_borrwoed[j].second<<" ";
                }
            }cout<<endl;
    }main();
}
































/*
cout << true && false;  ==1 wow --<< has higher precedence that &&. This is parsed as: (cout << true) && false. We did not mention << in the lecture for now. You should use: cout << (true && false);

n
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
