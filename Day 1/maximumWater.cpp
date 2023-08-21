class Solution {
private:
int nextIndex(vector<int>& height,int element,int index){
    int ans ;
    for(int j = height.size()-1;j>=index;j--){
        if(height[j]>=element){
            ans = j;
            break;
        }
        else{
            ans = index;
            }
        }
    return ans;
}
int prevIndex(vector<int>& height,int element,int index){
    int ans ;
    for(int j = 0;j<=index;j++){
        if(height[j]>=element){
            ans = j;
            break;
        }
        else{
            ans = index;
            }
        }
    return ans;
}
public:
    int maxArea(vector<int>& height) {
        int ans = INT_MIN;
        int n = height.size();
        int j = 0;
        int prevInd, currInd;
        for(int i = n-1 ; i>=0; i--){
            int curr = height[i];
            int prevInd = prevIndex(height,curr,i);
            int nextInd = nextIndex(height,curr,i);
            int area = curr*(nextInd - prevInd);
            ans = max(ans,area);    
        }
        return ans;
    }
};
