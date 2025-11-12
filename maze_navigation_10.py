from collections import deque

maze=[
    [1,0,1,0,0],
    [1,0,0,0,0],
    [0,0,0,1,0],
    [1,0,0,0,1],
    [0,0,1,0,0]
]
start=(3,0)
goal=(0,3)

directions=[(-1,0),(1,0),(0,-1),(0,1)]

def bfs(start, goal):
    queue=deque([start])
    visited=set([start])
    parent={start:None}

    while queue:
        r,c=queue.popleft()

        if(r,c)==goal:
            break

        for dr, dc in directions:
            nr, nc=r+dr, c+dc
            if 0<=nr<len(maze) and 0<=nc<len(maze[0]):
                if maze[nr][nc]==0 and (nr,nc) not in visited:
                    queue.append((nr,nc))
                    visited.add((nr,nc))
                    parent[(nr,nc)]=(r,c)

    path=[]
    node=goal
    while node is not None:
        path.append(node)
        node=parent.get(node)
    path.reverse()

    if path[0]==start:
        return path
    else:
        return None

path=bfs(start,goal)

if path:
    print("Path Found:",path)
else:
    print("Path Not Found")
