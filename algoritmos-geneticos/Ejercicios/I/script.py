import random
from deap import base
from deap import creator
from deap import tools

# Creamos los objetos para definir el problema y el tipo de individuo
creator.create("FitnessMax", base.Fitness, weights=(1.0,))
creator.create("Individual", list, fitness=creator.FitnessMax)

toolbox = base.Toolbox()

# Generación de genes
toolbox.register("attr_uniform", random.uniform, -100, 100)

# Generación de individuos y población
toolbox.register("individual", tools.initRepeat, creator.Individual, toolbox.attr_uniform, 2)
toolbox.register("population", tools.initRepeat, list, toolbox.individual, 30)

individuo = toolbox.individual()
poblacion = toolbox.population()