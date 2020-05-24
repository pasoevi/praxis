class Solution:
    def intervalIntersection(self, A: List[List[int]], B: List[List[int]]) -> List[List[int]]:
        result = []
        iterA = 0
        iterB = 0

        while iterA < len(A) and iterB < len(B):
            start = max(A[iterA][0], B[iterB][0])
            end = min(A[iterA][1], B[iterB][1])

            if start <= end:
                result.append([start, end])
            if A[iterA][1] < B[iterB][1]:
                iterA += 1
            else:
                iterB += 1

        return result
