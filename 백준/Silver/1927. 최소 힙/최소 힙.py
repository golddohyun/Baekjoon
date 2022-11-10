## MinHeap without using heapq module
import sys
input = sys.stdin.readline

class MinHeap: 
    def __init__(self):
        self.arr = [0]
        
    def heap_insert(self, i):
        cnt = len(self.arr)
        self.arr.append(i) 
        child = cnt
        while child//2 > 0 :
            parent = child//2 
            if self.arr[child] < self.arr[parent] :
                self.arr[child], self.arr[parent] = self.arr[parent], self.arr[child]
                child = parent
            else : break

    def delete_min(self) :
        if len(self.arr) == 1 : 
            res = 0
        else :
            self.arr[1], self.arr[-1] = self.arr[-1], self.arr[1]
            res = self.arr.pop()
            self.minheapify(1)
        return res
    
    def minheapify(self, i) :
        left = i*2
        right = i*2 +1
        smallest = i
        if left < len(self.arr) and self.arr[left] < self.arr[smallest]:
            smallest = left
        if right < len(self.arr) and self.arr[right] < self.arr[smallest]:
            smallest = right
        if smallest!= i :
            self.arr[smallest], self.arr[i] = self.arr[i], self.arr[smallest]
            self.minheapify(smallest)

m = MinHeap()
n = int(input())
for _ in range(n):
    key_in = int(input())
    if not key_in:
        print(m.delete_min())
    else:
        m.heap_insert(key_in)