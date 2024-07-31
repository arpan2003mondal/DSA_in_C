# Bubble sort    # binary search
def bubble_sort(l,n):
    for i in range(0,n-1):
        for j in range(0,n-i-1):
            if(l[j]>l[j+1]):
                l[j],l[j+1]=l[j+1],l[j]
    
    
def binary_search(l,item,beg,end):
    mid=beg+end//2
    if(beg==end):
        if(l[beg]==item):
            return mid
        else:
            return -1
    if(beg<end):
       # mid=beg+end//2
        if(l[mid]==item):
            return mid
        elif item<l[mid]:
            return binary_search(l,item,beg,mid-1)
        else:
            return binary_search(l,item,mid+1,end)
        
    
l=[]
n=int(input("Enter the number of list elements: "))
print("Enter the list elements:")
for i in range(0,n):
    item=int(input())
    l.append(item)
bubble_sort(l,n)
print("After sorting the list is ",*l,sep=" ")
item=int(input("Enter the number you want to find: "))
key=binary_search(l,item,0,n)
if key==-1:
    print("Data not found")
else:
    print("Data is present at position ",key+1)
