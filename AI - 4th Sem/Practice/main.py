import random

N = 25
POPULATION_SIZE = 100
MUTATION_RATE = 0.1
MAX_GENERATIONS = 10000

def create_individual():
    individual = []
    for i in range(N):
        individual.append(random.randint(0, N - 1))
    return individual

def create_population():
    population = []
    for _ in range(POPULATION_SIZE):
        population.append(create_individual())
    return population

def fitness(individual):

    conflicts = 0

    for i in range(N):
        for j in range(i + 1, N):

            # Same column
            if individual[i] == individual[j]:
                conflicts += 1

            # Same diagonal
            if abs(individual[i] - individual[j]) == abs(i - j):
                conflicts += 1

    max_pairs = (N * (N - 1)) // 2
    return max_pairs - conflicts

def selection(population):

    i1 = random.randint(0, POPULATION_SIZE - 1)
    i2 = random.randint(0, POPULATION_SIZE - 1)

    if fitness(population[i1]) > fitness(population[i2]):
        return population[i1]
    else:
        return population[i2]

def crossover(parent1, parent2):

    point = random.randint(1, N - 2)

    child = []
    for i in range(point):
        child.append(parent1[i])

    for i in range(point, N):
        child.append(parent2[i])

    return child

def mutate(individual):

    if random.random() < MUTATION_RATE:

        index = random.randint(0, N - 1)
        individual[index] = random.randint(0, N - 1)

    return individual

def print_board(individual):

    for r in range(N):
        for c in range(N):
            if individual[c] == r:
                print("Q", end=" ")
            else:
                print(".", end=" ")
        print()
    print()

def genetic_algorithm():

    population = create_population()

    max_pairs = (N * (N - 1)) // 2

    for generation in range(MAX_GENERATIONS):

        new_population = []

        for _ in range(POPULATION_SIZE):

            parent1 = selection(population)
            parent2 = selection(population)

            child = crossover(parent1, parent2)

            child = mutate(child)

            new_population.append(child)

        population = new_population

        best = population[0]
        best_fit = fitness(best)

        for individual in population:
            f = fitness(individual)
            if f > best_fit:
                best = individual
                best_fit = f

        print("Generation:", generation, "Fitness:", best_fit)

        if best_fit == max_pairs:
            print("\nSolution Found!\n")
            print_board(best)
            return

    print("No solution found.")

genetic_algorithm()