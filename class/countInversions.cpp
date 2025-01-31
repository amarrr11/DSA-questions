



int mergeSort(vector<int>&nums,int start,int end){
    if(start>=end){
        return 0;
    }

    int mid=(start+end)/2;

    int inversionFirstHalf=mergeSort(nums,start,mid);
    int inversionSecHalf=mergeSort(nums,mid+1,end);
    return inversionFirstHalf+ inversionSecHalf + merge(nums,start,mid,end);
}

void merge(vector<int>&nums,int start,int end){
    vector<int> &tempMerged(nums.size());

    int resultIndex=0;
    int i=start;
    int j=mid;
    int inversions=0;

    while(i<=mid && j<=end){
        if( nums[i]<=nums[j]){
            tempMerged[resultIndex++]=nums[i++];
        }else{
            tempMerged[resultIndex++]=nums[j++];
            inversions+=(mid-i+1);
        }   
    }

    while(i<=mid){
        tempMerged[resultIndex++]=nums[i++];
    }
    while(j<=end){
        tempMerged[resultIndex++]=nums[j++];
    }
    
    for(int i=start;i<=end;i++){
        nums[i]=tempMerged[i];
    }
}