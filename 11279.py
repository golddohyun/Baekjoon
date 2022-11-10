import sys
input = sys.stdin.readline

class MaxHeap: 
    def __init__(self):
        self.arr = [0]
        
    def heap_insert(self, i):
        child = len(self.arr)
        self.arr.append(i) 
        parent = child//2 #부모노드는 1부터 가능 (child>=2)
        while parent > 0 :
            if self.arr[child] > self.arr[parent] :
                self.arr[child], self.arr[parent] = self.arr[parent], self.arr[child]
                child = parent
            else : break

    def delete_max(self) :
        if len(self.arr) == 1 : 
            res = 0
        else :
            self.arr[1], self.arr[-1] = self.arr[-1], self.arr[1]
            res = self.arr.pop()
            self.maxheapify(1)
        return res
    
    def maxheapify(self, i) :
        left = i*2
        right = i*2 +1
        largest = i
        if left < len(self.arr) and self.arr[left] > self.arr[largest]:
            largest = left
        if right < len(self.arr) and self.arr[right] > self.arr[largest]:
            largest = right
        if largest != i :
            self.arr[largest], self.arr[i] = self.arr[i], self.arr[largest]
            self.maxheapify(largest)

m = MaxHeap()
n = int(input())
for _ in range(n):
    key_in = int(input())
    if not key_in:
        print(m.delete_max())
    else:
        m.heap_insert(key_in)