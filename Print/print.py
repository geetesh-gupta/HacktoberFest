"""
# print function is used in various ways
print x 
This statement is valid in pyhton 2.xx but it is not valid in python 3.xx. You need to put round braces in pyhton 3.x and subsequent version.
Python 2.xx
print x or print(x)--> this will print value of variable x and then will add line break statement.
print x, --> this will print value of variable x but will not print line break statement.

Python3.xx
print(x) --> this will behave as same in python2.xx
but additionally we can add "end" argument in python3.xx e.g
print(x, end=" ") {for space}
print(x, end="\n") {for line break}
print(x, end="\t") {for tab}
"""
print ("Print!")
