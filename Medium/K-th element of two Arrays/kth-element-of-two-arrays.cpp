//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n1, int n2, int k)
    {
        if(n2<n1)  return kthElement(arr2,arr1,n2,n1,k);
        int low = max(k-n2,0);
        
        int  high = min(n1,k);
        
        while(low<=high){
            int mid1 = (low+high)/2;
            int mid2 = k - mid1;
            if(mid2 < 0 ) {
                high  = mid1 -1;
                continue;
            }
            int l1,l2,r1,r2;
            l1 = l2 = INT_MIN;
            r1 = r2 = INT_MAX;
            if(mid1<n1) r1 = arr1[mid1]; 
            if(mid2<n2) r2 = arr2[mid2]; 
            if(mid1 - 1 >= 0 ) l1 = arr1[mid1-1]; 
            if(mid2 - 1 >= 0 ) l2 = arr2[mid2-1]; 
            
            if(l1 <= r2 && l2 <= r1 ){
                return max(l1,l2);
            }
            else if(l1 > r2){
                high = mid1-1;
            }
            else low = mid1+1;
        }
        return 0;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends