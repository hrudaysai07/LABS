import numpy as np
import random
import math

budget = 50      
preferred_distance = 5
required_bedrooms = 3
preferred_area = 1500  

n = 20
pa = 0.25
iterations = 100
dimensions = 4
step_size = 0.1

lower = np.array([20, 1, 1, 500])
upper = np.array([100, 30, 5, 3000])

nests = np.random.uniform(lower, upper, (n, dimensions))

def fitness(house):

    price, distance, bedrooms, area = house

    budget_penalty = max(0, price - budget) / budget
    distance_penalty = max(0, distance - preferred_distance) / 25
    bedroom_penalty = max(0, required_bedrooms - bedrooms) / 3
    area_penalty = max(0, preferred_area - area) / preferred_area

    penalty = (
        0.4 * budget_penalty +
        0.25 * distance_penalty +
        0.20 * bedroom_penalty +
        0.15 * area_penalty
    )

    return max(0, 100 * (1 - penalty))

def levy_flight():

    beta = 1.5

    sigma = (
        math.gamma(1 + beta) * math.sin(math.pi * beta / 2) /
        (math.gamma((1 + beta) / 2) * beta *
         2 ** ((beta - 1) / 2))
    ) ** (1 / beta)

    u = np.random.normal(0, sigma, dimensions)
    v = np.random.normal(0, 1, dimensions)

    return u / (np.abs(v) ** (1 / beta))

scores = np.array([fitness(h) for h in nests])
best_index = np.argmax(scores)
best_house = nests[best_index].copy()
best_score = scores[best_index]

for iteration in range(iterations):
    for i in range(n):
        new_house = nests[i] + step_size * levy_flight() * (
            nests[i] - best_house
        )

        new_house = np.clip(new_house, lower, upper)
        new_house[2] = round(new_house[2])
        new_score = fitness(new_house)

        j = random.randrange(n)

        if new_score > scores[j]:
            nests[j] = new_house
            scores[j] = new_score

    abandon = max(1, int(pa * n))
    worst_indices = np.argsort(scores)[:abandon]

    for j in worst_indices:
        nests[j] = np.random.uniform(lower, upper)
        nests[j][2] = round(nests[j][2])
        scores[j] = fitness(nests[j])
        
    best_index = np.argmax(scores)

    if scores[best_index] > best_score:
        best_score = scores[best_index]
        best_house = nests[best_index].copy()

print("\n--- BEST HOUSE RECOMMENDATION ---")
print(f"Price: Rs. {best_house[0]:.2f} Lakhs")
print(f"Distance from Workplace: {best_house[1]:.2f} Km")
print(f"Bedrooms: {int(best_house[2])}")
print(f"House Area: {best_house[3]:.2f} Sq.ft")
print(f"Suitability Score: {best_score:.2f}%")
