import networkx as nx
import matplotlib.pyplot as plt

n={}
color=[]
f = open('node0_500.txt')
for i, line in enumerate(f.readlines()):
    x,y,z = line.strip("\n").split()
    x = int(x)
    y = int(y)
    n[i] = (x,y)
    if z == '0':
        color.append('blue')
    elif z == '1':
        color.append('green')
    else:
        color.append('yellow')
f.close

e = []
f1 = open('connect0_500.txt')
for line in f1.readlines():
    x,y = line.strip("\n").split()
    x = int(x)
    y = int(y)
    e.append((x,y))
f1.close

G = nx.Graph()
G.add_nodes_from(n.keys())
G.add_edges_from(e)
plt.figure(figsize=(10,10))
nx.draw(G,n,node_color=color,with_labels=True)
plt.show()

