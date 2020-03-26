import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

def weight10(digit):
	return (10 - digit[0]) * digit[1]

def weight13(digit):
    weight = 1 if digit[0] % 2 == 0 else 3
    return weight * digit[1]

def is_valid_isbn10(isbn):
    if not all(map(str.isdigit, isbn[:-1])):
        return False
    if not isbn[9].isdigit() and isbn[9] is not "X":
        return False

    digits = list(map(lambda x: int(x), isbn[:-1]))
    check_digit = 11 - sum([weight10(i) for i in zip(range(len(digits)), digits)]) % 11
    if check_digit == 11:
        check_digit = 0
    return isbn[-1] == str(check_digit) if check_digit != 10 else isbn[-1] == "X"

def is_valid_isbn13(isbn):
    if not len(isbn) == 13 or not all(map(str.isdigit, isbn)):
        return False

    digits = list(map(lambda x: int(x), isbn[:-1]))
    check_digit = 10 - sum([weight13(i) for i in zip(range(len(digits)), digits)]) % 10
    if check_digit == 10:
        check_digit = 0
    return isbn[-1] == str(check_digit)

def is_valid_isbn(isbn):
    if len(isbn) == 10:
        return is_valid_isbn10(isbn)
    elif len(isbn) == 13:
        return is_valid_isbn13(isbn)
    else:
        return False

n = int(input())
invalid = []
for i in range(n):
    isbn = input()
    if not is_valid_isbn(isbn):
        invalid.append(isbn)

print(f"{len(invalid)} invalid:")
for isbn in invalid:
    print(isbn)
