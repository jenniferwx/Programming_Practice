'''
find k smallest number in a large array
'''
import heapq

def Minheap(array,m):
    h = []
    for i in array:
        if len(h)<m:
           heapq.heappush(h,-1*i)
        elif len(h)==m:
           heapq.heappushpop(h,-1*i)
           
    return h       

if __name__=="__main__":
   array = [10,4,62,18,2,1,9,34,87,123,20,0,76,21,86,4]
   N = 4
   L = Minheap(array,N)
   L= map(lambda x:-1*x,L)
   print L
