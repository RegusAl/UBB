#reading and printing

#Read

a = input("The number is:")
print('The type we read is ', type(a), 'and value', a)

#Everything we read is string - if we want to work with it
#as int, we need to do conversion
print('Converting...')

a = int(a)
print('The type is now', type(a), 'and the value is', a)

#can convert to float, as well - float(a)

#Operations on numbers

print('Int/floor division by 3', a//3)
print('To the power of 2:', a**2)
print('Absolute value:', abs(a))

#Format string

import math
a_sqrt = math.sqrt(a)

print(f'Square root of a is {a_sqrt}')
#or
#we print with specified number of decimal places
print("%.5f" % a_sqrt)
print('Square root of a is {:.3f}'.format(a_sqrt))

#in the seminar may have been mix-up of the syntaxes of the two options
#(which presumably won't work :D)


