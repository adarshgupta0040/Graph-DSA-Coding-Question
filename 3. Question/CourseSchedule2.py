from collections import deque

def topologicalSort(n, indegree, prerequisites):
    adjList = [[] for _ in range(n+1)]
    ans = []

    for a, b in prerequisites:
        adjList[b].append(a)
    
    for i in range(0, n):
        for x in adjList[i]:
            indegree[x]+=1


    queue = deque()
    for i in range(0, n): 
        if indegree[i] == 0:
            queue.append(i)
    while queue:
        front = queue.popleft()
        ans.append(front)

        for neighbour in adjList[front]:
            indegree[neighbour] -= 1
            if indegree[neighbour] == 0:
                queue.append(neighbour)

    if len(ans) != n:
        return []

    return ans

def findSchedule(numCourses, prerequisites):
    indegree = [0] * (numCourses+1)
    return topologicalSort(numCourses, indegree, prerequisites)
