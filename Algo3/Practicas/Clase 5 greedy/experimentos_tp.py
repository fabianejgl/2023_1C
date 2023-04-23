#Imports
import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

def nlogn(x):
    return x * np.log(x);
fig = plt.figure()

#Leemos los tres resultados del experimento (random, sorted y unsorted) y creamos los dataframes
df = pd.read_csv("runtime_tp_random.csv")
df_sorted = pd.read_csv("runtime_tp_sorted.csv")
df_unsorted = pd.read_csv("runtime_tp_unsorted.csv")

#Vemos la correlación de nuestras medidas con la cota teórica que estimamos
df['cota'] = nlogn(df['n'])
df_sorted['cota'] = nlogn(df_sorted['n'])
df_unsorted['cota'] = nlogn(df_unsorted['n'])

#Dibujamos los graficos con escala normal
#Random
ax1 = sns.lmplot(x='time', y='cota', data=df)
plt.xlabel("tiempo (s)")
plt.ylabel("cota teorica")
plt.title("Escala normal")
plt.savefig("plots/plt_random.png")
#Sorted
ax1 = sns.lmplot(x='time', y='cota', data=df_sorted)
plt.xlabel("tiempo (s)")
plt.ylabel("cota teorica")
plt.title("Escala normal")
plt.savefig("plots/plt_sorted.png")
#Unsorted
ax1 = sns.lmplot(x='time', y='cota', data=df_unsorted)
plt.xlabel("tiempo (s)")
plt.ylabel("cota teorica")
plt.title("Escala normal")
plt.savefig("plots/plt_unsorted.png")

#
#Hacemos lo mismo ahora con escala logaritmica para que se vea mejor
df['log_time'] = np.log(df['time'])
df['log_cota'] = np.log(df['cota'])
df_sorted['log_time'] = np.log(df_sorted['time'])
df_sorted['log_cota'] = np.log(df_sorted['cota'])
df_unsorted['log_time'] = np.log(df_unsorted['time'])
df_unsorted['log_cota'] = np.log(df_unsorted['cota'])

ax1 = sns.lmplot(x='log_time', y='log_cota', data=df)
plt.xlabel("log_tiempo (s)")
plt.ylabel("log_cota")
#Acomodo el titulo porque cuando se guardaba se cortaba el titulo en el .png
plt.title("Escala logarítmica")
plt.tight_layout()
plt.subplots_adjust(top=0.94)

plt.savefig("plots/plt_random_logScale.png")

ax1 = sns.lmplot(x='log_time', y='log_cota', data=df_sorted)
plt.xlabel("log_tiempo (s)")
plt.ylabel("log_cota")

plt.title("Escala logarítmica")
plt.tight_layout()
plt.subplots_adjust(top=0.94)

plt.savefig("plots/plt_sorted_logScale.png")

ax1 = sns.lmplot(x='log_time', y='log_cota', data=df_unsorted)
plt.xlabel("log_tiempo (s)")
plt.ylabel("log_cota")

plt.title("Escala logarítmica")
plt.tight_layout()
plt.subplots_adjust(top=0.94)

plt.savefig("plots/plt_unsorted_logScale.png")

#Hacemos ahora para compararlos entre ellos
#Escala normal
df['time_sorted'] = df_sorted['time']
df['time_unsorted'] = df_unsorted['time']

fig, ax = plt.subplots()

ax.scatter(df['n'],df['time'],color='yellow', label='random')
ax.scatter(df['n'],df['time_sorted'],color='blue', label='sorted')
ax.scatter(df['n'],df['time_unsorted'],color='red', label='unsorted')
plt.xlabel("n")
plt.ylabel("tiempo (s)")
plt.title("Escala normal")

ax.legend()
ax.grid(True)

plt.savefig("plots/comparacion_lineal")

#Escala logaritmica

fig, ax = plt.subplots()

ax.scatter(np.log(df['n']),np.log(df['time']),color='yellow')
ax.plot(np.log(df['n']),np.log(df['time']),color='yellow', label='random')
ax.scatter(np.log(df['n']),np.log(df['time_sorted']),color='blue')
ax.plot(np.log(df['n']),np.log(df['time_sorted']),color='blue', label='sorted')
ax.scatter(np.log(df['n']),np.log(df['time_unsorted']),color='red')
ax.plot(np.log(df['n']),np.log(df['time_unsorted']),color='red', label='unsorted')

plt.xlabel("log_n")
plt.ylabel("log_tiempo (s)")
plt.title("Escala logarítmica")

ax.legend()
ax.grid(True)

plt.savefig("plots/comparacion_log")