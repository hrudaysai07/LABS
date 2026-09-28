goal = (1, 2, 3, 4, 5, 6, 7, 8, 0)

def neighbors(state):
    i = state.index(0) 
    row, col = divmod(i, 3)
    result = []
    for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
        r, c = row + dr, col + dc
        if 0 <= r < 3 and 0 <= c < 3:
            j = r * 3 + c
            s = list(state)
            s[i], s[j] = s[j], s[i] 
            result.append(tuple(s))
    return result

def show(state):
    for i in range(0, 9, 3):
        print(state[i:i + 3])
    print()

def dfs(start):
    stack = [start]
    parent = {start: None} 
    while stack:
        state = stack.pop()
        if state == goal:
            path = []
            while state is not None: 
                path.append(state)
                state = parent[state]
            return path[::-1]
        for n in neighbors(state):
            if n not in parent:
                parent[n] = state
                stack.append(n)
    return None

def dls(state, limit, path): 
    if state == goal:
        return path
    if limit == 0:
        return None
    for n in neighbors(state):
        if n not in path: 
            result = dls(n, limit - 1, path + [n])
            if result:
                return result
    return None

def ids(start, max_depth=30):
    for depth in range(max_depth + 1):
        result = dls(start, depth, [start])
        if result:
            print(f"Solution found at depth {depth}")
            return result
    return None

start = (1, 2, 3, 0, 4, 6, 7, 5, 8)
print("DFS")
p = dfs(start)
print("Moves:", len(p) - 1)
print("\nIDS")
p = ids(start)
print("Moves:", len(p) - 1)
for s in p:
    show(s)
