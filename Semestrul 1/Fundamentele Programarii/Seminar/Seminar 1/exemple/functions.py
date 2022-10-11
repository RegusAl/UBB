import math

def maxim(lst):
    """
    Find the maximum value in a list of integers
    """
    m = -math.inf
    for el in lst:
        if el>m:
            m = el
    return m


#call function
my_list = [1,10,8,9,5,11]
my_list_max = maxim(my_list)
print('List:', my_list)
print('Maximum in list is:', my_list_max)

#can return about anything from functions
#e.g. lists, dictionaries, tuples

def assign_random_numbers(names, start, end):
    """
    Assign a random number representing queue numbers/ids for
    a series of persons given through their names
    
    @param names: list of unique names (list of strings)
    @param start: start of queue no. interval
    @param end: end of queue no. interval
    @return: dictionary of name and queue numbers pairs
    """
    import random
    d = {}
    for name in names:
        d[name] = random.randint(start, end)
    return d

name_list = ['George', 'Daniel', 'Marie']
print(assign_random_numbers(name_list, 1000, 9999))

#side note: in the above we can obtain the same random number
#for two people (by chance)
