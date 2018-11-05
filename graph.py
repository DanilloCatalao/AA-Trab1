import random

class Graph:

    def __init__(self):
        self.node_list = []
        self.edge_dict = {}

    def insert_node(self, node, edge_list):
        if node not in self.node_list:
            self.node_list.append(node)

        self.edge_dict[node] = edge_list

    def dfs(self, initial_node):
        visited_list = []
        others = self.node_list.copy()
        others.remove(initial_node)
        self._dfs_visit(initial_node, visited_list)
        for node in others:
            if node not in visited_list:
                self._dfs_visit(node, visited_list)

        return visited_list

    def _dfs_visit(self, node, visited_list):
       visited_list.append(node)
       for neighbor in self.edge_dict[node]:
           if neighbor not in visited_list:
               self._dfs_visit(neighbor, visited_list)


    @staticmethod
    def create_from_board(board):
        board_graph = Graph()

        # Constrói o grafo, onde os vértices são as peças e as arestas
        # representam a adjacência das peças no tabuleiro.
        for i in range(len(board)):
            for j in range(len(board)):
                node = board[i][j]
                edge_list = []

                if (j - 1) >= 0 and (j - 1) < len(board):
                    edge_list.append(board[i][j - 1])
                if (j + 1) >= 0 and (j + 1) < len(board):
                    edge_list.append(board[i][j + 1])
                if (i - 1) >= 0 and (i - 1) < len(board):
                    edge_list.append(board[i - 1][j])
                if (i + 1) >= 0 and (i + 1) < len(board):
                    edge_list.append(board[i + 1][j])
                board_graph.insert_node(node, edge_list)

        return board_graph

def create_board():
    dimension = 3
    piece_count = 8

    # Matriz que representa o tabuleiro.
    board = [dimension * [None] for _ in range(dimension)]
    # Lista de peças.
    piece_list = list(range(1, piece_count + 1))
    # Lista de todas as possíveis posições.
    possible_indexes = [(x, y) for x in range(dimension) for y in range(dimension)]

    # Insere as peças em posições aleatórias do tabuleiro.
    for _ in range(piece_count):
        random_indexes = random.choice(possible_indexes)
        possible_indexes.remove(random_indexes)
        x, y = random_indexes
        board[x][y] = piece_list.pop()

    return board

def generate_state_graph(initial_board):
    board_graph = Graph.create_from_board(initial_board)
    print(board_graph.dfs(None))

def main():
    board = create_board()
    print(board)
    generate_state_graph(board)

if __name__ == '__main__':
    main()
