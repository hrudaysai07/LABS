import numpy as np
import matplotlib.pyplot as plt

target_x = 5
target_y = 8
num_particles = 30
max_iterations = 100

w = 0.7   
c1 = 1.5    
c2 = 1.5      
positions = np.random.uniform(0, 10, (num_particles, 2))
velocities = np.random.uniform(-1, 1, (num_particles, 2))

def fitness(position):
    return np.sqrt(
        (position[0] - target_x)**2 +
        (position[1] - target_y)**2
    )

pbest_positions = positions.copy()
pbest_values = np.array([fitness(p) for p in positions])

gbest_index = np.argmin(pbest_values)
gbest_position = pbest_positions[gbest_index].copy()
gbest_value = pbest_values[gbest_index]

history = []
for iteration in range(max_iterations):

    for i in range(num_particles):

        r1 = np.random.random(2)
        r2 = np.random.random(2)
        velocities[i] = (
            w * velocities[i]
            + c1 * r1 * (pbest_positions[i] - positions[i])
            + c2 * r2 * (gbest_position - positions[i])
        )
        positions[i] = positions[i] + velocities[i]
        positions[i] = np.clip(positions[i], 0, 10)
        current_value = fitness(positions[i])
        if current_value < pbest_values[i]:
            pbest_values[i] = current_value
            pbest_positions[i] = positions[i].copy()
    gbest_index = np.argmin(pbest_values)

    if pbest_values[gbest_index] < gbest_value:
        gbest_value = pbest_values[gbest_index]
        gbest_position = pbest_positions[gbest_index].copy()

    history.append(gbest_value)
    print(
        f"Iteration {iteration+1}: "
        f"Best Position = {gbest_position}, "
        f"Error = {gbest_value:.6f}"
    )
print("\n--- FINAL RESULT ---")
print("Optimal Claw Position:", gbest_position)
print("Target Position:", [target_x, target_y])
print("Minimum Distance:", gbest_value)
plt.figure(figsize=(8, 5))
plt.plot(history, color='blue')
plt.xlabel("Iteration")
plt.ylabel("Best Fitness Value")
plt.title("PSO Convergence - Claw Machine Problem")
plt.grid()
plt.show()
plt.figure(figsize=(7, 7))
plt.scatter(positions[:, 0], positions[:, 1],
            label="Particles", color="blue")
plt.scatter(target_x, target_y,
            color="red", marker="*", s=200,
            label="Target Object")
plt.scatter(gbest_position[0], gbest_position[1],
            color="green", marker="X", s=150,
            label="Optimal Claw Position")
plt.xlim(0, 10)
plt.ylim(0, 10)
plt.xlabel("X Position")
plt.ylabel("Y Position")
plt.title("Claw Machine Optimization using PSO")
plt.legend()
plt.grid()
plt.show()
