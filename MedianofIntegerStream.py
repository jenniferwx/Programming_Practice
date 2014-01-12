'''
Given a stream of unsorted integers, find the median element in sorted order at any given time. So, we will be 
receiving a continuous stream of numbers in some random order and we don’t know the stream length in advance. 
Write a function that finds the median of the already received numbers efficiently at any time. We will be asked 
to find the median multiple times. Just to recall, median is the middle element in an odd length sorted array, 
and in the even case it’s the average of the middle elements.
'''

# Solution: MaxHeap and MinHeap. Complexity:  O(1) find heap and O(logN) insert
# reference: http://www.ardendertat.com/2011/11/03/programming-interview-questions-13-median-of-integer-stream/

class streamMedian: 
    def __init__(self): 
        self.minHeap, self.maxHeap = [], [] 
        self.N=0   
    
    def insert(self, num): 
        if self.N%2==0: 
           heapq.heappush(self.maxHeap, -1*num)  #Note: "heapq" module provides an implementation of min-heap only 
           self.N+=1 
           if len(self.minHeap)==0: 
              return 
           if -1*self.maxHeap[0]>self.minHeap[0]: 
              toMin=-1*heapq.heappop(self.maxHeap) 
              toMax=heapq.heappop(self.minHeap) 
              heapq.heappush(self.maxHeap, -1*toMax) 
              heapq.heappush(self.minHeap, toMin) 
         else: 
           toMin=-1*heapq.heappushpop(self.maxHeap, -1*num) 
           heapq.heappush(self.minHeap, toMin) 
           self.N+=1  
    
    def getMedian(self): 
        if self.N%2==0: 
           return (-1*self.maxHeap[0]+self.minHeap[0])/2.0 
        else: 
           return -1*self.maxHeap[0]
