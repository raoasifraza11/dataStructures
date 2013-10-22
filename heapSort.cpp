
#include <stdio.h>
#include <math.h>


void swap(int *a, int *b){
 if(*a == *b)
 return;
  int temp = *a;
  *a = *b;
  *b = temp;     
return;
}



void maxHeapify(int *iArr, int iLen, int iIndex, int iHeapSize){

 int iLargest =  iIndex; //initializing it with the default index of the parent
 int iLeftIndex = 2*iIndex,
     iRightIndex = 2*iIndex + 1,
	 iLeftChild = iArr[iLeftIndex],
     iRightChild = iArr[iRightIndex];
     
 if( iLeftChild > iArr[iLargest] && (iLeftIndex < iHeapSize)/* Left child's index 2*i doesnt go out of bound*/){
     iLargest = iLeftIndex;
     }
 if( iRightChild >  iArr[iLargest]  && (iRightIndex < iHeapSize/* Right child's index 2*i doesnt go out of bound*/)){
     iLargest = iRightIndex;
     } 
     
     if(iLargest != iIndex){  //if the parent is not largest element, swap it and call max-heapify on the largest element now
        swap(&iArr[iLargest], &iArr[iIndex]);
        maxHeapify(iArr, iLen, iLargest,iHeapSize);         
     } 
     

}


void buildMaxHeap(int *iArr, int iLen,int iHeapSize){
 for(int i =iLen/2 ; i >=0   ; i--){
  maxHeapify(iArr, iLen, i,iHeapSize);       
 }    
 return;
}


void heapSort(int *iArr, int iLen, int iHeapSize){
     
 buildMaxHeap(iArr, iLen, iHeapSize);
 iHeapSize = iLen;
 for(int i = iLen-1 ;i > 0 ;i--){
        swap(&iArr[0], &iArr[i]) ;
        iHeapSize = iHeapSize -1 ;
        maxHeapify(iArr, iLen, 0,iHeapSize);  
 }     

return;
}


void vPrintArr(int *iArr, int iLen){
     for(int i = 0 ; i < iLen ; i++){
        printf("%d ", iArr[i]);       
     }

}

int main(){
  int iArr[] = {3,2,5,7,9,1,4};
  int iLen = sizeof(iArr)/sizeof(iArr[0]);
  int iHeapSize = iLen;
  heapSort(iArr, iLen,iHeapSize);
  vPrintArr(iArr, iLen);
  getchar();
  return 0;     
}
