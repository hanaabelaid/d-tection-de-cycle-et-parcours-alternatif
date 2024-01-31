import networkx as nx
import matplotlib.pyplot as plt

def creer_graphe(sommets, relations):
    G = nx.Graph()
    
    # Ajouter les sommets au graphe
    G.add_nodes_from(sommets)
    
    # Ajouter les relations entre les sommets avec un attribut 'nom'
    for relation in relations:
        G.add_edge(relation[0], relation[1], nom=relation[2])  # ajout de l'attribut 'nom' à l'arête
    
    return G

def dessiner_graphe(G):
    pos = nx.spring_layout(G)  # disposition des nœuds avec l'algorithme de Fruchterman-Reingold
    
    # Extraire les noms des relations pour les afficher sur le graphe
    edge_labels = {(u, v): d['nom'] for u, v, d in G.edges(data=True)}
    
    nx.draw(G, pos, with_labels=True, font_weight='bold', node_size=700, node_color='skyblue', font_size=8, font_color='black')
    nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels, font_color='red')  # Ajout des noms des relations
    plt.show()

# Exemple d'utilisation avec des noms de sommets personnalisés
sommets = ['AL', 'MO', 'TX', 'GA', 'GC', 'VA','NS']
relations = [('AL', 'MO', 'rue little fleur'), ('AL', 'TX', 'rue golf'), ('AL', 'GA', 'rue Continental'),
             ('AL', 'GC', 'Kenwood'), ('AL', 'VA', 'Melby'),('AL', 'NS', 'Maison'), ('MO', 'TX', 'Spenser'),
             ('MO', 'GA', 'Shelley'), ('MO', 'GC', 'Eliot'), ('MO', 'VA', 'Sunbrook'),('MO', 'NS', 'Colorado'),
             ('TX', 'GA', 'Tony'), ('TX', 'GC', 'American Ash'), ('TX', 'VA', 'Farwell'),('TX', 'NS', 'Pond'),
             ('GA', 'GC', 'Almo'), ('GA', 'VA', 'Brentwood'),('GA', 'NS', 'Forest'), ('GC', 'VA', 'Gateway'),('GC', 'NS', 'Hoffman'),('VA', 'NS', 'Stone')]

graphe = creer_graphe(sommets, relations)
dessiner_graphe(graphe)