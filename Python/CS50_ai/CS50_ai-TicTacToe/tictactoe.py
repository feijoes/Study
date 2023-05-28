"""
Tic Tac Toe Player
"""
import copy


a = 0


X = "X"
O = "O"
EMPTY = None


def initial_state():
    """
    Returns starting state of the board.
    """
    return [[EMPTY, EMPTY, EMPTY],
            [EMPTY, EMPTY, EMPTY],
            [EMPTY, EMPTY, EMPTY]]


def player(board):
    """
    Returns player who has the next turn on a board.
    """
    count_x = 0
    count_O = 0
    for x in board:
        count_x += x.count(X)
        count_O += x.count(O)
    if count_x == count_O:
        return X
    return O
    


def actions(board):
    """
    Returns set of all possible actions (i, j) available on the board.
    """
    actions = set()
    for i in range(3):
        for j in range(3):
            if board[i][j] == EMPTY:
                actions.add((i,j)) 
    
    return actions  


def result(board, action):
    """
    Returns the board that results from making move (i, j) on the board.
    """
    if action not in actions(board) and action != None:
        print(f'not {action} in {actions(board)}')
        raise ValueError
   
    board2 = copy.deepcopy(board)
    board2[action[0]][action[1]] = player(board)
  
    return board2


def winner(board):
    """
    Returns the winner of the game, if there is one.
    """
    for i in range(3):
        if board[i][0] == board[i][1] == board[i][2]:
            if board[i][0] == X:
                return X
            if board[i][0] == O:
                return O
    for j in range(3):
        if board[0][j] == board[1][j] == board[2][j]:
            if board[0][j] == X:
                return X
            if board[0][j] == O:
                return O
    if board[0][0] == board[1][1] == board[2][2] or board[0][2] == board[1][1] == board[2][0]:
        if board[1][1] == X:
            return X
        if board[1][1] == O:
            return O
    return None


def terminal(board):
    """
    Returns True if game is over, False otherwise.
    """
    if winner(board) != None:
        return True
    for space in board:
        if any(element is None for element in space):
            return False
    return True
    


def utility(board):
    """
    Returns 1 if X has won the game, -1 if O has won, 0 otherwise.
    """
    if winner(board) == X:
        return 1
    elif winner(board) == O:
        return -1
    return 0


def minimax(board):
    """
    Returns the optimal action for the current player on the board.
    """
    Max = float("-inf")
    Min = float("inf")
    if player(board) == O:
        cost , move = Min_value(board, Max , Min)       
    if player(board) == X:
        cost , move = Max_value(board , Max , Min)
    print(f'THE BEST MOVE {cost} is {move}')
    return move
    

def Max_value(board, Max , Min):
    if terminal(board):
        return utility(board), None
    v = float("-inf")
    move = None

    for action in actions(board):
        cost , act = Min_value(result(board,action) ,Max,Min )
        Max = max(Max, cost)
        if cost > v:
            v = cost 
            move = action
            if Max >= Min:
                break
    return v , move

def Min_value(board, Max , Min): 
    if terminal(board):
        return utility(board), None
    v = float("inf")
    move = None
    for action in actions(board):
        cost , act = Max_value(result(board,action), Max , Min)
        Min = min(Min, cost)
        if cost < v:
            v = cost
            move = action
            if Max >= Min:
                break
    return v , move

board = [[None, None, None], 
         [X, X, None], 
         [None, None, O]]
print(minimax(board))



    