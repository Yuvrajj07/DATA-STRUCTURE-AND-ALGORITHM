# include <bits/stdc++.h>
using namespace std;
class heap{
	public:
		int arr[100];
		int size;
		heap(){
			arr[0]=-1;
			size=0;
		}
		
	// inserting elements in the heap
		
		void insert(int val){
			size = size+1;
			int index=size;
			 arr[index]=val;
			while (index>1){
				int parent =index/2;
				if (arr[parent]<arr[index]){
					swap(arr[parent],arr[index]);
					index=parent;
				}
				else {
				return ;
					}			
				}
			}
	
	// function for dealeting from the heap
	
			void deleteheap(){
				if (size==0){
					cout<<"heap is empty : nothing to delete "<<endl;
					return ;
				}

				arr[1]=arr[size];
				size--;
				
	//taking root node to its correct position 
				
				int i=1;
				while (i<size){
					int rightIndex=2*i+1;
					int leftIndex= 2*i;
					if (leftIndex<size && arr[i]<arr[leftIndex]){
						swap(arr[i],arr[leftIndex]);
						i=leftIndex;
					}
					else if (rightIndex<size && arr[i]<arr[rightIndex]){
						swap(arr[i],arr[rightIndex]);
						i=rightIndex;
					}
					else {
						return ;
					}
				}
			}
			
	//printing elements of the heap

	void print(){
		for (int i =1;i<=size;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
};

	// heapify function 
	
			void heapify(int arr[],int n,int i){
				int largest=i;
				int right=2*i+1;
				int left = 2*i;
				if (left<=n && arr[largest]<arr[left]){
					largest=left;
				}
				if (right<=n && arr[largest]<arr[right]){
					largest=right;
				}
				if (largest !=i){
					swap(arr[i],arr[largest]);
					heapify(arr,n,largest);
				}
			}

	//implementing heap sort
	
	void heapsort(int arr[],int n){
		 
		int size =n;
		while (size>1){
		//step : 1 -->  swap
		swap(arr[1],arr[size]);
		//step :2 decrement the size of the array
		size--;
		//step:3 heapify the array 
		heapify(arr,size,1);
	}
	}
int main (){
	heap h;
	h.insert(50);
	h.insert(55);
	h.insert(53);
	h.insert(52);
	h.insert(54);
	h.print();
	h.deleteheap();
	h.print();
	
	// doing heapify on a array
	int arr[6]={-1,54,53,55,52,50};
	int  n=5;
	for (int i =n/2;i>0;i--){
		heapify(arr,n,i);
	}
	cout<<"printing the array "<<endl;
	for (int i =1;i<=n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	int unsrt[5]{5,9,7,6,3};
	cout<<"after heap sort the array will be "<<endl; 
	heapsort(arr,n);
	for (int i =1;i<=n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	// applying heap sort on the secon array
	cout<<"heap sort on the second(unsrt) array --> "<<endl;
	heapsort(unsrt,5);
	for (int i =0;i<5;i++){
		cout<<unsrt[i]<<" ";
	}
	cout<<endl;
}
/*
it may possible :
note :  
1)-->  it will sort the array from the first index not the zeroth index  
2)--> it is one based indexing so the array will not be sorted from the begining 
*/
