
import numpy as np
import matplotlib.pyplot as plt

target_x = 64.10
target_y = 41.26

num_particles = 30
max_iterations = 15

w = 0.7
c1 = 1.5
c2 = 1.5


positions = np.random.uniform(0, 100, (num_particles, 4))
velocities = np.random.uniform(-1, 1, (num_particles, 4))


def fitness(position):
    x, y, grip, timing = position

    distance = np.sqrt(
        (x - target_x)**2 + (y - target_y)**2
    )

    error = distance / 100
    error += abs(grip - 0.749) * 0.1
    error += abs(timing - 0.602) * 0.1

    return max(0, 100 - error * 100)

pbest_positions = positions.copy()
pbest_values = np.array([fitness(p) for p in positions])


gbest_index = np.argmax(pbest_values)
gbest_position = pbest_positions[gbest_index].copy()
gbest_value = pbest_values[gbest_index]

history = []

for iteration in range(max_iterations):

    for i in range(num_particles):

        r1 = np.random.random(4)
        r2 = np.random.random(4)

        velocities[i] = (
            w * velocities[i]
            + c1 * r1 * (pbest_positions[i] - positions[i])
            + c2 * r2 * (gbest_position - positions[i])
        )

        positions[i] += velocities[i]

        positions[i] = np.clip(
            positions[i],
            [0, 0, 0, 0],
            [100, 100, 1, 1]
        )

        current_value = fitness(positions[i])

        if current_value > pbest_values[i]:
            pbest_values[i] = current_value
            pbest_positions[i] = positions[i].copy()

    gbest_index = np.argmax(pbest_values)

    if pbest_values[gbest_index] > gbest_value:
        gbest_value = pbest_values[gbest_index]
        gbest_position = pbest_positions[gbest_index].copy()

    history.append(gbest_value)

    if (iteration + 1) % 5 == 0:
        print(
            f"Iteration {iteration+1}: "
            f"Successful probability = {gbest_value:.2f}"
        )

print("\nBEST CLAW STRATEGY")
print(f"Claw X: {gbest_position[0]:.2f}")
print(f"Claw Y: {gbest_position[1]:.2f}")
print(f"Grip Strength: {gbest_position[2]:.3f}")
print(f"Closing Timing: {gbest_position[3]:.3f}")
print(f"Estimated Success: {gbest_value:.2f}%")
