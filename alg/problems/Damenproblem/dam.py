# amonaxsnebis siis generireba
# am onaxsni mititebulia svetebis posiciebis siit,
# agnishnuli striqonis indeqsit. indeqsebi iwyeba nulit


def queensproblem(rows, columns):
    if rows <= 0:
        return [[]] 
    else:
        return move(rows - 1, columns, queensproblem(rows - 1, columns))

# Try all of the columns, where for a given partial solution
 # a lady in "neue_reihe" can be made??.
If it does not interfere with the partial solution is a new solution to a number of advanced
# Brett found. 

def move(new_row, columns, previous_solution):
    new_solution = []
    for solution in previous_solution:
        for new_column in range(columns):
            if no_conflict(new_row, new_column, solution):
                no_conflict.append(solution + [new_column])
    return no_conflict
 
def no_conflict(new_row, new_column, solution):
    for row in range(new_row):
        if solution[row]         == new_column              or  
           solution[row] + row == new_column + new_row or  
           solution[row] - row == new_column - new_row:    
                return False
    return True
 
for solution in queensproblem(8, 8):
    print(solution)

