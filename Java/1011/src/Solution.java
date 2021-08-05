class Solution {
    public int shipWithinDays(int[] weights, int D) {
        int sum=0,max=weights[0];
        for (int i = 0; i < weights.length; i++) {
            sum+=weights[i];
            max=max>weights[i]?max:weights[i];
        }
        int l=max,r=sum;
        while(l<r){
            int mid=(l+r)/2;
            if(Cheak(weights,D,mid)){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return r;
    }
    private boolean Cheak(int []weights,int D,int mid){
        int n=weights.length;
        int cot=1;
        for(int i=1,sum=weights[0];i<n;sum=0,cot++){
            while(i<n&&sum+weights[i]<=mid){
                sum+=weights[i];
                i++;
            }
        }
        return cot-1<=D;
    }

}