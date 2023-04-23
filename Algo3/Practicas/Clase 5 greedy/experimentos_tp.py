import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

# Esto no es bueno hacerlo, porque no permite ver bien diferencias.
#fig = plt.figure()

#Leemos los tres resultados del experimento (random, sorted y unsorted) y creamos los dataframes
df = pd.read_csv("runtime_tp_random.csv")
df_sorted = pd.read_csv("runtime_tp_sorted.csv")
df_unsorted = pd.read_csv("runtime_tp_unsorted.csv")

#Agregamos la columna 'acts' que es una copia de la columna 'n'
df['acts'] = df['n']
df_sorted['acts'] = df_sorted['n']
df_unsorted['acts'] = df_unsorted['n']


#Dibujamos los graficos con escala lineal
#Random
ax1 = sns.lmplot(x='time', y='acts', data=df)
plt.xlabel("tiempo (s)")
plt.ylabel("cota teorica")
plt.savefig("plots/plt_random_lineal.png")
#Sorted
ax1 = sns.lmplot(x='time', y='acts', data=df_sorted)
plt.xlabel("tiempo (s)")
plt.ylabel("cota teorica")
plt.savefig("plots/plt_sorted_lineal.png")
#Unorted
ax1 = sns.lmplot(x='time', y='acts', data=df_unsorted)
plt.xlabel("tiempo (s)")
plt.ylabel("cota teorica")
plt.savefig("plots/plt_unsorted_lineal.png")

#
#Hacemos lo mismo ahora con escala logaritmica para que se vea mejor
df['log_time'] = np.log(df['time'])
df['log_acts'] = np.log(df['acts'])
df_sorted['log_time'] = np.log(df_sorted['time'])
df_sorted['log_acts'] = np.log(df_sorted['acts'])
df_unsorted['log_time'] = np.log(df_unsorted['time'])
df_unsorted['log_acts'] = np.log(df_unsorted['acts'])

ax1 = sns.lmplot(x='log_time', y='log_acts', data=df)
plt.xlabel("log_tiempo (s)")
plt.ylabel("log_acts")
plt.savefig("plots/plt_random_log.png")

ax1 = sns.lmplot(x='log_time', y='log_acts', data=df_sorted)
plt.xlabel("log_tiempo (s)")
plt.ylabel("log_acts")
plt.savefig("plots/plt_sorted_log.png")

ax1 = sns.lmplot(x='log_time', y='log_acts', data=df_unsorted)
plt.xlabel("log_tiempo (s)")
plt.ylabel("log_acts")
plt.savefig("plots/plt_unsorted_log.png")

#Hacemos ahora para compararlos entre ellos
#Escala lineal
df['time_sorted'] = df_sorted['time']
df['time_unsorted'] = df_unsorted['time']

fig, ax = plt.subplots()

ax.scatter(df['n'],df['time'],color='yellow', label='random')
ax.scatter(df['n'],df['time_sorted'],color='blue', label='sorted')
ax.scatter(df['n'],df['time_unsorted'],color='red', label='unsorted')
plt.xlabel("n")
plt.ylabel("tiempo (s)")

ax.legend()
ax.grid(True)

plt.savefig("plots/comparacion_lineal")
#Escala logaritmica
ax.scatter(np.log(df['n']),np.log(df['time']),color='yellow')
ax.plot(np.log(df['n']),np.log(df['time']),color='yellow', label='random')
ax.scatter(np.log(df['n']),np.log(df['time_sorted']),color='blue')
ax.plot(np.log(df['n']),np.log(df['time_sorted']),color='blue', label='sorted')
ax.scatter(np.log(df['n']),np.log(df['time_unsorted']),color='red')
ax.plot(np.log(df['n']),np.log(df['time_unsorted']),color='red', label='unsorted')

plt.xlabel("log_n")
plt.ylabel("log_tiempo (s)")

ax.legend()
ax.grid(True)

plt.savefig("plots/comparacion_log")