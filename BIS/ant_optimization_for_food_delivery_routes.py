
import numpy as np
import random

distance = np.array([
    [0,  2,  5,  7,  3,  6],
    [2,  0,  4,  6,  5,  3],
    [5,  4,  0,  3,  6,  4],
    [7,  6,  3,  0,  2,  5],
    [3,  5,  6,  2,  0,  4],
    [6,  3,  4,  5,  4,  0]
])

num_ants = 10
iterations = 100
alpha = 1   
beta = 2    
evaporation = 0.5
Q = 100

n = len(distance)

pheromone = np.ones((n, n))
best_route = None
best_distance = float('inf')

for iteration in range(iterations):

    all_routes = []
    all_distances = []

    for ant in range(num_ants):

        route = [0]
        unvisited = list(range(1, n))

        while unvisited:

            current = route[-1]

            probabilities = []

            for city in unvisited:
                tau = pheromone[current][city] ** alpha
                eta = (1 / distance[current][city]) ** beta
                probabilities.append(tau * eta)

            probabilities = np.array(probabilities)
            probabilities /= probabilities.sum()

            next_city = random.choices(
                unvisited,
                weights=probabilities
            )[0]

            route.append(next_city)
            unvisited.remove(next_city)

        route.append(0)

        total_distance = sum(
            distance[route[i]][route[i + 1]]
            for i in range(len(route) - 1)
        )

        all_routes.append(route)
        all_distances.append(total_distance)

        if total_distance < best_distance:
            best_distance = total_distance
            best_route = route


    pheromone *= (1 - evaporation)
    for route, dist in zip(all_routes, all_distances):

        for i in range(len(route) - 1):
            a = route[i]
            b = route[i + 1]

            pheromone[a][b] += Q / dist
            pheromone[b][a] += Q / dist

print("Best Delivery Route:", best_route)
print("Minimum Distance:", best_distance)
