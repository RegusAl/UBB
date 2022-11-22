import string
import random

def random_string(nr):
    return ''.join(random.choices(string.ascii_uppercase, k=nr))