#lists: mutable
#Empty list
l1 = []
print(l1)
print('Size of list', len(l1))

l2 = [1,2,3,4,100]
print(l2)
#slicing
#print first 3 elements (from indices 0,1,2)
print(l2[:3])
#print elements from index 2 to index 4
print(l2[2:5])
#print last element
print(l2[-1])

l2.clear()
print('After clearing the list:', l2)

l2.append(1)
l2.append(2)
l2.append(10)
l2.append(15)

print('New list is:', l2)

#delete last element
l2.pop()
print('After deletion of last elem:', l2)

#remove from specific index
l2.pop(1)
print('After deletion from index 1:', l2)

#modify element at specific index
l2[0] = 100
print('After modifications:', l2)

l2.clear()

#list with mixed types
l2 = ['Hello', 12, ['1','2','3'], 8]
for i, element in enumerate(l2):
    print('Element at position', i, 'is', element, 'with type', type(element))
    #check if current element is list
    if isinstance(element, list):
        #can also write element[0]
        print('First elem of nested list', l2[i][0])

#concatenate two lists
l1 = [1, 2]
l3 = [3, 4]
l5 = l1+l3
print('Concatenated list', l5)

#create a list of 0s of lentgth n
#can replace 0 with any element

n=10
my_list = [0]*n
print(my_list)

#other list operations: insert, remove, count, copy, extend, sort
#search documentation on their use (either on google or you can use IDLE
#- help(list) or Python Console)

#tuples: immutable

t1 = (1,2,3,4)
print('Tuple is', t1)
a,b,c,d = t1
print(f'a={a}', end=' ')
print(f'b={b}', end=' ')
print(f'c={c}', end=' ')
print(f'd={d}')

#accessing by index works for tuples, as does slicing
print('First element in tuple', t1[0])
print(t1[1:3])

#can also concatenate 2 tuples
t2 = ('a','b')
t3 = t1+t2
print(t3)

#other tuple methods: index, count








