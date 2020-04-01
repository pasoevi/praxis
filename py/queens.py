import pprint
# list of column positions
# Indexed by the row number.

 
def no_conflict(new_rows, new_column, solution):
    for row in range(new_rows):
        if solution[row] == new_column or solution[row] + row == new_column + new_rows or solution[row] - row == new_column - new_rows:    
                return False
    return True

def move(new_rows, columns, previous_solution):
    new_solution = []
    for solution in previous_solution:
        for new_column in range(columns):
            if no_conflict(new_rows, new_column, solution):
                new_solution.append(solution + [new_column])
    return new_solution

def queensproblem(rows, columns):
    if rows <= 0:
        return [[]] 
    else:
        return move(rows - 1, columns, queensproblem(rows - 1, columns))

solutions = [soluion for soluion in queensproblem(8, 8)]

if __name__ == "__main__":
    pprint.pprint(solutions)
