import numpy as np
import matplotlib.pyplot as plt
import os

os.system ("g++ JuanVelasquez_Ejercicio26.cpp")
os.system ("./a.out")

a = np.loadtxt("euler.dat")
b = np.loadtxt("rk4.dat")
c = np.loadtxt("leapfrog.dat")

plt.figure(figsize = (50,30))
fig,axes = plt.subplots(3,3)

axes[0,0].plot(a[:,0],a[:,1])
axes[0,0].set_title('Euler')
axes[0,0].set_ylabel('Posicion')
axes[0,0].set_xlim([0,4*np.pi])
axes[0,0].set_ylim([-1.5,1.5])

axes[1,0].plot(a[:,0],a[:,2])
axes[1,0].set_title('Time')
axes[1,0].set_ylabel('Velocidad')
axes[1,0].set_xlim([0,4*np.pi])
axes[1,0].set_ylim([-1.5,1.5])

axes[2,0].plot(a[:,1],a[:,2])
axes[2,0].set_title('Time')
axes[2,0].set_xlabel('Posicion')
axes[2,0].set_ylabel('Velocidad')
axes[2,0].set_xlim([-2,2])
axes[2,0].set_ylim([-2,2])

axes[0,1].plot(b[:,0],b[:,1])
axes[0,1].set_title('RK')
axes[0,1].set_ylabel('Posicion')
axes[0,1].set_xlim([0,4*np.pi])
axes[0,1].set_ylim([-1.5,1.5])

axes[1,1].plot(b[:,0],b[:,2])
axes[1,1].set_title('Time')
axes[1,1].set_ylabel('Velocidad')
axes[1,1].set_xlim([0,4*np.pi])
axes[1,1].set_ylim([-1.5,1.5])

axes[2,1].plot(b[:,1],b[:,2])
axes[2,1].set_title('Time')
axes[2,1].set_xlabel('Posicion')
axes[2,1].set_ylabel('Velocidad')
axes[2,1].set_xlim([-2,2])
axes[2,1].set_ylim([-2,2])

axes[0,2].plot(c[:,0],c[:,1])
axes[0,2].set_title('Leapfrog')
axes[0,2].set_ylabel('Posicion')
axes[0,2].set_xlim([0,4*np.pi])
axes[0,2].set_ylim([-1.5,1.5])

axes[1,2].plot(c[:,0],c[:,2])
axes[1,2].set_title('Time')
axes[1,2].set_ylabel('Velocidad')
axes[1,2].set_xlim([0,4*np.pi])
axes[1,2].set_ylim([-1.5,1.5])

axes[2,2].plot(c[:,1],c[:,2])
axes[2,2].set_title('Time')
axes[2,2].set_xlabel('Posicion')
axes[2,2].set_ylabel('Velocidad')
axes[2,2].set_xlim([-2,2])
axes[2,2].set_ylim([-2,2])
plt.savefig("grafica.png")