import random

class Graph:

    def __init__(self):
        self.node_list = []
        self.edge_dict = {}

    def insert_node(self, node, edge_list):
        if node not in self.node_list:
            self.node_list.append(node)

        self.edge_dict[node] = edge_list

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

def main():
    board = create_board()
    print(board)
    board_graph = Graph.create_from_board(board)
    print(board_graph.edge_dict)

if __name__ == '__main__':
    main()
