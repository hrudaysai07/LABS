import math
import random

def route_distance(route, cities):
    if len(route) < 2:
        return 0.0
    return sum(math.dist(cities[route[i]], cities[route[(i + 1) % len(route)]]) for i in range(len(route)))

def _ordered_crossover(parent_a, parent_b):
    size = len(parent_a)
    left, right = sorted(random.sample(range(size), 2))
    child = [None] * size
    child[left:right + 1] = parent_a[left:right + 1]
    remaining = [city for city in parent_b if city not in child]
    positions = list(range(right + 1, size)) + list(range(left))

    for position, city in zip(positions, remaining):
        child[position] = city

    return child


def find_route(cities, population_size=100, generations=500,
               mutation_rate=0.02, seed=None):
    if len(cities) < 2:
        raise ValueError("Provide at least two cities")
    if population_size < 2 or generations < 1:
        raise ValueError("population_size must be >= 2 and generations >= 1")
    if not 0 <= mutation_rate <= 1:
        raise ValueError("mutation_rate must be between 0 and 1")

    if seed is not None:
        random.seed(seed)

    names = list(cities)
    population = [
        random.sample(names, len(names))
        for _ in range(population_size)
    ]

    
    def fitness(route):
        return route_distance(route, cities)

    for _ in range(generations):
        population.sort(key=fitness)
        next_generation = population[:2]
        while len(next_generation) < population_size:
            contenders = random.sample(population, min(5, population_size))
            parent_a = min(contenders, key=fitness)

            contenders = random.sample(population, min(5, population_size))
            parent_b = min(contenders, key=fitness)

            child = _ordered_crossover(parent_a, parent_b)

            if len(child) > 1 and random.random() < mutation_rate:
                i, j = random.sample(range(len(child)), 2)
                child[i], child[j] = child[j], child[i]

            next_generation.append(child)

        population = next_generation

    best_route = min(population, key=fitness)
    return best_route, fitness(best_route)


if __name__ == "__main__":
    cities = {
        "A": (0, 0),
        "B": (2, 6),
        "C": (5, 3),
        "D": (6, 7),
        "E": (8, 1),
        "F": (1, 4),
    }

    route, distance = find_route(cities, seed=42)
    print("Best route:", " -> ".join(route + [route[0]]))
    print(f"Total distance: {distance:.2f}")
