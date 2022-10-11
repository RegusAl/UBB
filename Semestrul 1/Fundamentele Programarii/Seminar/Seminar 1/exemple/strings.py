#strings: immutable

s1 = 'I listened to music.'
s2 = 'I\'ve been listening to music.'
print('S1:', s1)

print('Number of characters S1:', len(s1))
print('First character of S1:', s1[0])
print('s1[:5]:', s1[:6])

print('S2:', s2)
print('Number of characters S2:', len(s2))


#finding a substring

#with method 'find'
#find: searches the string for a specified value
#      and returns the position of where it was found

pos1 = s1.find('music')
print(pos1)

pos2 = s1.index('music')
print(pos2)

#Difference between find/index
print('Position of substring that does not exist:')
print('With find', s1.find('Led Zeppelin'))

#this throws error - to run the following instructions, comment it out
print('With index', s1.index('Led Zeppelin'))

#can search in a specific portion of the string
#here, in the substring between indices 10-15
pos3 = s1.find('music', 10, 15)
print('Between indices 10-15: ', pos3)

#equivalent to

pos3 = s1[10:16].find('music')
print('Between indices 10-15: ', pos3)

#can search for last occurence of substring

first_pos = s1.find('i')
last_pos = s1.rfind('i')
print('First pos of character \'i\' ', first_pos)
print('First pos of character \'i\' ', last_pos)

#how can we find the n-th occurence of substring in string
#using these methods?

###########################################

#format strings in specific way

s1_upper = s1.upper()
print(s1_upper)

s1_lower = s1.lower()
print(s1_lower)

s3 = 'apples'
s3_cap = s3.capitalize()
print(s3_cap)

##########################################

#tokenize strings
#e.g. we want to get individual words in a sentence

print('Sentence',s1)
tokens = s1.split()
print('Tokens', tokens)

#.split() receives as optional argument delimiter
#default is space

s1 = 'apples,oranges,blueberries'
print('Current string:', s1)
print('Split string:', s1.split(','))

#what is the return type in this case?

#if we have a list of strings, we can make one
#big string out of it

s1 = ['this', 'should', 'be', 'a', 'sentence']

#What is the difference between the two versions below?

print(' '.join(s1))
print('\n'.join(s1))

#other useful string methods: replace, startswith, endswith, isnumeric, isdigit, isascii, etc
