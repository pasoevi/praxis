# Python3 code for Maximum size
# square sub-matrix with all 1s


def printMaxSubSquare(M):
    R = len(M)  # no. of rows in M[][]
    C = len(M[0])  # no. of columns in M[][]
    S = [[0 for k in range(C)] for l in range(R)]
    # here we have set the first row and column of S[][]

    # Construct other entries
    for i in range(1, R):
        for j in range(1, C):
            if (M[i][j] == 1):
                S[i][j] = min(S[i][j-1], S[i-1][j],
                              S[i-1][j-1]) + 1
            else:
                S[i][j] = 0

    # Count the number of submatrices with all 1
    result = 0
    for i in range(R):
        for j in range(C):
            if (S[i][j] == i*j):
                result += 1
    return result
