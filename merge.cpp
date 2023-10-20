# include <stdio.h>
void merge (int arr,int s,int e){
	int mid =(s+e)/2;
	int len1 =mid-s+1;
	int len2= e-mid;
	int first [len1];
	int second[len2];
	int k =mid+1;
	// copying the values 
	for (int i =0;i<len1;i++){
		first[i]=arr[k++];
	}
	for (int i =0;i<len2;i++){
		second[i]=arr[k++];
	}
//	merging the arays
	index1=0;
	index2=0; 
	originalarrayindex=s;
	while(index1<len1 && index2<len2){
		if (first[index1]<second[index2]){
			arr[originalarrayindex++]=first[index1++];
		}
		else {
			arr[originalarrayindex++]=second[index2++];
			
		}
	}
	while (index1<len1){
		arr[originalarrayindex++]=first[index1++];
	}
	while (index2<len2){
		arr[originalarrayindex++]=second[index2++];
	}
	

}
void mergesort(int arr,int s,int e){
	if (s>e){
		return ;
	}
	int mid = (s+e)/2;
	mergesort(arr,s,mid); // this will sort the left part of the array 
	mergesort(arr,mid+1,e); // this will sort the right part of the array 
}
int main () {
	int ar[1000];
	int n;
	scanf("%d",&n);
	printf("\n");
	printf("\n");
	for (int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	// this function will sort the array 
	mergesort(arr,0,n-1);
	printf("\n");
	printf("\n");
	// printing the sorted array 
	for (int i =0;i<n;i++){
		printf("%d ",arr[i]);
	}
}
