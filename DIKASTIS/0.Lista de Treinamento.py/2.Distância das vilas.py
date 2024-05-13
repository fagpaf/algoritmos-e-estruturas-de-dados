x=int(input())
z=int(input())
xh=34
zh=220
xk=0 
zk=0
xs=140
zs=456
h=float((xh-x)**2+(zh-z)**2)**(1/2)
k=float((xk-x)**2+(zk-z)**2)**(1/2)
s=float((xs-x)**2+(zs-z)**2)**(1/2)
print(f'Distancia para Hogsmeade: {h:0.2f}')
print(f'Distancia para Kakariko: {k:0.2f}')
print(f'Distancia para Solitude: {s:0.2f}')