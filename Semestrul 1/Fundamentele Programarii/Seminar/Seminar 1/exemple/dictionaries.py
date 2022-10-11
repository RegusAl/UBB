#dictionary where we have keys equal to years,
#and values lists of movies from that year
movies_dict = {}

movies_dict[2021] = ['Dune']
movies_dict[2015] = ['Mission Impossible - Rogue Nation', 'The Revenant']

print('Movie dictionary:')
print(movies_dict)

#print value(s) associated with a key
print('Movies from 2021:', movies_dict[2021])

#change value associated with a key
movies_dict[2021] = ['Spider-Man: No Way Home']
print('After changing the value for key 2021')
print(movies_dict)

#manipulate the values associated with a key
#if we know their type
movies_dict[2021].append('Dune')
print('After appending to 2021 list:')
print(movies_dict)

#can have key with empty list
movies_dict[2022] = []

#can have other types as values
movies_dict[2012] = {'drama': ['Les Miserables', 'Life of Pi'], 'comedy': ['Silver Linings Playbook']}

print()

#Pretty printing when we have a little more data
from pprint import pprint
pprint(movies_dict)

#delete key/value pair
del movies_dict[2012]
print('After deletion of pair associated with key 2012:')
pprint(movies_dict)

#keys can only be immutable types: int (as in the above example), string, tuple
#think about why

d1 = {'apples':10, 'oranges':20}
print(d1)

d2 = {(1,2,3):3, (1,3,5):7}
print(d2)

#this doesn't work

#d3 = {[1,2,3]:4}
#print(d3)

#can have mixed keys

d4 = {'a':1, 2:'two'}
print(d4)

#########################################################

#can also use dicts in lists:

persons = []
p1 = {'age':10, 'name':'george', 'favorite_subject':'math'}
p2 = {'age':11, 'name':'daniel', 'favorite_subject':'english'}
persons.append(p1)
persons.append(p2)

pprint(persons)

for person in persons:
    print('Name: {} | Age: {} | Favorite subject: {}'.format(person['name'], person['age'], person['favorite_subject']))


########################################################

#going through a dict

my_dict = {'apple': 20, 'orange':15, 'blueberries':24}

#keys
my_dict_keys = my_dict.keys()

#is it a 'true' list - check with type(my_dict_keys)
print(type(my_dict_keys))
print('Convert into list', list(my_dict_keys))

#even if it is not a 'true' list, it is iterable, which means we can use "for"
for key in my_dict.keys():
    print(key)

#values
print(my_dict.values())

#pairs
for key, value in my_dict.items():
    print('Key: {} with value: {}.'.format(key, value))


