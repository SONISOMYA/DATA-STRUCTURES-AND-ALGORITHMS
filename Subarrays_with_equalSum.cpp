#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool divide(vector<int>arr){
    int prefix=0,totalSum=0,n=arr.size();
    //Total sum
     for(int i=0;i<n;i++)
     totalSum +=arr[i];

      for(int i=0;i<n;i++){
      prefix +=arr[i];
      int ans=totalSum-prefix;
      if(ans==prefix)
      cout<<ans<<endl;
      }
      return 0;

      

}



int main(){
    int n;
    cout<<"Enter the size of array: "<<endl;
    cin>>n;
    vector<int>v(n);

    cout<<"Enter the element of array : "<<endl;
    for (int i=0;i<n;i++){
        cin>>v[i];
    }

    cout<<divide(v);

    return 0;

    
}
