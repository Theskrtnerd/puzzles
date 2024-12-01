table = [
    ['A', 'A', 'A', 'A', 'A', 'A'],
    ['A', 'A', 'A', 'A', 'B', 'B'],
    ['A', 'A', 'B', 'B', 'B', 'B'],
    ['B', 'B', 'B', 'B', 'C', 'C'],
    ['B', 'B', 'C', 'C', 'C', 'C'],
    ['C', 'C', 'C', 'C', 'C', 'C']
]

def get_knight_moves(x, y):
    moves = [
        (x + 2, y + 1), (x + 2, y - 1), (x - 2, y + 1), (x - 2, y - 1),
        (x + 1, y + 2), (x + 1, y - 2), (x - 1, y + 2), (x - 1, y - 2)
    ]
    return [(nx, ny) for nx, ny in moves if 0 <= nx < 6 and 0 <= ny < 6]

def find_paths(x, y, end_x, end_y, path, paths):
    if (x, y) == (end_x, end_y):
        paths.append(path)
        return
    for nx, ny in get_knight_moves(x, y):
        if (nx, ny) not in path:
            find_paths(nx, ny, end_x, end_y, path + [(nx, ny)], paths)

def get_path(x, y):
    paths = []
    find_paths(x, y, 5, 5, [(x, y)], paths)
    return paths

print(get_path(0, 0))
    