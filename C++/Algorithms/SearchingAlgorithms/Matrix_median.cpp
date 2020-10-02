/*A = { {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}   }
Find median using binary search. 
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int findval(vector<vector<int> > &A, ll pos){
    int rows = A.size();
    int cols = A[0].size();
    int l = INT_MAX;
    for(int i=0; i<rows; i++)
        l = min(l, A[i][0]);                    // find the minimum value from the entire matrix which 
                                                //    will be in first column of each row
    int r = INT_MIN;
    for(int i=0; i<rows; i++)
        r = max(r, A[i][cols-1]);               // find maximum from last column of each row.
    
    int mid;
    while(l<r){                                 // apply binary search ont he range 
        mid = (l+r)/2;
        int foundele = 0;
        for(int i=0; i<rows; i++)
            foundele += upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();      // get number of values less than mid
        if(foundele < pos)
            l = mid+1;
        else
            r = mid;
    }
    return l;
}

int findMedian(vector<vector<int> > &A) {
    
    int r = A.size();
    int c = A[0].size();
    int n = r*c;
    // if number of elements are even
    if(r*c%2 == 0){
        int val1 = findval(A, n/2);
        int val2 = findval(A, n/2+1);
        return (val1+val2)/2;
    }
    else{                                   // odd number of elements
        return findval(A, n/2+1);
    }
}

int main(){
    vector<vector<int>> A = {{1, 3, 5},{2, 6, 9},{3, 6, 9}};
    cout<<findMedian(A)<<endl;
}
